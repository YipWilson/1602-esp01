#ifndef __BSP_USART3_H__
#define __BSP_USART3_H__
#include "sys.h"

void USART3_Config(void);
void USART3_SendString(char *buffer);
void USART3_SendData(char *buffer,int len);
void GetEspData(char *RecvBuffer);

#endif
