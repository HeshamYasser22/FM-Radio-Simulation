/*
 * MRCC_Interface.h
 *
 *  Created on: Sep 6, 2023
 *      Author: HeshamYasser
 */

#ifndef MRCC_INTERFACE_H_
#define MRCC_INTERFACE_H_


/**Buses**/

#define RCC_APB1				0
#define RCC_APB2				1
#define RCC_AHB1				2
#define RCC_AHB2				3


/********************APB1********************/

#define RCC_APB1_TIM2			0
#define RCC_APB1_TIM3			1
#define RCC_APB1_TIM4			2
#define RCC_APB1_TIM5			3
#define RCC_APB1_WWDG			11
#define RCC_APB1_SPI2			14
#define RCC_APB1_SPI3			15
#define RCC_APB1_USART2			17
#define RCC_APB1_I2C1			21
#define RCC_APB1_I2C2			22
#define RCC_APB1_I2C3			23
#define RCC_APB1_PWR			28

/********************APB2********************/

#define RCC_APB2_TIM1			0
#define RCC_APB2_USART1			4
#define RCC_APB2_USART6			5
#define RCC_APB2_ADC1			8
#define RCC_APB2_SDIO			11
#define RCC_APB2_SPI1			12
#define RCC_APB2_SPI4			13
#define RCC_APB2_SYSCFG			14
#define RCC_APB2_TIM9			16
#define RCC_APB2_TIM10			17
#define RCC_APB2_TIM11			18

/********************AHB1********************/

#define RCC_AHB1_GPIOA			0
#define RCC_AHB1_GPIOB			1
#define RCC_AHB1_GPIOC			2
#define RCC_AHB1_GPIOD			3
#define RCC_AHB1_GPIOE			4
#define RCC_AHB1_GPIOH			7
#define RCC_AHB1_CRC			12
#define RCC_AHB1_DMA1			21
#define RCC_AHB1_DMA2			22

/********************AHB2********************/

#define RCC_AHB2_OTGFS			7

/*********************APIs*********************/

void MRCC_voidInit (void);
void MRCC_voidEnablePeripheral(u32 A_u32BusAddress , u32 A_u32Peripheral);
void MRCC_voidDisablePeripheral(u32 A_u32BusAddress , u32 A_u32Peripheral);



#endif /* MRCC_INTERFACE_H_ */
