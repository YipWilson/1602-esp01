#include "timemodu.h"

#define def10ms  10
#define def100ms  10
#define def1s  10
#define def2s  10

#define value1hz 100
//===============全局变量定义===============




timedevunion timedevuni;



//===============局部变量定义===============


//===============函数声明==================




//===============函数定义==================
void timemodu(void)
{
	static u8  cnt1ms;
	static u8  cnt10ms;
	static u8  cnt100ms;
	static u8  cnt1s;
	
	if(fg1scheck)
	{
		LED0=~LED0;
	}
		
	
	fg10mscheck=0;
	fg100mscheck=0;
	fg1scheck=0;

	
	
	if(fg1mscheck==1)
	{
		fg1mscheck=0;	
		cnt10ms++;
		
	}
	if(cnt10ms>def10ms)
	{
		fg10mscheck=1;	
		cnt10ms=0;
		cnt100ms++;
		
	}	
	if(cnt100ms>def100ms)
	{
		fg100mscheck=1;	
		cnt100ms=0;
		cnt1s++;
	}
	if(cnt1s>def1s)
	{
		fg1scheck=1;	
		cnt1s=0;
		
	}
}




