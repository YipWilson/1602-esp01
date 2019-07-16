#ifndef  __TIMEMODE_H
#define  __TIMEMODE_H
#include "stm32f10x.h"
#include "led.h"


#define   EXTR  extern



//===============全局变量定义===============



typedef union 
{
	u8 fgtimebyte;
	struct 
	{
		u8 fgtimebit0:1;
		u8 fgtimebit1:1;
		u8 fgtimebit2:1;
		u8 fgtimebit3:1;
		u8 fgtimebit4:1;
		u8 fgtimebit5:1;
		u8 fgtimebit6:1;
		u8 fgtimebit7:1;
	}timecheflag;
}timedevunion;



extern timedevunion timedevuni;


#define fg1mscheck  timedevuni.timecheflag.fgtimebit0   
#define fg10mscheck  timedevuni.timecheflag.fgtimebit1
#define fg100mscheck  timedevuni.timecheflag.fgtimebit2   
#define fg1scheck  timedevuni.timecheflag.fgtimebit3


//===============函数声明==================
//===============函数声明==================
void timemodu(void);







#endif
