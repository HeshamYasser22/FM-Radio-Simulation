/*
 * HTFT_private.h
 *
 *  Created on: Sep 24, 2023
 *      Author: Hesham Yasser
 */

#ifndef HTFT_PRIVATE_H_
#define HTFT_PRIVATE_H_


/*************Color Modes******************/
#define TFT_RGB444						0x03
#define TFT_RGB565						0x05
#define TFT_RGB666						0x06

/**************Commands******************/
#define SLEEP_OUT						0x11
#define MODE_SET_COLOR					0x3A
#define DISPLAY_ON						0x29
#define SET_X							0x2A
#define SET_Y							0x2B
#define MEMORY_WRITE					0x2C
/**************Macros*******************/
#define TFT_START_PIXEL_X				0
#define TFT_START_PIXEL_Y				0
#define HIGH_BITS						8

#endif /* HTFT_PRIVATE_H_ */
