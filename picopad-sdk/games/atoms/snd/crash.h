#include "picopad.h"

// sound format: PCM mono 8-bit 22050Hz
const u8 CrashSnd[2324] = {
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 
	0x7F, 0x80, 0x80, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
	0x80, 0x81, 0x80, 0x7D, 0x7C, 0x7D, 0x80, 0x81, 0x81, 0x81, 0x82, 0x81, 0x7E, 0x7D, 0x7D, 0x7D, 
	0x7D, 0x7D, 0x80, 0x80, 0x7F, 0x80, 0x83, 0x83, 0x82, 0x7F, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 
	0x7F, 0x82, 0x83, 0x83, 0x83, 0x7F, 0x7F, 0x7E, 0x7B, 0x7A, 0x7B, 0x7F, 0x83, 0x84, 0x84, 0x83, 
	0x80, 0x7F, 0x7F, 0x7B, 0x7A, 0x7B, 0x7F, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x7F, 0x7B, 0x7B, 
	0x7B, 0x7C, 0x80, 0x81, 0x81, 0x80, 0x80, 0x7F, 0x7E, 0x7E, 0x7D, 0x7D, 0x7F, 0x80, 0x83, 0x83, 
	0x83, 0x83, 0x82, 0x7F, 0x7E, 0x7F, 0x7F, 0x80, 0x80, 0x81, 0x82, 0x82, 0x7F, 0x7F, 0x80, 0x80, 
	0x7C, 0x7B, 0x78, 0x7B, 0x80, 0x83, 0x83, 0x82, 0x81, 0x7F, 0x7B, 0x7A, 0x7C, 0x7D, 0x81, 0x84, 
	0x85, 0x84, 0x81, 0x81, 0x81, 0x81, 0x7E, 0x7A, 0x7B, 0x80, 0x81, 0x82, 0x82, 0x83, 0x84, 0x84, 
	0x80, 0x7C, 0x7C, 0x80, 0x81, 0x81, 0x80, 0x81, 0x84, 0x84, 0x82, 0x7F, 0x81, 0x82, 0x82, 0x82, 
	0x82, 0x82, 0x82, 0x7E, 0x79, 0x78, 0x79, 0x7C, 0x7C, 0x7B, 0x7B, 0x7D, 0x7E, 0x80, 0x7C, 0x7B, 
	0x7D, 0x7E, 0x81, 0x82, 0x82, 0x86, 0x8B, 0x8C, 0x8B, 0x86, 0x82, 0x81, 0x80, 0x7F, 0x7E, 0x80, 
	0x83, 0x84, 0x81, 0x80, 0x7B, 0x73, 0x6A, 0x63, 0x64, 0x69, 0x74, 0x7B, 0x7B, 0x81, 0x92, 0xAB, 
	0xB8, 0xB7, 0xAF, 0xA8, 0xA7, 0xA7, 0x9F, 0x93, 0x8C, 0x90, 0x96, 0x91, 0x85, 0x78, 0x68, 0x5B, 
	0x49, 0x38, 0x28, 0x20, 0x1C, 0x1F, 0x29, 0x38, 0x4A, 0x55, 0x5B, 0x63, 0x6F, 0x82, 0x94, 0xA4, 
	0xB1, 0xBD, 0xCE, 0xE0, 0xED, 0xEF, 0xE8, 0xDE, 0xD2, 0xC2, 0xAD, 0x94, 0x7B, 0x66, 0x56, 0x49, 
	0x3C, 0x32, 0x25, 0x1D, 0x1C, 0x1F, 0x25, 0x2B, 0x34, 0x3F, 0x56, 0x73, 0x91, 0xA8, 0xB9, 0xCB, 
	0xE1, 0xF7, 0xFF, 0xFA, 0xE7, 0xD2, 0xBE, 0xAE, 0x9D, 0x89, 0x7A, 0x68, 0x56, 0x48, 0x3F, 0x3D, 
	0x3A, 0x38, 0x38, 0x3E, 0x4B, 0x56, 0x64, 0x76, 0x92, 0xB7, 0xD0, 0xD9, 0xD0, 0xC4, 0xBF, 0xC0, 
	0xBE, 0xAB, 0x91, 0x79, 0x63, 0x4E, 0x3B, 0x26, 0x18, 0x10, 0x09, 0x03, 0x02, 0x10, 0x26, 0x3F, 
	0x5A, 0x79, 0x9D, 0xCA, 0xF2, 0xFF, 0xFF, 0xFF, 0xFD, 0xFF, 0xFF, 0xFF, 0xFE, 0xDE, 0xB8, 0x99, 
	0x7B, 0x59, 0x34, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x48, 0x6E, 0x92, 0xB2, 
	0xD7, 0xF9, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF6, 0xD6, 0xB1, 0x8C, 0x66, 0x45, 0x23, 0x04, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x37, 0x5C, 0x84, 0xA7, 0xC5, 0xDC, 0xF4, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xF5, 0xE1, 0xCB, 0xAC, 0x86, 0x5E, 0x3A, 0x1D, 0x08, 0x00, 0x00, 0x00, 0x00, 
	0x0B, 0x20, 0x36, 0x53, 0x71, 0x90, 0xAC, 0xC4, 0xD9, 0xE6, 0xEF, 0xEF, 0xED, 0xE5, 0xD7, 0xC5, 
	0xAD, 0x96, 0x7D, 0x64, 0x49, 0x36, 0x2A, 0x24, 0x21, 0x23, 0x2C, 0x38, 0x4C, 0x5F, 0x74, 0x89, 
	0x9B, 0xAB, 0xB8, 0xBE, 0xC1, 0xBF, 0xB8, 0xB1, 0xA6, 0x9A, 0x8A, 0x7C, 0x6C, 0x5D, 0x50, 0x47, 
	0x43, 0x43, 0x49, 0x52, 0x5E, 0x6D, 0x80, 0x94, 0xA6, 0xB7, 0xC3, 0xCE, 0xD1, 0xCE, 0xC6, 0xBB, 
	0xAC, 0x9A, 0x85, 0x74, 0x61, 0x4C, 0x3A, 0x2B, 0x1F, 0x19, 0x16, 0x19, 0x24, 0x34, 0x4D, 0x68, 
	0x85, 0xA2, 0xBA, 0xD0, 0xE2, 0xF0, 0xF6, 0xF5, 0xED, 0xE4, 0xD9, 0xC6, 0xAD, 0x90, 0x73, 0x56, 
	0x3D, 0x26, 0x14, 0x0A, 0x05, 0x0A, 0x12, 0x22, 0x32, 0x48, 0x5E, 0x77, 0x90, 0xA6, 0xBB, 0xD1, 
	0xE0, 0xEB, 0xEF, 0xEC, 0xE2, 0xD1, 0xBB, 0xA3, 0x8A, 0x71, 0x5F, 0x50, 0x41, 0x35, 0x2E, 0x2D, 
	0x30, 0x34, 0x3D, 0x4C, 0x5C, 0x71, 0x88, 0x9D, 0xAF, 0xBC, 0xC7, 0xCE, 0xCC, 0xC6, 0xBB, 0xAC, 
	0x9E, 0x8F, 0x81, 0x72, 0x63, 0x56, 0x48, 0x3E, 0x39, 0x3A, 0x42, 0x4C, 0x58, 0x67, 0x76, 0x87, 
	0x95, 0xA1, 0xAC, 0xB1, 0xB8, 0xBB, 0xBB, 0xB8, 0xB3, 0xAD, 0xA3, 0x93, 0x82, 0x6F, 0x61, 0x56, 
	0x4E, 0x47, 0x46, 0x49, 0x4D, 0x51, 0x54, 0x5A, 0x63, 0x70, 0x7E, 0x8B, 0x96, 0xA2, 0xAA, 0xB1, 
	0xB3, 0xAF, 0xAE, 0xAB, 0xA4, 0xA0, 0x98, 0x91, 0x86, 0x7C, 0x71, 0x67, 0x60, 0x5B, 0x56, 0x52, 
	0x52, 0x56, 0x5A, 0x5F, 0x67, 0x6E, 0x76, 0x7E, 0x87, 0x8E, 0x93, 0x9C, 0xA5, 0xA9, 0xAB, 0xA6, 
	0xA3, 0x9D, 0x95, 0x8D, 0x85, 0x7B, 0x73, 0x69, 0x64, 0x60, 0x5B, 0x5D, 0x5E, 0x63, 0x69, 0x6E, 
	0x77, 0x7E, 0x87, 0x92, 0x9A, 0x9C, 0x9F, 0x9E, 0x9A, 0x96, 0x93, 0x8B, 0x86, 0x7F, 0x78, 0x73, 
	0x6E, 0x6A, 0x65, 0x65, 0x67, 0x6B, 0x6F, 0x74, 0x79, 0x81, 0x87, 0x8D, 0x90, 0x92, 0x95, 0x97, 
	0x97, 0x97, 0x92, 0x8A, 0x86, 0x7F, 0x7A, 0x73, 0x70, 0x6E, 0x6D, 0x6A, 0x6A, 0x6B, 0x6B, 0x6E, 
	0x72, 0x73, 0x76, 0x79, 0x7C, 0x82, 0x85, 0x89, 0x8D, 0x92, 0x96, 0x9A, 0x9A, 0x9B, 0x9A, 0x98, 
	0x95, 0x93, 0x8C, 0x85, 0x7F, 0x74, 0x69, 0x63, 0x5D, 0x5A, 0x57, 0x55, 0x57, 0x5D, 0x64, 0x6C, 
	0x77, 0x84, 0x8E, 0x98, 0xA2, 0xAB, 0xB0, 0xB2, 0xB0, 0xAC, 0xA7, 0x9F, 0x92, 0x85, 0x76, 0x6E, 
	0x65, 0x5D, 0x56, 0x52, 0x52, 0x56, 0x5A, 0x61, 0x67, 0x71, 0x7A, 0x83, 0x8C, 0x90, 0x97, 0x99, 
	0x9A, 0x99, 0x96, 0x91, 0x8E, 0x89, 0x87, 0x83, 0x7F, 0x7F, 0x7E, 0x7B, 0x7D, 0x7D, 0x7E, 0x81, 
	0x82, 0x82, 0x7F, 0x7C, 0x79, 0x78, 0x75, 0x73, 0x71, 0x70, 0x6F, 0x6F, 0x72, 0x77, 0x7C, 0x80, 
	0x87, 0x8B, 0x8C, 0x91, 0x92, 0x93, 0x93, 0x92, 0x92, 0x90, 0x8C, 0x85, 0x81, 0x7A, 0x73, 0x71, 
	0x6C, 0x69, 0x6A, 0x6B, 0x6D, 0x6D, 0x70, 0x75, 0x7A, 0x7D, 0x81, 0x86, 0x8A, 0x8C, 0x8C, 0x90, 
	0x92, 0x92, 0x8F, 0x8D, 0x8D, 0x8B, 0x89, 0x87, 0x82, 0x7E, 0x7D, 0x79, 0x76, 0x71, 0x70, 0x6D, 
	0x6E, 0x6E, 0x6D, 0x6D, 0x70, 0x72, 0x76, 0x7A, 0x80, 0x84, 0x87, 0x8E, 0x90, 0x92, 0x96, 0x95, 
	0x94, 0x94, 0x93, 0x8E, 0x89, 0x82, 0x7E, 0x79, 0x75, 0x71, 0x6F, 0x6B, 0x6A, 0x6B, 0x6D, 0x6E, 
	0x71, 0x78, 0x7D, 0x83, 0x87, 0x89, 0x8B, 0x8F, 0x8F, 0x8D, 0x8C, 0x8A, 0x8A, 0x86, 0x84, 0x80, 
	0x7F, 0x7C, 0x7B, 0x7A, 0x79, 0x77, 0x78, 0x76, 0x79, 0x79, 0x7B, 0x7B, 0x7D, 0x80, 0x81, 0x80, 
	0x82, 0x84, 0x84, 0x86, 0x85, 0x84, 0x83, 0x82, 0x81, 0x81, 0x80, 0x80, 0x7F, 0x7F, 0x7F, 0x7F, 
	0x7F, 0x7F, 0x7F, 0x80, 0x80, 0x80, 0x7D, 0x7C, 0x7D, 0x81, 0x82, 0x83, 0x83, 0x81, 0x82, 0x84, 
	0x84, 0x86, 0x86, 0x82, 0x81, 0x7D, 0x7B, 0x77, 0x78, 0x76, 0x76, 0x75, 0x77, 0x79, 0x79, 0x7C, 
	0x7D, 0x7F, 0x82, 0x82, 0x85, 0x85, 0x82, 0x82, 0x80, 0x82, 0x84, 0x84, 0x83, 0x83, 0x84, 0x85, 
	0x87, 0x87, 0x89, 0x86, 0x86, 0x84, 0x86, 0x84, 0x7F, 0x7D, 0x7B, 0x79, 0x76, 0x75, 0x74, 0x71, 
	0x70, 0x6F, 0x73, 0x74, 0x76, 0x7B, 0x7B, 0x7B, 0x7F, 0x83, 0x87, 0x88, 0x8A, 0x8C, 0x8D, 0x8E, 
	0x8E, 0x8E, 0x8D, 0x8B, 0x88, 0x85, 0x83, 0x81, 0x7C, 0x7A, 0x77, 0x74, 0x73, 0x72, 0x73, 0x73, 
	0x72, 0x77, 0x79, 0x7D, 0x81, 0x84, 0x84, 0x87, 0x88, 0x89, 0x8B, 0x8A, 0x8B, 0x8C, 0x8B, 0x8A, 
	0x87, 0x83, 0x81, 0x7E, 0x7C, 0x78, 0x75, 0x74, 0x73, 0x70, 0x70, 0x73, 0x76, 0x77, 0x7B, 0x7C, 
	0x7F, 0x82, 0x82, 0x85, 0x85, 0x86, 0x8A, 0x89, 0x88, 0x88, 0x88, 0x8A, 0x89, 0x87, 0x82, 0x7E, 
	0x7E, 0x7D, 0x79, 0x77, 0x76, 0x76, 0x74, 0x77, 0x77, 0x78, 0x7A, 0x7B, 0x7F, 0x80, 0x83, 0x84, 
	0x85, 0x87, 0x89, 0x88, 0x88, 0x8A, 0x8B, 0x87, 0x85, 0x81, 0x80, 0x7D, 0x7C, 0x77, 0x75, 0x73, 
	0x74, 0x74, 0x77, 0x79, 0x7A, 0x7B, 0x7B, 0x80, 0x84, 0x85, 0x86, 0x87, 0x89, 0x89, 0x89, 0x89, 
	0x87, 0x85, 0x84, 0x82, 0x7F, 0x7E, 0x7E, 0x7E, 0x7E, 0x79, 0x77, 0x76, 0x77, 0x75, 0x78, 0x78, 
	0x7A, 0x79, 0x7E, 0x80, 0x82, 0x83, 0x85, 0x87, 0x86, 0x86, 0x86, 0x86, 0x84, 0x81, 0x7F, 0x7D, 
	0x7A, 0x77, 0x73, 0x73, 0x75, 0x74, 0x77, 0x78, 0x7B, 0x7F, 0x82, 0x85, 0x89, 0x89, 0x8B, 0x8D, 
	0x8D, 0x8E, 0x8C, 0x8B, 0x88, 0x85, 0x82, 0x7D, 0x7A, 0x77, 0x75, 0x74, 0x72, 0x70, 0x70, 0x73, 
	0x75, 0x76, 0x79, 0x7D, 0x81, 0x85, 0x88, 0x8A, 0x8C, 0x8F, 0x8F, 0x8D, 0x8B, 0x8B, 0x87, 0x81, 
	0x7E, 0x7B, 0x78, 0x74, 0x72, 0x70, 0x6E, 0x6D, 0x6D, 0x6F, 0x74, 0x75, 0x7B, 0x7E, 0x81, 0x87, 
	0x8B, 0x90, 0x93, 0x96, 0x95, 0x94, 0x92, 0x91, 0x8F, 0x8A, 0x89, 0x82, 0x7F, 0x7C, 0x79, 0x75, 
	0x74, 0x72, 0x6F, 0x6E, 0x70, 0x71, 0x73, 0x76, 0x7A, 0x7A, 0x7D, 0x81, 0x85, 0x88, 0x89, 0x89, 
	0x8B, 0x89, 0x89, 0x89, 0x86, 0x83, 0x81, 0x80, 0x7E, 0x7C, 0x7A, 0x77, 0x78, 0x78, 0x77, 0x76, 
	0x78, 0x7A, 0x7B, 0x7D, 0x81, 0x83, 0x84, 0x85, 0x84, 0x86, 0x86, 0x86, 0x87, 0x89, 0x87, 0x86, 
	0x85, 0x81, 0x81, 0x81, 0x7D, 0x7D, 0x7C, 0x7C, 0x7A, 0x78, 0x79, 0x76, 0x75, 0x77, 0x76, 0x77, 
	0x78, 0x7B, 0x7C, 0x7F, 0x7F, 0x81, 0x82, 0x84, 0x85, 0x86, 0x87, 0x89, 0x89, 0x89, 0x8A, 0x8C, 
	0x8B, 0x87, 0x87, 0x85, 0x83, 0x7D, 0x7A, 0x78, 0x75, 0x74, 0x70, 0x71, 0x71, 0x70, 0x71, 0x74, 
	0x77, 0x79, 0x7E, 0x83, 0x85, 0x8A, 0x8D, 0x91, 0x93, 0x93, 0x94, 0x90, 0x8C, 0x8A, 0x85, 0x81, 
	0x7C, 0x78, 0x73, 0x70, 0x6D, 0x6C, 0x6C, 0x6B, 0x6C, 0x70, 0x75, 0x76, 0x7A, 0x81, 0x84, 0x88, 
	0x8C, 0x8F, 0x92, 0x93, 0x95, 0x93, 0x91, 0x90, 0x8A, 0x87, 0x82, 0x7D, 0x7C, 0x77, 0x74, 0x72, 
	0x72, 0x71, 0x73, 0x73, 0x73, 0x75, 0x78, 0x7D, 0x7E, 0x80, 0x84, 0x86, 0x88, 0x8A, 0x89, 0x89, 
	0x8A, 0x8B, 0x8A, 0x85, 0x83, 0x80, 0x7F, 0x7B, 0x77, 0x75, 0x73, 0x70, 0x6F, 0x6D, 0x6E, 0x70, 
	0x72, 0x73, 0x7A, 0x7E, 0x81, 0x88, 0x8C, 0x91, 0x94, 0x94, 0x96, 0x97, 0x95, 0x92, 0x90, 0x8C, 
	0x85, 0x81, 0x7C, 0x78, 0x72, 0x70, 0x6D, 0x6A, 0x6B, 0x6B, 0x6C, 0x70, 0x73, 0x78, 0x7D, 0x81, 
	0x87, 0x8C, 0x8F, 0x92, 0x92, 0x94, 0x92, 0x90, 0x8D, 0x8A, 0x85, 0x7F, 0x7A, 0x79, 0x77, 0x74, 
	0x71, 0x72, 0x70, 0x70, 0x73, 0x74, 0x74, 0x77, 0x79, 0x7B, 0x80, 0x81, 0x83, 0x88, 0x8A, 0x8A, 
	0x8E, 0x90, 0x8F, 0x8F, 0x8D, 0x8C, 0x88, 0x85, 0x82, 0x7C, 0x7A, 0x7C, 0x7A, 0x77, 0x77, 0x76, 
	0x75, 0x76, 0x77, 0x78, 0x7A, 0x7A, 0x7C, 0x7E, 0x80, 0x82, 0x80, 0x82, 0x85, 0x84, 0x82, 0x81, 
	0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x7F, 0x7F, 0x7E, 0x7E, 0x7D, 0x7D, 
	0x7F, 0x7F, 0x7E, 0x7D, 0x7D, 0x80, 0x80, 0x80, 0x7F, 0x7E, 0x7D, 0x7D, 0x7F, 0x7F, 0x82, 0x83, 
	0x86, 0x88, 0x89, 0x8C, 0x8A, 0x87, 0x87, 0x85, 0x82, 0x7D, 0x7A, 0x77, 0x73, 0x72, 0x6F, 0x6B, 
	0x6C, 0x6D, 0x6F, 0x70, 0x76, 0x79, 0x7E, 0x83, 0x85, 0x8A, 0x8E, 0x93, 0x96, 0x97, 0x96, 0x94, 
	0x93, 0x91, 0x8C, 0x88, 0x81, 0x7E, 0x7B, 0x75, 0x74, 0x70, 0x71, 0x71, 0x6F, 0x70, 0x73, 0x75, 
	0x76, 0x79, 0x7D, 0x80, 0x83, 0x86, 0x87, 0x8A, 0x8C, 0x8A, 0x8C, 0x89, 0x88, 0x86, 0x83, 0x82, 
	0x80, 0x7F, 0x7E, 0x7D, 0x7B, 0x79, 0x77, 0x79, 0x79, 0x76, 0x78, 0x78, 0x7A, 0x7C, 0x7E, 0x80, 
	0x81, 0x82, 0x84, 0x86, 0x89, 0x89, 0x89, 0x89, 0x87, 0x85, 0x83, 0x83, 0x82, 0x7E, 0x7E, 0x7D, 
	0x78, 0x77, 0x78, 0x76, 0x76, 0x75, 0x78, 0x7A, 0x7A, 0x7B, 0x7F, 0x80, 0x83, 0x84, 0x85, 0x86, 
	0x88, 0x87, 0x86, 0x86, 0x87, 0x84, 0x81, 0x7F, 0x7D, 0x7B, 0x7C, 0x7A, 0x7B, 0x7C, 0x7C, 0x7C, 
	0x7C, 0x7C, 0x7F, 0x7F, 0x82, 0x82, 0x81, 0x82, 0x86, 0x87, 0x84, 0x85, 0x83, 0x85, 0x83, 0x81, 
	0x7F, 0x7D, 0x7B, 0x79, 0x79, 0x79, 0x76, 0x77, 0x76, 0x77, 0x78, 0x79, 0x7B, 0x7C, 0x7F, 0x82, 
	0x86, 0x87, 0x88, 0x8A, 0x8E, 0x8E, 0x8D, 0x8C, 0x8C, 0x8A, 0x85, 0x83, 0x7F, 0x7E, 0x79, 0x73, 
	0x73, 0x6F, 0x6D, 0x6E, 0x71, 0x72, 0x72, 0x74, 0x78, 0x79, 0x7D, 0x81, 0x85, 0x89, 0x8B, 0x8E, 
	0x91, 0x8F, 0x8E, 0x8E, 0x8D, 0x8C, 0x89, 0x86, 0x81, 0x7F, 0x7E, 0x7C, 0x77, 0x77, 0x75, 0x74, 
	0x73, 0x74, 0x75, 0x77, 0x76, 0x77, 0x7B, 0x7B, 0x7F, 0x82, 0x85, 0x85, 0x86, 0x89, 0x87, 0x89, 
	0x88, 0x88, 0x88, 0x86, 0x84, 0x83, 0x81, 0x7D, 0x7C, 0x7B, 0x7A, 0x79, 0x76, 0x77, 0x78, 0x78, 
	0x7B, 0x7B, 0x7D, 0x7F, 0x81, 0x84, 0x86, 0x85, 0x84, 0x83, 0x82, 0x83, 0x83, 0x83, 0x81, 0x81, 
	0x7F, 0x7F, 0x7D, 0x7D, 0x7D, 0x7A, 0x79, 0x7A, 0x7D, 0x7C, 0x7B, 0x7E, 0x80, 0x80, 0x82, 0x82, 
	0x84, 0x84, 0x84, 0x84, 0x84, 0x85, 0x83, 0x83, 0x81, 0x7F, 0x81, 0x7F, 0x7C, 0x79, 0x7A, 0x7A, 
	0x76, 0x78, 0x77, 0x79, 0x7A, 0x7B, 0x7C, 0x7F, 0x81, 0x85, 0x87, 0x89, 0x88, 0x8B, 0x8D, 0x8B, 
	0x8A, 0x89, 0x86, 0x84, 0x81, 0x7F, 0x7D, 0x7B, 0x77, 0x73, 0x71, 0x6F, 0x6F, 0x71, 0x72, 0x72, 
	0x74, 0x79, 0x7B, 0x80, 0x84, 0x86, 0x88, 0x8B, 0x8F, 0x91, 0x90, 0x90, 0x8F, 0x8F, 0x8B, 0x86, 
	0x84, 0x81, 0x80, 0x7C, 0x77, 0x75, 0x72, 0x6F, 0x6D, 0x6D, 0x6D, 0x6F, 0x73, 0x75, 0x78, 0x7B, 
	0x7C, 0x80, 0x84, 0x89, 0x8A, 0x8D, 0x91, 0x93, 0x92, 0x8F, 0x8D, 0x8D, 0x8A, 0x88, 0x83, 0x7E, 
	0x7C, 0x78, 0x76, 0x73, 0x70, 0x6E, 0x70, 0x70, 0x73, 0x74, 0x75, 0x77, 0x7A, 0x7C, 0x81, 0x84, 
	0x86, 0x89, 0x8C, 0x8D, 0x8E, 0x8E, 0x8D, 0x8B, 0x8A, 0x8A, 0x88, 0x84, 0x7F, 0x7D, 0x7B, 0x78, 
	0x75, 0x70, 0x6F, 0x70, 0x71, 0x74, 0x75, 0x76, 0x79, 0x7C, 0x7E, 0x80, 0x82, 0x85, 0x89, 0x8D, 
	0x8E, 0x8D, 0x8C, 0x8D, 0x8B, 0x8A, 0x86, 0x83, 0x80, 0x7E, 0x7B, 0x78, 0x75, 0x74, 0x73, 0x74, 
	0x74, 0x74, 0x75, 0x77, 0x7B, 0x7C, 0x80, 0x84, 0x84, 0x85, 0x88, 0x87, 0x89, 0x88, 0x88, 0x89, 
	0x86, 0x84, 0x82, 0x80, 0x7F, 0x7D, 0x7B, 0x79, 0x7A, 0x78, 0x77, 0x78, 0x7A, 0x79, 0x7B, 0x7D, 
	0x7E, 0x80, 0x81, 0x83, 0x85, 0x87, 0x87, 0x8A, 0x87, 0x88, 0x86, 0x84, 0x83, 0x82, 0x81, 0x7D, 
	0x7C, 0x7B, 0x7A, 0x78, 0x78, 0x75, 0x77, 0x77, 0x78, 0x7A, 0x7B, 0x7F, 0x80, 0x81, 0x84, 0x85, 
	0x83, 0x85, 0x88, 0x88, 0x87, 0x85, 0x86, 0x84, 0x82, 0x81, 0x80, 0x7F, 0x7E, 0x7C, 0x7B, 0x7D, 
	0x7C, 0x7D, 0x7B, 0x7B, 0x7B, 0x7B, 0x7B, 0x7A, 0x7C, 0x7C, 0x7D, 0x80, 0x81, 0x7F, 0x80, 0x82, 
	0x84, 0x83, 0x85, 0x85, 0x85, 0x85, 0x83, 0x83, 0x81, 0x7F, 0x7D, 0x7F, 0x7D, 0x7B, 0x7C, 0x7A, 
	0x7A, 0x7A, 0x7A, 0x7D, 0x7D, 0x7E, 0x7D, 0x7E, 0x80, 0x81, 0x80, 0x82, 0x81, 0x84, 0x83, 0x83, 
	0x82, 0x7F, 0x7F, 0x7F, 0x80, 0x80, 0x80, 0x7E, 0x7E, 0x7E, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 
	0x7F, 0x7E, 0x7F, 0x82, 0x83, 0x82, 0x80, 0x80, 0x81, 0x81, 0x80, 0x80, 0x7E, 0x7F, 0x80, 0x7D, 
	0x7D, 0x7D, 0x7A, 0x7C, 0x7C, 0x7B, 0x7D, 0x7D, 0x7F, 0x80, 0x80, 0x82, 0x81, 0x81, 0x84, 0x84, 
	0x82, 0x82, 0x80, 0x81, 0x80, 0x81, 0x80, 0x7F, 0x7D, 0x7E, 0x7C, 0x7C, 0x7B, 0x7A, 0x7A, 0x7C, 
	0x7C, 0x7D, 0x7C, 0x7D, 0x7F, 0x80, 0x7F, 0x80, 0x81, 0x80, 0x81, 0x81, 0x82, 0x82, 0x82, 0x82, 
	0x83, 0x83, 0x82, 0x81, 0x80, 0x81, 0x7F, 0x7E, 0x7D, 0x7C, 0x7E, 0x7D, 0x7B, 0x7B, 0x7B, 0x7B, 
	0x7C, 0x7B, 0x7C, 0x7E, 0x7F, 0x7F, 0x80, 0x82, 0x83, 0x82, 0x82, 0x83, 0x83, 0x83, 0x81, 0x82, 
	0x81, 0x80, 0x80, 0x80, 0x7F, 0x7D, 0x7D, 0x7E, 0x7E, 0x7E, 0x7D, 0x7D, 0x7D, 0x7D, 0x7E, 0x7E, 
	0x7F, 0x7F, 0x7F, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x81, 0x81, 0x80, 0x80, 0x80, 
	0x80, 0x80, 0x80, 0x80, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 
	0x7F, 0x80, 0x7F, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
	0x80, 0x7F, 0x7F, 0x7F, 0x7F, 0x80, 0x7F, 0x7F, 0x80, 0x80, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 
	0x80, 0x80, 0x80, 0x7F, 0x7F, 0x7F, 0x80, 0x80, 0x80, 0x7F, 0x7F, 0x7F, 0x80, 0x80, 0x80, 0x80, 
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x7F, 0x7F, 0x80, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 
	0x7F, 0x7F, 0x80, 0x80, 
};
