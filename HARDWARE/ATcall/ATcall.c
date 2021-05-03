#include "ATcall.h"
#include "usart.h"
#include "AT_ESP.H"
//#include "oled.h"
//#include "gui.h"
#include "dht11.h"
#include "string.h"


extern char ESPBuffer[128];


char wifi_name[] = "YW1302";
char wifi_pass[] = "yyxwst1302";

char server_ip[] = "服务器ip";
char server_port[] = "服务器端口";









/*
///////////////////////////////////////////////////////////////////////////
有参方法传参用于向服务器发送数据
///////////////////////////////////////////////////////////////////////////
*/
void Uploading(char *mode ){
	
	esp8266 test;
	esp8266Init(&test);
	printf("准备发送ID====%s\r\n", mode);
			while(0)
			{
				if(test.ConnectCirmode(0))//设置穿透模式
				{
					USART1_Info("非穿透模式成功.....\r\n");
					break;
				}
				else{
					USART1_Info("非穿透模式失败.....\r\n");
					delay_ms(100);
					USART1_Info("准备重新设置穿透模式.\r\n");
					break;
				}
			}
			delay_ms(100);
			while(0)
			{
				USART1_Info("正在连接服务器.....\r\n");
					//	OLED_Clear(0);             //清屏（全黑）
				//GUI_ShowCHinese(0,0,16,"正在连接服务器",1);
				if(test.ConnectServer(server_ip,server_port,0))
				{
				USART1_Info("服务器已连接.....\r\n");
				//			OLED_Clear(0);             //清屏（全黑）
				//GUI_ShowCHinese(0,0,16,"服务器已连接",1);
					break;
				}
				else
				{
				USART1_Info("服务器连接失败.....\r\n");
				//			OLED_Clear(0);             //清屏（全黑）
				//GUI_ShowCHinese(0,0,16,"服务器连接失败",1);
				delay_ms(100);
				USART1_Info("准备重新连接.\r\n");
				}
			}
			delay_ms(100);
			
			while(1)
			{
				//OLED_Clear(0);             //清屏（全黑）
				//GUI_ShowCHinese(0,0,16,"开始发送数据",1);
				USART1_Info("开始发送数据.....\r\n");
				if(test.SendStringDataToServer(mode))
					{
						USART1_Info("数据发送成功.....\r\n");
					//	OLED_Clear(0);             //清屏（全黑）
					//	GUI_ShowCHinese(0,0,16,"数据发送成功",1);
						delay_ms(100);
						break;
					}
					else
					{
					//	OLED_Clear(0);             //清屏（全黑）
					//	GUI_ShowCHinese(0,0,16,"数据发送失败",1);	
						USART1_Info("数据发送失败.....\r\n");
						break;
					}
			}
}


/*
-------------------------------------------------------------------------------
函数ATcall：自动配置atcall模块，并通过usart1发送结果
配置过程：
1，检测at模块
2，wifi模式配置为3
3，打开多链接模式
4，打开tcp服务器，ip192.168.4.1：8080
-------------------------------------------------------------------------------
*/
void ATcall(void)
{
	esp8266 test;
	esp8266Init(&test);



	delay_ms(1000);
	//GUI_ShowCHinese(0,0,16,"程序加载中",1);
	USART1_Info("等待程序加载完毕.....\r\n");
	delay_ms(1000);
	//	OLED_Clear(0);             //清屏（全黑）
	//GUI_ShowCHinese(0,0,16,"程序加载中",1);
	USART1_Info("等待程序加载完毕.....\r\n");
	delay_ms(1000);
	//	OLED_Clear(0);             //清屏（全黑）
	//GUI_ShowCHinese(0,0,16,"程序加载中",1);
	USART1_Info("等待程序加载完毕.....\r\n");		
		
		
	while(1)
	{
		//OLED_Clear(0);             //清屏（全黑）
		//GUI_ShowCHinese(0,0,16,"检测模块",1);
		USART1_Info("检测ESP01是否连接.....\r\n");
		if(!test.CheckESP()) //检测ESP01
		{
		//	GUI_ShowCHinese(0,0,16,"重新检测模块",1);
			USART1_Info("未检测到ESP01.....\r\n");
			delay_ms(100);
			USART1_Info("重新检测.\r\n");
			delay_ms(100);
		//	OLED_Clear(0);             //清屏（全黑）
			delay_ms(100);
			
		}
		else{
			USART1_Info("ESP01已连接.....\r\n");
		//	OLED_Clear(0);             //清屏（全黑）
		//	GUI_ShowCHinese(0,0,16,"已连接模块",1);
			break;
		}
	}

	delay_ms(1000);
	
			while(1)
	{
	
		USART1_Info("设置ESP01模式1.....\r\n");
		if(test.SetEspMode(1))
		{
			USART1_Info("模式1已设置.....\r\n");
			break;
		}
		else{
			USART1_Info("模式1失败.....\r\n");
			delay_ms(100);
			USART1_Info("重新设置.\r\n");
		}
	
	}
	
	delay_ms(1000);
	

	while(1)
	{
		//		OLED_Clear(0);             //清屏（全黑）
		//GUI_ShowCHinese(0,0,16,"连接网络",1);
		USART1_Info("正在连接WIFI中.....\r\n");
		if(test.ConnectWiFi(wifi_name,wifi_pass))//WiFi连接超时时间6s；
		{
		USART1_Info("wifi[lab]已连接.....\r\n");
		//			OLED_Clear(0);             //清屏（全黑）
		//GUI_ShowCHinese(0,0,16,"已连接网络",1);
			break;
		}
		else
		{
		//			OLED_Clear(0);             //清屏（全黑）
		//GUI_ShowCHinese(0,0,16,"已连接网络失败",1);
		USART1_Info("wifi[lab]连接失败.....\r\n");
		delay_ms(300);
		USART1_Info("wifi[lab]准备重新连接.\r\n");
		delay_ms(400);
		USART1_Info("wifi[lab]准备重新连接.\r\n");
		delay_ms(500);
		USART1_Info("wifi[lab]准备重新连接.\r\n");
		//			OLED_Clear(0);             //清屏（全黑）
		//GUI_ShowCHinese(0,0,16,"重新连接网络",1);
		}
	}
	
	
	
	delay_ms(1000);
	
	while(1)
	{

		if(test.ConnectCirmode(0))//设置穿透模式
		{
			USART1_Info("穿透模式成功.....\r\n");
			break;
		}
		else{
			USART1_Info("穿透模式失败.....\r\n");
			delay_ms(100);
			USART1_Info("准备重新设置穿透模式.\r\n");
		}
	}
	
	delay_ms(1000);

	while(1)
			{
				USART1_Info("正在连接服务器.....\r\n");
				//		OLED_Clear(0);             //清屏（全黑）
				//GUI_ShowCHinese(0,0,16,"正在连接服务器",1);
				if(test.ConnectServer(server_ip,server_port,0))
				{
				USART1_Info("服务器已连接.....\r\n");
				//			OLED_Clear(0);             //清屏（全黑）
				//GUI_ShowCHinese(0,0,16,"服务器已连接",1);
					break;
				}
				else
				{
				USART1_Info("服务器连接失败.....\r\n");
				//			OLED_Clear(0);             //清屏（全黑）
				//GUI_ShowCHinese(0,0,16,"服务器连接失败",1);
				delay_ms(100);
				USART1_Info("准备重新连接.\r\n");
				delay_ms(200);
				USART1_Info("准备重新连接.\r\n");
				delay_ms(300);
				USART1_Info("准备重新连接.\r\n");
				//			OLED_Clear(0);             //清屏（全黑）
				//GUI_ShowCHinese(0,0,16,"服务器重新连接",1);
				}
			}
			delay_ms(1000);
}
/*
-------------------------------------------------------------------------------
函数WiFiSendData：通过WiFi发送单字符
IPD为接入客户端id
仅可在多连接模式下使用
发送字符串直接调用SendStringDataToMultServer(char *ipd,char *Data)
例如test.SendStringDataToMultServer("0","jiqirenxiehui");
-------------------------------------------------------------------------------
*/
void WiFiSendData(u16 IPD,u16 DATA)
{	esp8266 test;
	char ipd[1];
	char data[1];
	ipd[0]=IPD+48;
	data[0]=DATA;
	esp8266Init(&test);
	test.SendStringDataToMultServer(ipd,data);

}
/*
-------------------------------------------------------------------------------
函数WiFiReadData：通过WiFi接收字符串
-------------------------------------------------------------------------------
*/
void WiFiReadData()
{	esp8266 test;
	esp8266Init(&test);
	if(!CheckResponse())
	{
	USART1_SendString(ESPBuffer);
	}
	ClearESPBuffer();

}
