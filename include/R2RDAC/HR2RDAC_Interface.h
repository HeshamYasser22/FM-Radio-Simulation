/*
 * HR2RDAC_Interface.h
 *
 *  Created on: Sep 13, 2023
 *      Author: Hesham Yasser
 */

#ifndef HR2RDAC_INTERFACE_H_
#define HR2RDAC_INTERFACE_H_


void HR2RDAC_voidInit (void);
void HR2RDAC_voidSendData (u8 * p_u8Arr , u32 A_u32ArraySize);
void HR2RDAC_voidSendDataAsync (u8 * p_u8Arr , u32 A_u32Index);


#endif /* HR2RDAC_INTERFACE_H_ */
