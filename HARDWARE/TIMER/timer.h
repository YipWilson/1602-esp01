#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"


//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEKս��STM32������
//��ʱ�� ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/3
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////   
#define def10ms  10
#define def1ms  10
#define def2khz  5

extern u8 ucFlash1hz;





void TIM3_Int_Init(u16 arr,u16 psc);
 
#endif
