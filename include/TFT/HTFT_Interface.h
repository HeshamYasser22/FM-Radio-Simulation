/*
 * HTFT_Interface.h
 *
 *  Created on: Sep 24, 2023
 *      Author: Hesham Yasser
 */

#ifndef HTFT_INTERFACE_H_
#define HTFT_INTERFACE_H_


void HTFT_voidReset (void);

void HTFT_voidInit (void);

void HTFT_voidSendPicture (const u16 * p_Picture);

void HTFT_voidSendCommand (u8 A_u8Command);

void HTFT_voidSendData (u8 A_u8Data);


#endif /* HTFT_INTERFACE_H_ */
