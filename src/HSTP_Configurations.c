/*
 * HSTP_Configurations.c
 *
 *  Created on: Oct 7, 2023
 *      Author: Hesham Yasser
 */
#include "../include/LIB/STD_Types.h"
#include "../include/GPIO/MGPIO_Interface.h"
#include "../include/STK/MSTK_Interface.h"
#include "../include/STP/HSTP_Interface.h"
#include "../include/STP/HSTP_private.h"
#include "../include/STP/HSTP_Configurations.h"

/*
 * STP_Configurations {
					 Data_Port
					 Data_Pin
					 StorageClk_Port
					 StorageClk_Pin
					 ShiftClk_Port
					 ShiftClk_Pin
					};
 */


STP_Configurations STP_Config [STP_NUMBER] =
											{
													{
														GPIO_PORTA,
														GPIO_PIN0,
														GPIO_PORTA,
														GPIO_PIN1,
														GPIO_PORTA,
														GPIO_PIN10
													}
													,
													{
														GPIO_PORTA,
														GPIO_PIN3,
														GPIO_PORTA,
														GPIO_PIN4,
														GPIO_PORTA,
														GPIO_PIN6
													}
											};
