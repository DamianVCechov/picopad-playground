#include "picopad.h"

// format: 4-bit paletted pixel graphics
// image width: 32 pixels
// image height: 21 lines
// image pitch: 16 bytes
const u16 CloudImg_Pal[4] __attribute__ ((aligned(4))) = {
	0xA158, 0xC73F, 0xFFFF, 0x0000, 
};

const u8 CloudImg[336] __attribute__ ((aligned(4))) = {
	0x00, 0x00, 0x00, 0x02, 0x22, 0x22, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x20, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x20, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x02, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x20, 0x00, 0x00, 0x00, 
	0x00, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x00, 0x00, 0x00, 
	0x02, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x21, 0x10, 0x00, 
	0x00, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x11, 0x30, 
	0x00, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x21, 0x11, 0x30, 
	0x02, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x11, 0x30, 
	0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x21, 0x11, 0x30, 
	0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x21, 0x12, 0x21, 0x30, 
	0x00, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x21, 0x12, 0x11, 0x11, 0x30, 
	0x00, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x21, 0x11, 0x11, 0x13, 0x00, 
	0x02, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x21, 0x11, 0x11, 0x11, 0x23, 0x00, 
	0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x11, 0x12, 0x13, 0x33, 0x00, 
	0x11, 0x12, 0x22, 0x22, 0x22, 0x22, 0x21, 0x12, 0x21, 0x11, 0x11, 0x11, 0x11, 0x13, 0x30, 0x00, 
	0x02, 0x11, 0x11, 0x11, 0x21, 0x11, 0x11, 0x11, 0x11, 0x21, 0x11, 0x11, 0x11, 0x33, 0x30, 0x00, 
	0x00, 0x01, 0x11, 0x12, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x33, 0x33, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x13, 0x33, 0x33, 0x33, 0x30, 0x00, 0x00, 
	0x00, 0x00, 0x03, 0x33, 0x31, 0x11, 0x13, 0x33, 0x33, 0x33, 0x33, 0x33, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x03, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};
