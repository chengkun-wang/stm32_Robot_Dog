#ifndef __SERIAL3_H
#define __SERIAL3_H

#include <stdio.h>
#include "stm32f10x.h" 

extern char USART3_Serial_RxPacket[100];	
extern uint8_t USART3_Serial_RxFlag;	

void USART3_Init(u32 baud);   
void USART3_Sned_Char(u8 temp);
void USART3_Sned_Char_Buff(u8 buf[],u32 len);
void USART3_Serial_SendString(char *String);
#endif
