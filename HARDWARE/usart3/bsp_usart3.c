#include "sys.h" 
#include "string.h"
#include "stdio.h"
#include "bsp_usart3.h"
void USART3_Config()
{
    //GPIO�˿�����
    GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	//ʹ��USART3��GPIOBʱ��
 	USART_DeInit(USART3);  //��λ����3
	 //USART3_TX   PB.10
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; //PB.10
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//�����������
    GPIO_Init(GPIOB, &GPIO_InitStructure); //��ʼ��PB10
   
    //USART3_RX	  PB.11
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������
    GPIO_Init(GPIOB, &GPIO_InitStructure);  //��ʼ��PB11

   //Usart3 NVIC ����
	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
  
   //USART ��ʼ������

	USART_InitStructure.USART_BaudRate = 115200;//һ������Ϊ9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ

    USART_Init(USART3, &USART_InitStructure); //��ʼ������
    USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);//�����ж�
    USART_Cmd(USART3, ENABLE);                    //ʹ�ܴ��� 
}

//USART3�ķ����ֽ����ݺ���
void USART3_SendByte(uint8_t data)
{
	USART_SendData(USART3,data);
	
	while(USART_GetFlagStatus(USART3,USART_FLAG_TXE) == RESET);
}
//USART3�ķ��Ͳ��������ݺ���
void USART3_SendString(char *buffer)
{
	while(*(buffer) != '\0')
	{
		USART3_SendByte(*(buffer));
		buffer++;
	}
	
	while(USART_GetFlagStatus(USART3,USART_FLAG_TC)==RESET);
}

void USART3_SendData(char *buffer,int len)
{
	while(len--)
	{
		USART3_SendByte(*(buffer));
		buffer++;
	}
	while(USART_GetFlagStatus(USART3,USART_FLAG_TC)==RESET);
}







