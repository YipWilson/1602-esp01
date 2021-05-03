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

char server_ip[] = "������ip";
char server_port[] = "�������˿�";









/*
///////////////////////////////////////////////////////////////////////////
�вη��������������������������
///////////////////////////////////////////////////////////////////////////
*/
void Uploading(char *mode ){
	
	esp8266 test;
	esp8266Init(&test);
	printf("׼������ID====%s\r\n", mode);
			while(0)
			{
				if(test.ConnectCirmode(0))//���ô�͸ģʽ
				{
					USART1_Info("�Ǵ�͸ģʽ�ɹ�.....\r\n");
					break;
				}
				else{
					USART1_Info("�Ǵ�͸ģʽʧ��.....\r\n");
					delay_ms(100);
					USART1_Info("׼���������ô�͸ģʽ.\r\n");
					break;
				}
			}
			delay_ms(100);
			while(0)
			{
				USART1_Info("�������ӷ�����.....\r\n");
					//	OLED_Clear(0);             //������ȫ�ڣ�
				//GUI_ShowCHinese(0,0,16,"�������ӷ�����",1);
				if(test.ConnectServer(server_ip,server_port,0))
				{
				USART1_Info("������������.....\r\n");
				//			OLED_Clear(0);             //������ȫ�ڣ�
				//GUI_ShowCHinese(0,0,16,"������������",1);
					break;
				}
				else
				{
				USART1_Info("����������ʧ��.....\r\n");
				//			OLED_Clear(0);             //������ȫ�ڣ�
				//GUI_ShowCHinese(0,0,16,"����������ʧ��",1);
				delay_ms(100);
				USART1_Info("׼����������.\r\n");
				}
			}
			delay_ms(100);
			
			while(1)
			{
				//OLED_Clear(0);             //������ȫ�ڣ�
				//GUI_ShowCHinese(0,0,16,"��ʼ��������",1);
				USART1_Info("��ʼ��������.....\r\n");
				if(test.SendStringDataToServer(mode))
					{
						USART1_Info("���ݷ��ͳɹ�.....\r\n");
					//	OLED_Clear(0);             //������ȫ�ڣ�
					//	GUI_ShowCHinese(0,0,16,"���ݷ��ͳɹ�",1);
						delay_ms(100);
						break;
					}
					else
					{
					//	OLED_Clear(0);             //������ȫ�ڣ�
					//	GUI_ShowCHinese(0,0,16,"���ݷ���ʧ��",1);	
						USART1_Info("���ݷ���ʧ��.....\r\n");
						break;
					}
			}
}


/*
-------------------------------------------------------------------------------
����ATcall���Զ�����atcallģ�飬��ͨ��usart1���ͽ��
���ù��̣�
1�����atģ��
2��wifiģʽ����Ϊ3
3���򿪶�����ģʽ
4����tcp��������ip192.168.4.1��8080
-------------------------------------------------------------------------------
*/
void ATcall(void)
{
	esp8266 test;
	esp8266Init(&test);



	delay_ms(1000);
	//GUI_ShowCHinese(0,0,16,"���������",1);
	USART1_Info("�ȴ�����������.....\r\n");
	delay_ms(1000);
	//	OLED_Clear(0);             //������ȫ�ڣ�
	//GUI_ShowCHinese(0,0,16,"���������",1);
	USART1_Info("�ȴ�����������.....\r\n");
	delay_ms(1000);
	//	OLED_Clear(0);             //������ȫ�ڣ�
	//GUI_ShowCHinese(0,0,16,"���������",1);
	USART1_Info("�ȴ�����������.....\r\n");		
		
		
	while(1)
	{
		//OLED_Clear(0);             //������ȫ�ڣ�
		//GUI_ShowCHinese(0,0,16,"���ģ��",1);
		USART1_Info("���ESP01�Ƿ�����.....\r\n");
		if(!test.CheckESP()) //���ESP01
		{
		//	GUI_ShowCHinese(0,0,16,"���¼��ģ��",1);
			USART1_Info("δ��⵽ESP01.....\r\n");
			delay_ms(100);
			USART1_Info("���¼��.\r\n");
			delay_ms(100);
		//	OLED_Clear(0);             //������ȫ�ڣ�
			delay_ms(100);
			
		}
		else{
			USART1_Info("ESP01������.....\r\n");
		//	OLED_Clear(0);             //������ȫ�ڣ�
		//	GUI_ShowCHinese(0,0,16,"������ģ��",1);
			break;
		}
	}

	delay_ms(1000);
	
			while(1)
	{
	
		USART1_Info("����ESP01ģʽ1.....\r\n");
		if(test.SetEspMode(1))
		{
			USART1_Info("ģʽ1������.....\r\n");
			break;
		}
		else{
			USART1_Info("ģʽ1ʧ��.....\r\n");
			delay_ms(100);
			USART1_Info("��������.\r\n");
		}
	
	}
	
	delay_ms(1000);
	

	while(1)
	{
		//		OLED_Clear(0);             //������ȫ�ڣ�
		//GUI_ShowCHinese(0,0,16,"��������",1);
		USART1_Info("��������WIFI��.....\r\n");
		if(test.ConnectWiFi(wifi_name,wifi_pass))//WiFi���ӳ�ʱʱ��6s��
		{
		USART1_Info("wifi[lab]������.....\r\n");
		//			OLED_Clear(0);             //������ȫ�ڣ�
		//GUI_ShowCHinese(0,0,16,"����������",1);
			break;
		}
		else
		{
		//			OLED_Clear(0);             //������ȫ�ڣ�
		//GUI_ShowCHinese(0,0,16,"����������ʧ��",1);
		USART1_Info("wifi[lab]����ʧ��.....\r\n");
		delay_ms(300);
		USART1_Info("wifi[lab]׼����������.\r\n");
		delay_ms(400);
		USART1_Info("wifi[lab]׼����������.\r\n");
		delay_ms(500);
		USART1_Info("wifi[lab]׼����������.\r\n");
		//			OLED_Clear(0);             //������ȫ�ڣ�
		//GUI_ShowCHinese(0,0,16,"������������",1);
		}
	}
	
	
	
	delay_ms(1000);
	
	while(1)
	{

		if(test.ConnectCirmode(0))//���ô�͸ģʽ
		{
			USART1_Info("��͸ģʽ�ɹ�.....\r\n");
			break;
		}
		else{
			USART1_Info("��͸ģʽʧ��.....\r\n");
			delay_ms(100);
			USART1_Info("׼���������ô�͸ģʽ.\r\n");
		}
	}
	
	delay_ms(1000);

	while(1)
			{
				USART1_Info("�������ӷ�����.....\r\n");
				//		OLED_Clear(0);             //������ȫ�ڣ�
				//GUI_ShowCHinese(0,0,16,"�������ӷ�����",1);
				if(test.ConnectServer(server_ip,server_port,0))
				{
				USART1_Info("������������.....\r\n");
				//			OLED_Clear(0);             //������ȫ�ڣ�
				//GUI_ShowCHinese(0,0,16,"������������",1);
					break;
				}
				else
				{
				USART1_Info("����������ʧ��.....\r\n");
				//			OLED_Clear(0);             //������ȫ�ڣ�
				//GUI_ShowCHinese(0,0,16,"����������ʧ��",1);
				delay_ms(100);
				USART1_Info("׼����������.\r\n");
				delay_ms(200);
				USART1_Info("׼����������.\r\n");
				delay_ms(300);
				USART1_Info("׼����������.\r\n");
				//			OLED_Clear(0);             //������ȫ�ڣ�
				//GUI_ShowCHinese(0,0,16,"��������������",1);
				}
			}
			delay_ms(1000);
}
/*
-------------------------------------------------------------------------------
����WiFiSendData��ͨ��WiFi���͵��ַ�
IPDΪ����ͻ���id
�����ڶ�����ģʽ��ʹ��
�����ַ���ֱ�ӵ���SendStringDataToMultServer(char *ipd,char *Data)
����test.SendStringDataToMultServer("0","jiqirenxiehui");
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
����WiFiReadData��ͨ��WiFi�����ַ���
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
