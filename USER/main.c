#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "led.h"
#include "lcd1602.h"
#include "timer.h"
#include "timemodu.h"
#include "key.h"
#include "buz.h"
#include "rtc.h"
#include "dht11.h" 
int main(void)
{
	u8 str[] = "ATOM@ALIENTEK";
	u8 t=0;
  	
	delay_init();
	NVIC_Configuration();
	uart_init(115200);
	RTC_Init();	  			//RTC初始化
	GPIO_Configuration();
	LED_Init();
	TIM3_Int_Init(79,59);   /// 8000*9000=72000000   1s中断一次   80*900=720000 1ms
	LCD1602_Init();
	while(DHT11_Init())	//DHT11初始化	
	{
		LCD1602_Show_Str(2, 1, "DHT11 Error");
 		delay_ms(500);
	}	
	//LCD1602_Show_Str(1, 0, str);
 	LCD1602_Show_Str(2, 1, "123");
	LCD1602_Show_Str(2, 1, "I LOVE YOU");
	BUZ_Application(5,30,2);//开机声两声
	
	ATcall();//配置esp01s
	while(1)
	{
		//===============时钟处理==================
		timemodu();
		if(t!=calendar.sec)
		{
			t=calendar.sec;
			//LCD_ShowNum(60,130,calendar.w_year,4,16);									  
			//LCD_ShowNum(100,130,calendar.w_month,2,16);									  
			//LCD_ShowNum(124,130,calendar.w_date,2,16);	
			sprintf(str, "%d-%d Temp:%d C", calendar.w_month,calendar.w_date,temperature);
			LCD1602_Show_Str(0, 0, str);
			sprintf(str, "%d:%d:%d Humi:%d", calendar.hour,calendar.min,calendar.sec,humidity);
			LCD1602_Show_Str(0, 1, str);
		}
		//===============按键处理==================
		//key_pro();
		//===============蜂鸣器处理==================
		BUZ_Drvpro();
		//===============串口处理====================
		//uart_deal();
		if(1 == fg1scheck)
		{
				//USART1_SendString(str);
		}
		//===============DH11处理====================
		DHT11_Deal();
	}
}

