/*
 * HSTP_Interface.h
 *
 *  Created on: Oct 7, 2023
 *      Author: Hesham Yasser
 */

#ifndef HSTP_INTERFACE_H_
#define HSTP_INTERFACE_H_

void HSTP_voidInit (void);

void HSTP_voidSendData (u8 A_u8STP,u8 A_u8Data);

void HSTP_voidLedMatrix (u8 * p_u8Data);

void HSTP_voidLedMatrixScrollingSync (u64 * p_u64Data , u8 A_RowNumber);

void HSTP_voidLedMatrixScrollingAsync (u64 * p_u64Data , u8 A_Index);



#endif /* HSTP_INTERFACE_H_ */
