/*
 * MEXTI_Configurations.c
 *
 *  Created on: Sep 12, 2023
 *      Author: Hesham Yasser
 */


#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_Types.h"
#include "../include/EXTI/MEXTI_Interface.h"
#include "../include/EXTI/MEXTI_private.h"
#include "../include/EXTI/MEXTI_Configuration.h"


/*
 * MEXTI_Configuartions {
	 * Line
	 * Port
	 * Mode
	 * Initial Value
 * }
 */


MEXTI_Configuartions MEXTI_Config [MEXTI_NUMBER] =
{
		{
				MEXTI_LINE0,
				MEXTI_PORTB,
				MEXTI_FALLING_EDGE,
				MEXTI_DISABLED
		}
		,
		{
				MEXTI_LINE1,
				MEXTI_PORTB,
				MEXTI_FALLING_EDGE,
				MEXTI_DISABLED
		}
		,
		{
				MEXTI_LINE2,
				MEXTI_PORTA,
				MEXTI_FALLING_EDGE,
				MEXTI_DISABLED
		}

};


