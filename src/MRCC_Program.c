/*
 * MRCC_Program.c
 *
 *  Created on: Sep 6, 2023
 *      Author: Hesham Yasser
 */




#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_Types.h"
#include "../include/RCC/MRCC_Interface.h"
#include "../include/RCC/MRCC_private.h"
#include "../include/RCC/MRCC_Configurations.h"


void MRCC_voidInit (void)
{
#if SYS_CLK == RCC_HSI
	// Enable HSI
	SET_BIT(RCC->CR , CR_HSI_ON);
	// Wait till HSI is Ready
	while (GET_BIT(RCC->CR , CR_HSI_RDY) == RCC_NOT_READY);
	// Masking The Switching Bits
	RCC->CFGR &= ~(TWO_BIT_MASK << SW_b0);
	// Select HSI as System Clk Source
	RCC->CFGR |= (SW_HSI << SW_b0);

#elif SYS_CLK == RCC_HSE
	// Enable HSE
	SET_BIT(RCC->CR , CR_HSE_ON);
	// Wait till HSE is Ready
	while (GET_BIT(RCC->CR , CR_HSE_RDY) == RCC_NOT_READY);
	// Masking The Switching Bits
	RCC->CFGR &= ~(TWO_BIT_MASK << SW_b0);
	// Select HSE as System Clk Source
	RCC->CFGR |= (SW_HSE << SW_b0);

#elif SYS_CLK == RCC_PLL
	// Enable PLL
	SET_BIT(RCC->CR , CR_PLL_ON);
	// Wait till PLL is Ready
	while (GET_BIT(RCC->CR , CR_PLL_RDY) == RCC_NOT_READY);
	// Masking The Switching Bits
	RCC->CFGR &= ~(TWO_BIT_MASK << SW_b0);
	// Select PLL as System Clk Source
	RCC->CFGR |= (SW_PLL << SW_b0);

#else
#error WRONG_SYS_CLK
#endif

}
void MRCC_voidEnablePeripheral(u32 A_u32BusAddress , u32 A_u32Peripheral)
{
	if (A_u32BusAddress < RCC_NUMBER_OF_BUSES && A_u32Peripheral < BITS_PER_REGISTER)
	{
		switch (A_u32BusAddress)
		{
		case RCC_APB1:
			SET_BIT(RCC->APB1ENR,A_u32Peripheral);
			break;
		case RCC_APB2:
			SET_BIT(RCC->APB2ENR,A_u32Peripheral);
			break;
		case RCC_AHB1:
			SET_BIT(RCC->AHB1ENR,A_u32Peripheral);
			break;
		case RCC_AHB2:
			SET_BIT(RCC->AHB2ENR,A_u32Peripheral);
			break;
		default:
			break;
		}
	}
}
void MRCC_voidDisablePeripheral(u32 A_u32BusAddress , u32 A_u32Peripheral)
{
	if (A_u32BusAddress < RCC_NUMBER_OF_BUSES && A_u32Peripheral < BITS_PER_REGISTER)
	{
		switch (A_u32BusAddress)
		{
		case RCC_APB1:
			CLR_BIT(RCC->APB1ENR,A_u32Peripheral);
			break;
		case RCC_APB2:
			CLR_BIT(RCC->APB2ENR,A_u32Peripheral);
			break;
		case RCC_AHB1:
			CLR_BIT(RCC->AHB1ENR,A_u32Peripheral);
			break;
		case RCC_AHB2:
			CLR_BIT(RCC->AHB2ENR,A_u32Peripheral);
			break;
		default:
			break;
		}
	}
}
