/*
 * HR2RDAC_Program.c
 *
 *  Created on: Sep 13, 2023
 *      Author: Hesham Yasser
 */


#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_Types.h"
#include "../include/GPIO/MGPIO_Interface.h"
#include "../include/STK/MSTK_Interface.h"
#include "../include/R2RDAC/HR2RDAC_Interface.h"
#include "../include/R2RDAC/HR2RDAC_private.h"
#include "../include/R2RDAC/HR2RDAC_Configurations.h"

void HR2RDAC_voidInit (void)
{
	/* Set DAC Pins mode to Output */
	MGPIO_voidSetPinMode(DAC_PORT , GPIO_PIN2 , GPIO_OUTPUT);
	MGPIO_voidSetPinMode(DAC_PORT , GPIO_PIN5 , GPIO_OUTPUT);
	MGPIO_voidSetPinMode(DAC_PORT , GPIO_PIN6 , GPIO_OUTPUT);
	MGPIO_voidSetPinMode(DAC_PORT , GPIO_PIN7 , GPIO_OUTPUT);
	MGPIO_voidSetPinMode(DAC_PORT , GPIO_PIN8 , GPIO_OUTPUT);
	MGPIO_voidSetPinMode(DAC_PORT , GPIO_PIN9 , GPIO_OUTPUT);
	MGPIO_voidSetPinMode(DAC_PORT , GPIO_PIN10 , GPIO_OUTPUT);
	MGPIO_voidSetPinMode(DAC_PORT , GPIO_PIN12 , GPIO_OUTPUT);
	/* Set DAC Pins output mode to PUSH PULL and Speed To MID */
	MGPIO_voidSetPinOutputMode(DAC_PORT , GPIO_PIN2  , GPIO_PUSH_PULL , GPIO_MID_SPEED);
	MGPIO_voidSetPinOutputMode(DAC_PORT , GPIO_PIN5  , GPIO_PUSH_PULL , GPIO_MID_SPEED);
	MGPIO_voidSetPinOutputMode(DAC_PORT , GPIO_PIN6  , GPIO_PUSH_PULL , GPIO_MID_SPEED);
	MGPIO_voidSetPinOutputMode(DAC_PORT , GPIO_PIN7  , GPIO_PUSH_PULL , GPIO_MID_SPEED);
	MGPIO_voidSetPinOutputMode(DAC_PORT , GPIO_PIN8  , GPIO_PUSH_PULL , GPIO_MID_SPEED);
	MGPIO_voidSetPinOutputMode(DAC_PORT , GPIO_PIN9  , GPIO_PUSH_PULL , GPIO_MID_SPEED);
	MGPIO_voidSetPinOutputMode(DAC_PORT , GPIO_PIN10 , GPIO_PUSH_PULL , GPIO_MID_SPEED);
	MGPIO_voidSetPinOutputMode(DAC_PORT , GPIO_PIN12 , GPIO_PUSH_PULL , GPIO_MID_SPEED);
}


void HR2RDAC_voidSendData (u8 * p_u8Arr , u32 A_u32ArraySize)
{
	/*Initialize an iterator to iterate on the given array*/
	u32 local_u8Iterator = 0;
	for (local_u8Iterator = 0 ; local_u8Iterator < A_u32ArraySize ; local_u8Iterator++)
	{
		/*Set those bits based on the value given*/
		MGPIO_voidSetPinValue(DAC_PORT , GPIO_PIN2  , GET_BIT(p_u8Arr[local_u8Iterator] , 0));
		MGPIO_voidSetPinValue(DAC_PORT , GPIO_PIN5  , GET_BIT(p_u8Arr[local_u8Iterator] , 1));
		MGPIO_voidSetPinValue(DAC_PORT , GPIO_PIN6  , GET_BIT(p_u8Arr[local_u8Iterator] , 2));
		MGPIO_voidSetPinValue(DAC_PORT , GPIO_PIN7  , GET_BIT(p_u8Arr[local_u8Iterator] , 3));
		MGPIO_voidSetPinValue(DAC_PORT , GPIO_PIN8  , GET_BIT(p_u8Arr[local_u8Iterator] , 4));
		MGPIO_voidSetPinValue(DAC_PORT , GPIO_PIN9  , GET_BIT(p_u8Arr[local_u8Iterator] , 5));
		MGPIO_voidSetPinValue(DAC_PORT , GPIO_PIN10 , GET_BIT(p_u8Arr[local_u8Iterator] , 6));
		MGPIO_voidSetPinValue(DAC_PORT , GPIO_PIN12 , GET_BIT(p_u8Arr[local_u8Iterator] , 7));
		/*make a delay using systick to achieve 8kHz*/
		MSTK_voidDelayus(125);
	}
}

void HR2RDAC_voidSendDataAsync (u8 * p_u8Arr , u32 A_u32Index)
{
	/*Set those bits based on the value given*/
	MGPIO_voidSetPinValue(DAC_PORT , GPIO_PIN2  , GET_BIT(p_u8Arr[A_u32Index] , 0));
	MGPIO_voidSetPinValue(DAC_PORT , GPIO_PIN5  , GET_BIT(p_u8Arr[A_u32Index] , 1));
	MGPIO_voidSetPinValue(DAC_PORT , GPIO_PIN6  , GET_BIT(p_u8Arr[A_u32Index] , 2));
	MGPIO_voidSetPinValue(DAC_PORT , GPIO_PIN7  , GET_BIT(p_u8Arr[A_u32Index] , 3));
	MGPIO_voidSetPinValue(DAC_PORT , GPIO_PIN8  , GET_BIT(p_u8Arr[A_u32Index] , 4));
	MGPIO_voidSetPinValue(DAC_PORT , GPIO_PIN9  , GET_BIT(p_u8Arr[A_u32Index] , 5));
	MGPIO_voidSetPinValue(DAC_PORT , GPIO_PIN10 , GET_BIT(p_u8Arr[A_u32Index] , 6));
	MGPIO_voidSetPinValue(DAC_PORT , GPIO_PIN12 , GET_BIT(p_u8Arr[A_u32Index] , 7));

}
