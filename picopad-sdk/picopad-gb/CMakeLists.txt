cmake_minimum_required(VERSION 3.25)

set(PICO_TOOLCHAIN_PATH /Applications/ARM)
set(PICO_SDK_PATH ../../pico-sdk)
set(PICOPAD_BASE_PATH ../../picopad-base)

set(CMAKE_SIZE ${PICO_TOOLCHAIN_PATH}/bin/arm-none-eabi-size)

include(pico_sdk_import.cmake)
include(picopad_base_import.cmake)

# If config.cmake exists, include it
if(EXISTS "${CMAKE_SOURCE_DIR}/config.cmake")
    include("${CMAKE_SOURCE_DIR}/config.cmake")
endif()

project(picopad-gb C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

if(${ENABLE_GBC_SUPPORT})
    add_compile_definitions(PEANUT_FULL_GBC_SUPPORT=1)
endif()

pico_sdk_init()

add_executable(${PROJECT_NAME} vendor/minigb_apu/minigb_apu.c src/rom.c src/main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE vendor/minigb_apu)

target_link_libraries(${PROJECT_NAME}
        pico_stdlib
        pico_stdio
        pico_multicore
        hardware_spi
        hardware_irq
        picopad
        picopad_st7789
        picopad_libs
        picopad_machine
        pico_divider
        )

target_link_options(${PROJECT_NAME} PRIVATE LINKER:--gc-sections)

pico_set_linker_script(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/memmap_default_noboot.ld)

pico_add_bin_output(${PROJECT_NAME})

string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_UPPER)

# Create a 'build' directory
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/../build)

# Copy the .bin file to the 'build' directory after the build
add_custom_command(TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMENT "Copying bin file to build directory"
        COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_NAME}.bin ${CMAKE_BINARY_DIR}/../build/${PROJECT_NAME_UPPER}.PP2
        )

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_BINARY_DIR}/../assets/"
        "${CMAKE_BINARY_DIR}/../build/"
        COMMENT "Copying assets to build directory"
        )

# Print the size of the binary file after the build is complete
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${PROJECT_NAME}>)

