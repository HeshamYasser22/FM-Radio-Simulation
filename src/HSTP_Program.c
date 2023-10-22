/*
 * HSTP_Program.c
 *
 *  Created on: Oct 7, 2023
 *      Author: Hesham Yasser
 */
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_Types.h"
#include "../include/GPIO/MGPIO_Interface.h"
#include "../include/STK/MSTK_Interface.h"
#include "../include/STP/HSTP_Interface.h"
#include "../include/STP/HSTP_private.h"
#include "../include/STP/HSTP_Configurations.h"


extern STP_Configurations STP_Config[STP_NUMBER];

void HSTP_voidInit (void)
{
	/*Initialize STP Pins*/
	u8 local_u8Iterator = 0;
	for (local_u8Iterator = 0 ; local_u8Iterator < STP_NUMBER ; local_u8Iterator++)
	{
		MGPIO_voidSetPinMode(STP_Config[local_u8Iterator].Data_Port , STP_Config[local_u8Iterator].Data_Pin , GPIO_OUTPUT);
		MGPIO_voidSetPinOutputMode(STP_Config[local_u8Iterator].Data_Port , STP_Config[local_u8Iterator].Data_Pin , GPIO_PUSH_PULL , GPIO_MID_SPEED);
		MGPIO_voidSetPinMode(STP_Config[local_u8Iterator].ShiftClk_Port , STP_Config[local_u8Iterator].ShiftClk_Pin , GPIO_OUTPUT);
		MGPIO_voidSetPinOutputMode(STP_Config[local_u8Iterator].ShiftClk_Port , STP_Config[local_u8Iterator].ShiftClk_Pin , GPIO_PUSH_PULL , GPIO_MID_SPEED);
		MGPIO_voidSetPinMode(STP_Config[local_u8Iterator].StorageClk_Port , STP_Config[local_u8Iterator].StorageClk_Pin , GPIO_OUTPUT);
		MGPIO_voidSetPinOutputMode(STP_Config[local_u8Iterator].StorageClk_Port , STP_Config[local_u8Iterator].StorageClk_Pin , GPIO_PUSH_PULL , GPIO_MID_SPEED);
	}
}

void HSTP_voidSendData (u8 A_u8STP,u8 A_u8Data)
{
	u8 local_u8Iterator ;
	u8 local_u8PinValue ;
	if (A_u8STP < STP_NUMBER)
	{
		for (local_u8Iterator = 0 ; local_u8Iterator < 8 ; local_u8Iterator++)
		{
			MGPIO_voidSetPinValue(STP_Config[A_u8STP].Data_Port , STP_Config[A_u8STP].Data_Pin , (GET_BIT(A_u8Data , (LAST_BIT-local_u8Iterator))));
			MGPIO_voidSetPinValue(STP_Config[A_u8STP].ShiftClk_Port , STP_Config[A_u8STP].ShiftClk_Pin , GPIO_PIN_HIGH);
			MGPIO_voidSetPinValue(STP_Config[A_u8STP].ShiftClk_Port , STP_Config[A_u8STP].ShiftClk_Pin , GPIO_PIN_LOW);

		}
		MGPIO_voidSetPinValue(STP_Config[A_u8STP].StorageClk_Port , STP_Config[A_u8STP].StorageClk_Pin , GPIO_PIN_HIGH);
		MGPIO_voidSetPinValue(STP_Config[A_u8STP].StorageClk_Port , STP_Config[A_u8STP].StorageClk_Pin , GPIO_PIN_LOW);
	}
}


void HSTP_voidLedMatrix (u8 * p_u8Data)
{
	u8 local_u8RowIterator = 0;
	u8 local_u8RowVal = 0;
	for (local_u8RowIterator = 0 ; local_u8RowIterator < 8 ; local_u8RowIterator++)
	{
		local_u8RowVal = (1<<local_u8RowIterator);
		HSTP_voidSendData(0,local_u8RowVal);
		HSTP_voidSendData(1,~(p_u8Data[local_u8RowIterator]));
	}
}


void HSTP_voidLedMatrixScrollingSync (u64 * p_u64Data , u8 A_RowNumber)
{
	u8 local_u8Iterator = 0;
	u8 local_u8FlagVal = 0;
	u8 local_u8RowIterator = 0;
	u8 local_u8RowVal = 0;
	for (local_u8Iterator = 0 ; local_u8Iterator < (A_RowNumber-8) ; local_u8Iterator ++)
	{
		MSTK_voidSetPreloadValue(1600000);
		MSTK_voidEnableSTK();
		while (!local_u8FlagVal)
		{
			for (local_u8RowIterator = 0 ; local_u8RowIterator < 8 ; local_u8RowIterator++)
			{
				local_u8RowVal = (1<<local_u8RowIterator);
				HSTP_voidSendData(0,local_u8RowVal);
				HSTP_voidSendData(1,~((u8)((p_u64Data[local_u8RowIterator])>>local_u8Iterator)));
			}
			MSTK_voidGetFlagValue(&local_u8FlagVal);
		}
		local_u8FlagVal = 0;
	}

}

void HSTP_voidLedMatrixScrollingAsync (u64 * p_u64Data , u8 A_Index)
{

	u8 local_u8RowIterator ;
	u8 local_u8RowVal ;

	for (local_u8RowIterator = 0 ; local_u8RowIterator < 8 ; local_u8RowIterator++)
	{
		HSTP_voidSendData(0,(1<<local_u8RowIterator));
		HSTP_voidSendData(1,~((u8)((p_u64Data[local_u8RowIterator])>>A_Index)));
	}
}
