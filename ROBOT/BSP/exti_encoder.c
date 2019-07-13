#include "exti_encoder.h"
#include "gpio_switch.h"

//////////////////////////////////////////////////////////////////////////////////   
//�ⲿ�ж�10-12�������
void EXTIX_Encoder_Init(void)	//PC10 PC11 PC12 -> PB4 PB5 PA1
{

 	EXTI_InitTypeDef EXTI_InitStructure;
 	NVIC_InitTypeDef NVIC_InitStructure;

    //KEY_Init();	 //	�����˿ڳ�ʼ��

  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	//ʹ�ܸ��ù���ʱ��

    //GPIOB.4 �ж����Լ��жϳ�ʼ������   �½��ش���
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource4);

  	EXTI_InitStructure.EXTI_Line=EXTI_Line4;	//T5
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);	 	//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���

   //GPIOB.5	  �ж����Լ��жϳ�ʼ������ �½��ش��� //T6
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource5);
  	EXTI_InitStructure.EXTI_Line=EXTI_Line5;
  	EXTI_Init(&EXTI_InitStructure);	  	//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���

   //GPIOA.1	  �ж����Լ��жϳ�ʼ������  �½��ش���	//T7
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource1);
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
  	EXTI_InitStructure.EXTI_Line=EXTI_Line1;
  	EXTI_Init(&EXTI_InitStructure);	  	//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���

/************************************************************************
   //GPIOA.0	  �ж����Լ��жϳ�ʼ������ �����ش��� PA0  WK_UP
 	 GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0); 

  	EXTI_InitStructure.EXTI_Line=EXTI_Line0;
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  	EXTI_Init(&EXTI_InitStructure);		//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���


  	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;			//ʹ�ܰ���WK_UP���ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//��ռ���ȼ�2�� 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;					//�����ȼ�3
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
  	NVIC_Init(&NVIC_InitStructure); 
***************************************************************************/

//    NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;			//ʹ�ܰ���KEY1���ڵ��ⲿ�ж�ͨ��
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;	//��ռ���ȼ�2�� 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;					//�����ȼ�2
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
//  	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//ʹ�ܰ���KEY2���ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	//��ռ���ȼ�2�� 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;					//�����ȼ�2
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
  	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;			//ʹ�ܰ���KEY3���ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	//��ռ���ȼ�2�� 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;					//�����ȼ�2
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
  	NVIC_Init(&NVIC_InitStructure);

/**************************************************************************
  	NVIC_InitStructure.NVIC_IRQChannel = EXTI5_IRQn;			//ʹ�ܰ���KEY1���ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//��ռ���ȼ�2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;					//�����ȼ�1 
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
  	NVIC_Init(&NVIC_InitStructure);  	  //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���

	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;			//ʹ�ܰ���KEY0���ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//��ռ���ȼ�2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;					//�����ȼ�0 
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
  	NVIC_Init(&NVIC_InitStructure);  	  //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���
****************************************************************************/
}

u32 test[3]={0};
volatile s16 Encoder_Postion=0;
//�ⲿ�ж�10-15�������
void EXTI15_10_IRQHandler(void)	//��Ȧ2690 ���7  �����40-->6cm
{
//	delay_ms(10);//����
	if(EXTI_GetFlagStatus(EXTI_Line10)!=RESET)	//pc10 t5
	{
		EXTI_ClearFlag(EXTI_Line10);
		EXTI_ClearITPendingBit(EXTI_Line10);
		test[0]++;
		if(T6_IN==1)
		{
			Encoder_Postion++;
		}
		else
		{
			Encoder_Postion--;
		}
	}
	
	if(EXTI_GetFlagStatus(EXTI_Line11)!=RESET)	//pc11 t6
	{
		EXTI_ClearFlag(EXTI_Line11);
		EXTI_ClearITPendingBit(EXTI_Line11);
		test[1]++;
	}
	
	if(EXTI_GetFlagStatus(EXTI_Line12)!=RESET)	//pc12 t7
	{
		EXTI_ClearFlag(EXTI_Line12);
		EXTI_ClearITPendingBit(EXTI_Line12);
		test[2]++;
////		if(T6_IN==0)	//�����Բ���
////		{
////			pos_test++;
////		}
////		else
////		{
////			pos_test--;
////		}
//////		if(T5_IN==0)	//�����Բ���
//////		{
//////			pos_test++;
//////		}
//////		else
//////		{
//////			pos_test--;
//////		}
//////	}

//	EXTI_ClearITPendingBit(EXTI_Line2);  //���LINE2�ϵ��жϱ�־λ  
	}
}


void EXTI4_IRQHandler(void)	//T5
{
	test[0]++;
	if(EXTI_GetFlagStatus(EXTI_Line4)!=RESET)	//pc10 t5
	{
		//EXTI_ClearFlag(EXTI_Line4);
		//EXTI_ClearITPendingBit(EXTI_Line4);
		//test[0]++;
//		if(T6_IN==1)
//		{
//			Encoder_Postion++;
//		}
//		else
//		{
//			Encoder_Postion--;
//		}
	}
	
	EXTI_ClearFlag(EXTI_Line4);
	EXTI_ClearITPendingBit(EXTI_Line4);  //���LINE4�ϵ��жϱ�־λ  
}

volatile u8 trigger_flag=0;
//�ⲿ�ж�5�������
void EXTI9_5_IRQHandler(void)	//T6
{
	test[1]++;
	
	trigger_flag=1;
	//if(EXTI_GetFlagStatus(EXTI_Line5)!=RESET)	//pc10 t5
	//{
		//EXTI_ClearFlag(EXTI_Line4);
		//EXTI_ClearITPendingBit(EXTI_Line4);
//////	u16 gpioa=GPIOA->IDR;
//////	u8 pa1=gpioa>>1&0x01;
//////		if(pa1==1)
//////		{
//////			Encoder_Postion++;
//////		}
//////		else
//////		{
//////			Encoder_Postion--;
//////		}
	//}
	
	EXTI_ClearFlag(EXTI_Line5);
	EXTI_ClearITPendingBit(EXTI_Line5);  //���LINE3�ϵ��жϱ�־λ  
}

void EXTI1_IRQHandler(void)	//T7
{
	test[2]++;
	if(trigger_flag==1)
	{
		if(T7_IN==0)	//�½���
		{
			Encoder_Postion--;
		}
		else
		{
			Encoder_Postion++;
		}
		trigger_flag=0;
	}
//	if(EXTI_GetFlagStatus(EXTI_Line1)!=RESET)	//pc10 t5
//	{
//		//EXTI_ClearFlag(EXTI_Line4);
//		//EXTI_ClearITPendingBit(EXTI_Line4);
//////		if(T6_IN==1)
//////		{
//////			Encoder_Postion++;
//////		}
//////		else
//////		{
//////			Encoder_Postion--;
//////		}
//	}
	
	EXTI_ClearFlag(EXTI_Line1);
	EXTI_ClearITPendingBit(EXTI_Line1);  //���LINE4�ϵ��жϱ�־λ  
}
/************************************************************
//�ⲿ�ж�0������� 
void EXTI0_IRQHandler(void)
{
	delay_ms(10);//����
	if(WK_UP==1)	 	 //WK_UP����
	{				 
		BEEP=!BEEP;	
	}
	EXTI_ClearITPendingBit(EXTI_Line0); //���LINE0�ϵ��жϱ�־λ  
}
 
//�ⲿ�ж�2�������
void EXTI2_IRQHandler(void)
{
	delay_ms(10);//����
	if(KEY2==0)	  //����KEY2
	{
		LED0=!LED0;
	}		 
	EXTI_ClearITPendingBit(EXTI_Line2);  //���LINE2�ϵ��жϱ�־λ  
}
//�ⲿ�ж�3�������
void EXTI3_IRQHandler(void)
{
	delay_ms(10);//����
	if(KEY1==0)	 //����KEY1
	{				 
		LED1=!LED1;
	}		 
	EXTI_ClearITPendingBit(EXTI_Line3);  //���LINE3�ϵ��жϱ�־λ  
}

void EXTI4_IRQHandler(void)
{
	delay_ms(10);//����
	if(KEY0==0)	 //����KEY0
	{
		LED0=!LED0;
		LED1=!LED1; 
	}		 
	EXTI_ClearITPendingBit(EXTI_Line4);  //���LINE4�ϵ��жϱ�־λ  
}
************************************************************************/

