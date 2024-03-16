/*
 * HTFT_private.h
 *
 *  Created on: Feb 6, 2024
 *      Author: Tasneem
 */

#ifndef HTFT_PRIVATE_H_
#define HTFT_PRIVATE_H_


#define TFT_DATA_RGB_444             	0x03
#define TFT_DATA_RGB_565             	0x05
#define TFT_DATA_RGB_666             	0x06


#define TFT_CMD_SLEEP_OUT_MODE          0x11
#define TFT_CMD_COLOR_MODE              0x3A
#define TFT_CMD_DISPLAY_MODE            0x29
#define TFT_CMD_SET_X_POSITION_MODE     0x2A
#define TFT_CMD_SET_Y_POSITION_MODE     0x2B
#define TFT_CMD_WRITE_ON_RAM_MODE       0x2C





static void HTFT_WriteCommand(uint8 Cpy_u8Command);
static void HTFT_WriteData(uint8 Cpy_u8Data);
static void HTFT_voidReset(void);



static const uint8 Char_Array[77][8]={
{15, 9, 9, 9, 9, 9, 9, 15}, // 0
{7, 2, 2, 2, 2, 2, 6, 2}, // 1
{15, 8, 8, 15, 1, 1, 1, 15}, // 2
{15, 1, 1, 15, 1, 1, 1, 15}, // 3
{1, 1, 1, 15, 9, 9, 9, 9}, // 4
{15, 1, 1, 1, 15, 8, 8, 15}, // 5
{15, 9, 9, 9, 15, 8, 8, 15}, // 6
{1, 1, 1, 1, 1, 1, 1, 15}, // 7
{15, 9, 9, 15, 9, 9, 9, 15}, // 8
{15, 1, 1, 15, 9, 9, 9, 15}, // 9
{0, 4, 0, 0, 0, 0, 4, 0}, // :
{0xc4,0x00,0x00,0x00,0x00,0x00}, // ;
{1, 2, 4, 8, 4, 2, 1, 0}, // <
{0x28,0x28,0x28,0x28,0x28,0x00}, // =
{8, 4, 2, 1, 2, 4, 8, 0}, // >
{0x08,0x04,0x54,0x08,0x00,0x00}, // ?
{0x7c,0x44,0x54,0x54,0x5c,0x00}, // @
{18, 18, 18, 30, 18, 18, 12, 0}, // A
{14, 9, 9, 15, 9, 9, 9, 14}, // B
{14, 16, 16, 16, 16, 16, 14, 0}, // C
{28, 18, 18, 18, 18, 18, 28, 0}, // D
{30, 16, 16, 28, 16, 16, 30, 0}, // E
{8, 8, 8, 8, 15, 8, 8, 15}, // F
{15, 17, 17, 23, 16, 16, 15, 0}, // G
{18, 18, 18, 30, 18, 18, 18, 0}, // H
{14, 4, 4, 4, 4, 4, 14, 0}, // I
{6, 9, 1, 1, 1, 1, 1, 15}, // J
{16, 18, 20, 24, 20, 18, 16, 0}, // K
{15, 8, 8, 8, 8, 8, 8, 0}, // L
{ 21, 21, 21, 21, 21, 21, 31,0}, // M
{18, 18, 18, 18, 18, 18, 30, 0}, // N
{14, 17, 17, 17, 17, 17, 14, 0}, // O
{ 8, 8, 8, 15, 9, 9, 15,0}, // P
{0x3c,0x24,0x64,0x24,0x3c,0x00}, // Q
{18, 18, 18, 28, 18, 18, 28, 0}, // R
{30, 2, 2, 30, 16, 16, 30, 0}, // S
{4, 4, 4, 4, 4, 4, 31, 0}, // T
{15, 9, 9, 9, 9, 9, 9, 0}, // U
{4, 10, 17, 17, 17, 17, 17, 0}, // V
{14, 21, 21, 21, 21, 21, 17, 0}, // W
{18, 18, 18, 12, 18, 18, 18, 0}, // X
{4, 4, 4, 4, 4, 10, 17, 0}, // Y
{0x44,0x64,0x54,0x4c,0x44,0x00}, // Z
{0x7c,0x44,0x00,0x00,0x00,0x00}, // [
{0x0c,0x10,0x60,0x00,0x00,0x00}, // "\"
{0x44,0x7c,0x00,0x00,0x00,0x00}, // ]
{0x00,0x01,0x00,0x01,0x00,0x00}, // ^
{0x40,0x40,0x40,0x40,0x40,0x40}, // _
{0x00,0x01,0x00,0x00,0x00,0x00}, // `
{15, 18, 18, 14, 2, 12, 0, 0}, // a
{0x7c,0x54,0x54,0x54,0x6c,0x00}, // b
{14, 16, 16, 16, 16, 14, 0, 0}, // c
{0x7c,0x44,0x44,0x44,0x38,0x00}, // d
{0x7c,0x54,0x54,0x54,0x44,0x00}, // e
{0x7c,0x14,0x14,0x14,0x04,0x00}, // f
{12, 18, 10, 2, 14, 18, 12, 0}, // g
{0x7c,0x10,0x10,0x10,0x7c,0x00}, // h
{14, 4, 4, 4, 4, 12, 0, 4}, // i
{0x60,0x40,0x40,0x44,0x7c,0x00}, // j
{18, 20, 24, 20, 18, 16, 0, 0}, // k
{14, 4, 4, 4, 4, 4, 12, 0}, // l
{0x7c,0x08,0x10,0x08,0x7c,0x00}, // m
{0x7c,0x08,0x10,0x20,0x7c,0x00}, // n
{14, 17, 17, 17, 17, 14, 0, 0}, // o
{0x7c,0x14,0x14,0x14,0x08,0x00}, // p
{0x3c,0x24,0x64,0x24,0x3c,0x00}, // q
{0x7c,0x14,0x14,0x14,0x68,0x00}, // r
{0x5c,0x54,0x54,0x54,0x74,0x00}, // s
{4, 10, 8, 8, 8, 28, 8, 0}, // t
{0x7c,0x40,0x40,0x40,0x7c,0x00}, // u
{0x0c,0x30,0x40,0x30,0x0c,0x00}, // v
{0x3c,0x40,0x30,0x40,0x3c,0x00}, // w
{0x44,0x28,0x10,0x28,0x44,0x00}, // x
{0x0c,0x10,0x60,0x10,0x0c,0x00}, // y
{0x44,0x64,0x54,0x4c,0x44,0x00}, // z
{0x0c,0x10,0x60,0x10,0x0c,0x00}, // {
{8, 0, 8, 8, 8, 8, 8, 0}, // |
};

#endif /* HTFT_PRIVATE_H_ */
