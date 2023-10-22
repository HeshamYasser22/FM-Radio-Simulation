#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_Types.h"
#include "../include/RCC/MRCC_Interface.h"
#include "../include/GPIO/MGPIO_Interface.h"
#include "../include/NVIC/MNVIC_Interface.h"
#include "../include/STK/MSTK_Interface.h"
#include "../include/SPI/MSPI_Interface.h"
#include "../include/EXTI/MEXTI_Interface.h"
#include "../include/TFT/HTFT_Interface.h"
#include "../include/R2RDAC/HR2RDAC_Interface.h"
#include "../include/STP/HSTP_Interface.h"
#include "../include/TFT/TFT_Diad.h"
#include "../include/TFT/TFT_Monir.h"
#include "../include/R2RDAC/DAC_Diab.h"
#include "../include/R2RDAC/DAC_Monir.h"
/****************Interrupt Handlers***************/
void EXTI0_Handler (void);
void EXTI1_Handler (void);
void EXTI2_Handler (void);
void STK_Handler (void);
/****************Led Matrix Arrays****************/
u64 global_u64Amr[8] = {496592811086, 636800538321, 636800537937, 1064149775455, 636800537681, 636800537681, 499814044753, 0};
u64 global_u64Mohamed[8] = {514611286929, 620006544475, 619905881173, 634874885201, 619838772305, 619838772305, 514612073361, 0};
u64 global_u64Monir[8] = {259855249, 286340187, 286348373, 252810321, 286331985, 286331985, 293409681, 0};
u64 global_u64Exit[8] = {17751376417, 35502752834, 71005505668, 142011011336, 71005505668, 35502752834, 17751376417, 0};
/***************Some Flags & Pointers*************/
u8 global_u8CurrentSinger = -1;
u8 global_u8LedMatrixIndex = 0;
u32 global_u32DacIndex = 0;
u64 * Ptr_Name = &global_u64Amr;
u16 * Ptr_Image = &TFT_Monir;
u8  * Ptr_Song = &DAC_Diab;
u32 global_u32SongSize = 0;
u16 global_u16TimeCount = 0;
u8 global_u8FlagVal = 0;

void main (void)
{
	/*****************RCC Initialization*******************/
	MRCC_voidInit();
	MRCC_voidEnablePeripheral(RCC_AHB1 , RCC_AHB1_GPIOA);
	MRCC_voidEnablePeripheral(RCC_AHB1 , RCC_AHB1_GPIOB);
	MRCC_voidEnablePeripheral(RCC_AHB1 , RCC_AHB1_GPIOC);
	MRCC_voidEnablePeripheral(RCC_APB2 , RCC_APB2_SPI1);
	MRCC_voidEnablePeripheral(RCC_APB2 , RCC_APB2_SYSCFG);
	/**************Peripheral Initialization**************/
	MSTK_voidInit();
	MEXTI_voidInit();
	HTFT_voidInit();
	HSTP_voidInit();
	HR2RDAC_voidInit();
	/***************GPIO Initializtion*******************/
	MGPIO_voidSetPinMode(GPIO_PORTA , GPIO_PIN12 , GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA , GPIO_PIN12 , GPIO_PUSH_PULL , GPIO_MID_SPEED );
	MGPIO_voidSetResetPin(GPIO_PORTA , GPIO_PIN12 , GPIO_RESET);
	MGPIO_voidSetPinMode(GPIO_PORTC , GPIO_PIN14 , GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTC , GPIO_PIN14 , GPIO_PUSH_PULL , GPIO_MID_SPEED );
	MGPIO_voidSetResetPin(GPIO_PORTC , GPIO_PIN14 , GPIO_SET);
	MGPIO_voidSetPinMode(GPIO_PORTB , GPIO_PIN0 , GPIO_INPUT);
	MGPIO_voidSetPinInputMode(GPIO_PORTB , GPIO_PIN0 , GPIO_PULLUP);
	MGPIO_voidSetPinMode(GPIO_PORTB , GPIO_PIN1 , GPIO_INPUT);
	MGPIO_voidSetPinInputMode(GPIO_PORTB , GPIO_PIN1 , GPIO_PULLUP);
	MGPIO_voidSetPinMode(GPIO_PORTA , GPIO_PIN2 , GPIO_INPUT);
	MGPIO_voidSetPinInputMode(GPIO_PORTA , GPIO_PIN2 , GPIO_PULLUP);
	/***************EXTI Initializtions******************/
	MNVIC_voidEnablePeripheralInterrupt(6);
	MNVIC_voidEnablePeripheralInterrupt(7);
	MNVIC_voidEnablePeripheralInterrupt(8);
	MEXTI_voidSetCallBack(MEXTI_LINE0 , EXTI0_Handler);
	MEXTI_voidSetCallBack(MEXTI_LINE1 , EXTI1_Handler);
	MEXTI_voidSetCallBack(MEXTI_LINE2 , EXTI2_Handler);
	MEXTI_voidEnableEXTILine(MEXTI_LINE0);
	MEXTI_voidEnableEXTILine(MEXTI_LINE1);
	MEXTI_voidEnableEXTILine(MEXTI_LINE2);
	/*****************Systick Initialization************/
	MSTK_voidEnableInterrupt();
	MSTK_voidSetCallBack(STK_Handler);
	MSTK_voidEnableSTK();
	while (1)
	{
		/*Check on Playing Flag*/
		if (global_u8FlagVal != 0)
		{
			/*Set Led Matrix Value*/
			HSTP_voidLedMatrixScrollingAsync(Ptr_Name , global_u8LedMatrixIndex);
			global_u16TimeCount++;
			/*Check on a Counter to make the scrolling Effect*/
			if (global_u16TimeCount == 100)
			{
				/*Check on the Index of Led Matrix Array*/
				if (global_u8LedMatrixIndex < 40)
				{
					global_u8LedMatrixIndex++;
				}
				else
				{
					global_u8LedMatrixIndex = 0;
					/*if Playing Mohamed Monir's song ,Switch on the first and the last Name (as it can't be in one Array)*/
					if ((global_u8CurrentSinger == 1) && (Ptr_Name == global_u64Mohamed))
					{
						Ptr_Name = global_u64Monir;
					}
					else if ((global_u8CurrentSinger == 1) && (Ptr_Name == global_u64Monir))
					{
						Ptr_Name = global_u64Mohamed;
					}
					/*if on the exit sequence , Stop Led Matrix*/
					else if ((global_u8CurrentSinger == 255))
					{
						global_u8FlagVal = 0;
					}

				}
				/*Reset Counter*/
				global_u16TimeCount =0;
			}
		}
	}
}

void EXTI0_Handler (void)
{
	/*Check if we are already playing Amr Diab's song*/
	if (global_u8CurrentSinger != 0)
	{
		/*Change Led matrix pointer to point at Amr Diab's Name array*/
		Ptr_Name = global_u64Amr;
		/*Reset the Led matrix Index*/
		global_u8LedMatrixIndex = 0;
		/*Reset Dac Index to start from the beggining*/
		global_u32DacIndex = 0;
		/*Change Dac pointer to point at Amr Diab's Song array*/
		Ptr_Song = &DAC_Diab;
		/*Set Current Singer to Amr Diab*/
		global_u8CurrentSinger = 0;
		/*Display Amr Diab's Photo on TFT*/
		HTFT_voidSendPicture(&TFT_Diad);
		/*Turn on the TFT screen*/
		MGPIO_voidSetResetPin(GPIO_PORTC , GPIO_PIN14 , GPIO_RESET);
		/*Set the size on the song on the song size variable*/
		global_u32SongSize = 34526;
		/*Set the Preload value to acheive 8KHz*/
		MSTK_voidSetPreloadValue(2000);
		/*Enable Systick (if not already enabled)*/
		MSTK_voidEnableSTK();
		/*Set the Playing Flag to 1*/
		global_u8FlagVal = 1;
	}

}
void EXTI1_Handler (void)
{
	/*Check if we are already playing Monir's song*/
	if (global_u8CurrentSinger != 1)
	{
		/*Change Led matrix pointer to point at Monir's Name array*/
		Ptr_Name = global_u64Mohamed;
		/*Reset the Led matrix Index*/
		global_u8LedMatrixIndex = 0;
		/*Reset Dac Index to start from the beggining*/
		global_u32DacIndex = 0;
		/*Change Dac pointer to point at Monir's Song array*/
		Ptr_Song = &DAC_Monir;
		/*Set Current Singer to Monir*/
		global_u8CurrentSinger = 1;
		/*Display Monir's Photo on TFT*/
		HTFT_voidSendPicture(&TFT_Monir);
		/*Turn on the TFT screen*/
		MGPIO_voidSetResetPin(GPIO_PORTC , GPIO_PIN14 , GPIO_RESET);
		/*Set the size on the song on the song size variable*/
		global_u32SongSize = 37286;
		/*Set the Preload value to acheive 8KHz*/
		MSTK_voidSetPreloadValue(2000);
		/*Enable Systick (if not already enabled)*/
		MSTK_voidEnableSTK();
		/*Set the Playing Flag to 1*/
		global_u8FlagVal = 1;
	}
}
void EXTI2_Handler (void)
{
	/*Change Led matrix pointer to point at Exit Sequece array*/
	Ptr_Name = global_u64Exit;
	/*Reset the Led matrix Index*/
	global_u8LedMatrixIndex = 0;
	/*Turn off the TFT screen*/
	MGPIO_voidSetResetPin(GPIO_PORTC , GPIO_PIN14 , GPIO_SET);
	/*Blink All Eight Leds*/
	MGPIO_voidSetResetPin(GPIO_PORTA , GPIO_PIN12 , GPIO_SET);
	MSTK_voidDelayms(500);
	MGPIO_voidSetResetPin(GPIO_PORTA , GPIO_PIN12 , GPIO_RESET);
	/*Change Current Singer to None*/
	global_u8CurrentSinger = -1;

}


void STK_Handler (void)
{
	/*Set the Dac to the corresponding Array Element*/
	HR2RDAC_voidSendDataAsync(Ptr_Song , global_u32DacIndex);
	/*Reset the Index Variable when the song ends*/
	if (global_u32DacIndex < global_u32SongSize)
	{
		global_u32DacIndex++;
	}
	else
	{
		global_u32DacIndex = 0;
	}

}
