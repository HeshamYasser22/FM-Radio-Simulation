/*
 * HTFT_Program.c
 *
 *  Created on: Sep 24, 2023
 *      Author: Hesham Yasser
 */


#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_Types.h"
#include "../include/RCC/MRCC_Interface.h"
#include "../include/GPIO/MGPIO_Interface.h"
#include "../include/SPI/MSPI_Interface.h"
#include "../include/STK/MSTK_Interface.h"
#include "../include/TFT/HTFT_Interface.h"
#include "../include/TFT/HTFT_private.h"
#include "../include/TFT/HTFT_Configurations.h"


void HTFT_voidReset (void)
{
	MGPIO_voidSetResetPin(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_SET);
	MSTK_voidDelayus(100);
	MGPIO_voidSetResetPin(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_RESET);
	MSTK_voidDelayus(1);
	MGPIO_voidSetResetPin(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_SET);
	MSTK_voidDelayus(100);
	MGPIO_voidSetResetPin(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_RESET);
	MSTK_voidDelayus(100);
	MGPIO_voidSetResetPin(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_SET);
	MSTK_voidDelayms(120);
}

void HTFT_voidInit (void)
{
	MGPIO_voidSetPinMode(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_PUSH_PULL , GPIO_MID_SPEED);
	MGPIO_voidSetResetPin(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_RESET);
	MGPIO_voidSetPinMode(TFT_CS_PORT , TFT_CS_PIN , GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(TFT_CS_PORT , TFT_CS_PIN , GPIO_PUSH_PULL , GPIO_MID_SPEED);
	MGPIO_voidSetResetPin(TFT_CS_PORT , TFT_CS_PIN , GPIO_RESET);
	MGPIO_voidSetPinMode(TFT_CONTROL_PORT , TFT_CONTROL_PIN , GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(TFT_CONTROL_PORT , TFT_CONTROL_PIN , GPIO_PUSH_PULL , GPIO_MID_SPEED);
	MGPIO_voidSetPinMode(GPIO_PORTA , GPIO_PIN5 , GPIO_ALT_FUNC);
	MGPIO_voidSetPinAltrenativeFunction(GPIO_PORTA , GPIO_PIN5 , GPIO_AF5);
	MGPIO_voidSetPinMode(GPIO_PORTA , GPIO_PIN6 , GPIO_ALT_FUNC);
	MGPIO_voidSetPinAltrenativeFunction(GPIO_PORTA , GPIO_PIN6 , GPIO_AF5);
	MGPIO_voidSetPinMode(GPIO_PORTA , GPIO_PIN7 , GPIO_ALT_FUNC);
	MGPIO_voidSetPinAltrenativeFunction(GPIO_PORTA , GPIO_PIN7 , GPIO_AF5);
	MSTK_voidInit();
	MSTK_voidDisableInterrupt();
	MSPI_voidInit();
	HTFT_voidReset();
	HTFT_voidSendCommand(SLEEP_OUT);
	MSTK_voidDelayms(150);
	HTFT_voidSendCommand(MODE_SET_COLOR);
	HTFT_voidSendData(TFT_COLOR_MODE);
	HTFT_voidSendCommand(DISPLAY_ON);
	MSTK_voidDelayms(1);
}

void HTFT_voidSendPicture (const u16 * p_Picture)
{
	/*******************Send TFT Size******************/

	HTFT_voidSendCommand(SET_X);
	HTFT_voidSendData(TFT_START_PIXEL_Y);
	HTFT_voidSendData(TFT_START_PIXEL_X);
	HTFT_voidSendData(TFT_START_PIXEL_Y);
	HTFT_voidSendData(TFT_PIXELS_X-1);
	HTFT_voidSendCommand(SET_Y);
	HTFT_voidSendData(TFT_START_PIXEL_X);
	HTFT_voidSendData(TFT_START_PIXEL_Y);
	HTFT_voidSendData(TFT_START_PIXEL_X);
	HTFT_voidSendData(TFT_PIXELS_Y-1);

	/****************Send Pixels***********************/
	u16 local_u16Iterator = 0;
	HTFT_voidSendCommand(MEMORY_WRITE);
	for (local_u16Iterator = 0 ; local_u16Iterator < (TFT_PIXELS_X*TFT_PIXELS_Y) ; local_u16Iterator++)
	{
		HTFT_voidSendData((u8)(p_Picture[local_u16Iterator]>>HIGH_BITS));
		HTFT_voidSendData((u8)p_Picture[local_u16Iterator]);
	}
}

void HTFT_voidSendCommand (u8 A_u8Command)
{
	MGPIO_voidSetResetPin(TFT_CONTROL_PORT , TFT_CONTROL_PIN , GPIO_RESET);
	MSPI_voidSendReceiveData(A_u8Command);
}
void HTFT_voidSendData (u8 A_u8Data)
{
	MGPIO_voidSetResetPin(TFT_CONTROL_PORT , TFT_CONTROL_PIN , GPIO_SET);
	MSPI_voidSendReceiveData(A_u8Data);
}
