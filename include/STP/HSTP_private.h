/*
 * HSTP_private.h
 *
 *  Created on: Oct 7, 2023
 *      Author: Hesham Yasser
 */

#ifndef HSTP_PRIVATE_H_
#define HSTP_PRIVATE_H_

typedef struct {
	u8 Data_Port;
	u8 Data_Pin;
	u8 StorageClk_Port;
	u8 StorageClk_Pin;
	u8 ShiftClk_Port;
	u8 ShiftClk_Pin;
}STP_Configurations;


/*********************Macros*****************/

#define LAST_BIT				7



#endif /* HSTP_PRIVATE_H_ */
