// Enable LCD
#define ENABLE_LCD    1
// Disable sound
#define ENABLE_SOUND    0
// High accuracy mode for Peanut GB
#define PEANUT_GB_HIGH_LCD_ACCURACY 1

// Pico libraries
#include <string.h>
#include <hardware/clocks.h>
#include <hardware/spi.h>
#include <hardware/vreg.h>
#include <pico/stdio.h>
#include <pico/stdlib.h>
#include <pico/multicore.h>

// Peanut GB library
#include "peanut_gb.h"

// LCD display libraries
#include "st7789.h"
#include "lib_drawtft.h"

// Picopad library
#include "picopad_init.h"
#include "picopad_key.h"
#include "sdk_watchdog.h"

// Button GPIO mapping
#define GPIO_BUTTON_UP        4
#define GPIO_BUTTON_DOWN      5
#define GPIO_BUTTON_LEFT      3
#define GPIO_BUTTON_RIGHT     2
#define GPIO_BUTTON_A         7
#define GPIO_BUTTON_B         6
#define GPIO_BUTTON_SELECT    8
#define GPIO_BUTTON_START     9

// ROM data
extern const unsigned char gameRom[];
// ROM Bank 0 data
static unsigned char romBank0[32768];
// Game RAM
static uint8_t gameRam[32768];
// LCD Line status
static int lcdLineStatus = 0;

// Previous joypad state
static struct {
    unsigned a: 1;
    unsigned b: 1;
    unsigned select: 1;
    unsigned start: 1;
    unsigned right: 1;
    unsigned left: 1;
    unsigned up: 1;
    unsigned down: 1;
} prevGamepadState;

// Multicore command structure
union coreCommand {
    struct {
#define NO_OPERATION_CMD        0
#define DRAW_LCD_LINE_CMD       1
#define IDLE_SET_CMD            2
        uint8_t cmd;
        uint8_t unused1;
        uint8_t unused2;
        uint8_t data;
    };
    uint32_t full;
};

// Pixel data buffer
static uint8_t pixelBuffer[LCD_WIDTH];

// GameBoy context
static struct gb_s gbContext;

// GameBoy ROM read function
uint8_t gbRomRead(struct gb_s *gb, const uint_fast32_t addr) {
    (void) gb;
    if (addr < sizeof(romBank0))
        return romBank0[addr];

    return gameRom[addr];
}

// GameBoy cartridge RAM read function
uint8_t gbCartRamRead(struct gb_s *gb, const uint_fast32_t addr) {
    (void) gb;
    return gameRam[addr];
}

// GameBoy cartridge RAM write function
void gbCartRamWrite(struct gb_s *gb, const uint_fast32_t addr, const uint8_t val) {
    gameRam[addr] = val;
}

// Error handler function
void gbErrorHandler(struct gb_s *gb, const enum gb_error_e gb_err, const uint16_t addr) {
    ResetToBootLoader();
}

// Palette definition
static const uint16_t greyscalePalette[3][4] = {
        {0xFFFF, 0xAD55, 0x52AA, 0x0000},
        {0xFFFF, 0xAD55, 0x52AA, 0x0000},
        {0xFFFF, 0xAD55, 0x52AA, 0x0000}
};

inline void core1DrawLine(const uint_fast8_t line) {
    static uint16_t fb[WIDTH];
    for (uint8_t x = 0; x < LCD_WIDTH; x++) {
        uint16_t color = greyscalePalette[(pixelBuffer[x] & LCD_PALETTE_ALL) >> 4][pixelBuffer[x] & 3];
        fb[2 * x] = color;
        fb[(2 * x + 1)] = color;
    }

    bool duplicate = line % 3 != 0;
    uint_fast8_t duplicateLines = line / 3;
    uint_fast8_t writeLine = (2 * line) - duplicateLines;
    writeLine += !duplicate;

    uint16_t *destination = &FrameBuf[writeLine * WIDTH];
    memcpy(destination, fb, WIDTH * 2);

    if (duplicate && line < 143) {
        destination = destination + WIDTH;
        memcpy(destination, fb, WIDTH * 2);
    }

    DispDirtyRect(0, writeLine, WIDTH, duplicate ? 2 : 1);
    DispUpdate();

    __atomic_store_n(&lcdLineStatus, 0, __ATOMIC_SEQ_CST);
}

// Main function for Core 1
void core1MainFunction() {
    union coreCommand cmd{};

    DrawClear(COL_BLACK);
    DispUpdate();

    while (true) {
        cmd.full = multicore_fifo_pop_blocking();
        switch (cmd.cmd) {
            case DRAW_LCD_LINE_CMD:
                core1DrawLine(cmd.data);
                break;
            case IDLE_SET_CMD:
            case NO_OPERATION_CMD:
            default:
                break;
        }
    }
}

void lcdDrawLine(struct gb_s *gb, const uint8_t pixels[LCD_WIDTH], const uint_fast8_t line) {
    coreCommand cmd{};

    /* Wait until previous line is sent. */
    while (__atomic_load_n(&lcdLineStatus, __ATOMIC_SEQ_CST))
        tight_loop_contents();

    memcpy(pixelBuffer, pixels, LCD_WIDTH);

    /* Populate command. */
    cmd.cmd = DRAW_LCD_LINE_CMD;
    cmd.data = line;

    __atomic_store_n(&lcdLineStatus, 1, __ATOMIC_SEQ_CST);
    multicore_fifo_push_blocking(cmd.full);
}

// Main function
int main() {
    // Variable for storing return status of initialization
    enum gb_init_error_e initStatus;

    // Overclocking the system
    {
        // Frequency of the voltage controlled oscillator (VCO) - 266MHz
        const unsigned vcoFrequency = 1596 * 1000 * 1000;
        const unsigned div1 = 6, div2 = 1;

        // Setting voltage and system clock
        vreg_set_voltage(VREG_VOLTAGE_1_15);
        sleep_ms(2);
        set_sys_clock_pll(vcoFrequency, div1, div2);
        sleep_ms(2);
    }

    // Initialise USB serial connection for debugging
    stdio_init_all();

    // Configure clocks and initialize SPI
    clock_configure(clk_peri, 0, CLOCKS_CLK_PERI_CTRL_AUXSRC_VALUE_CLKSRC_PLL_SYS, 133000 * 1000, 133000 * 1000);
    // Maximal Pico SPI frequency - 62.5MHz
    spi_init(spi0, 62500000);
    spi_set_format(spi0, 8, SPI_CPOL_1, SPI_CPHA_1, SPI_MSB_FIRST);

    // Initialize the Picopad device
    DeviceInit(true, false);

    // Main game loop
    while (true) {
        DrawClear(COL_BLACK);
        DispUpdate();

        // Initialize GB context
        memcpy(romBank0, gameRom, sizeof(romBank0));
        initStatus = gb_init(&gbContext, &gbRomRead, &gbCartRamRead, &gbCartRamWrite, &gbErrorHandler, nullptr);
        if (initStatus != GB_INIT_NO_ERROR) {
            ResetToBootLoader();
        }
        gb_init_lcd(&gbContext, &lcdDrawLine);

        // Turn ON Peanut GB frame skip
        gbContext.direct.frame_skip = 1;
        gbContext.display.frame_skip_count = 1;

        // Start Core1, which processes requests to the LCD
        multicore_launch_core1(core1MainFunction);

        // Frame count variable
        uint_fast32_t frameCount = 0;
        do {
            gbContext.gb_frame = 0;
            do {
                __gb_step_cpu(&gbContext);
                tight_loop_contents();
            } while (gbContext.gb_frame == 0);

            frameCount++;

            // Update gamepad state
            prevGamepadState.up = gbContext.direct.joypad_bits.up;
            prevGamepadState.down = gbContext.direct.joypad_bits.down;
            prevGamepadState.left = gbContext.direct.joypad_bits.left;
            prevGamepadState.right = gbContext.direct.joypad_bits.right;
            prevGamepadState.a = gbContext.direct.joypad_bits.a;
            prevGamepadState.b = gbContext.direct.joypad_bits.b;
            prevGamepadState.select = gbContext.direct.joypad_bits.select;
            prevGamepadState.start = gbContext.direct.joypad_bits.start;

            // Map Picopad buttons to Peanut GB emulator
            gbContext.direct.joypad_bits.up = gpio_get(GPIO_BUTTON_UP);
            gbContext.direct.joypad_bits.down = gpio_get(GPIO_BUTTON_DOWN);
            gbContext.direct.joypad_bits.left = gpio_get(GPIO_BUTTON_LEFT);
            gbContext.direct.joypad_bits.right = gpio_get(GPIO_BUTTON_RIGHT);
            gbContext.direct.joypad_bits.a = gpio_get(GPIO_BUTTON_A);
            gbContext.direct.joypad_bits.b = gpio_get(GPIO_BUTTON_B);
            gbContext.direct.joypad_bits.select = gpio_get(GPIO_BUTTON_SELECT);
            gbContext.direct.joypad_bits.start = gpio_get(GPIO_BUTTON_START);
        } while (KeyGet() != KEY_Y);

        // Reset core1 and reset to bootloader
        multicore_reset_core1();
        ResetToBootLoader();
    }
}
