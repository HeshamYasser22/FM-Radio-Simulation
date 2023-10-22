/*
 * MRCC_private.h
 *
 *  Created on: Sep 6, 2023
 *      Author: Hesham Yasser
 */

#ifndef MRCC_PRIVATE_H_
#define MRCC_PRIVATE_H_


#define RCC_BASE_ADDRESS			(0x40023800)


typedef struct
{
	u32 CR;
	u32 PLLCFRG;
	u32 CFGR;
	u32 CIR;
	u32 AHB1RSTR;
	u32 AHB2RSTR;
	u32 RESERVED1;
	u32 RESERVED2;
	u32 APB1RSTR;
	u32 APB2RSTR;
	u32 RESERVED3;
	u32 RESERVED4;
	u32 AHB1ENR;
	u32	AHB2ENR;
	u32 RESERVED5;
	u32 RESERVED6;
	u32 APB1ENR;
	u32 APB2ENR;
	u32 RESERVED7;
	u32 RESERVED8;
	u32 AHB1LPENR;
	u32 AHB2LPENR;
	u32 RESERVED9;
	u32 RESERVED10;
	u32 APB1LPENR;
	u32 APB2LPENR;
	u32	RESERVED11;
	u32 RESERVED12;
	u32 BDCR;
	u32 CSR;
	u32 RESERVED13;
	u32 RESERVED14;
	u32 SSCGR;
	u32 PLLI2SCFGR;
	u32 RESERVED15;
	u32 DCKCFGR;
}RCC_t;


#define RCC				((volatile RCC_t *)RCC_BASE_ADDRESS)

/***********************************************/
#define RCC_NUMBER_OF_BUSES			4
#define BITS_PER_REGISTER			32
#define RCC_NOT_READY				0
/***********************************************/
#define RCC_HSI							0
#define RCC_HSE							1
#define RCC_PLL							2
/**********************************************/
#define CR_HSI_ON						0
#define CR_HSI_RDY						1
#define CR_HSE_ON						16
#define CR_HSE_RDY						17
#define CR_PLL_ON						24
#define CR_PLL_RDY						25
#define SW_b0						0
#define SW_HSI						0b00
#define SW_HSE						0b01
#define SW_PLL						0b10
#define TWO_BIT_MASK				0b11
#endif /* MRCC_PRIVATE_H_ */
