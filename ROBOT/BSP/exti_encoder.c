#include "exti_encoder.h"
#include "gpio_switch.h"

//////////////////////////////////////////////////////////////////////////////////   
//外部中断10-12服务程序
void EXTIX_Encoder_Init(void)	//PC10 PC11 PC12 -> PB4 PB5 PA1
{

 	EXTI_InitTypeDef EXTI_InitStructure;
 	NVIC_InitTypeDef NVIC_InitStructure;

    //KEY_Init();	 //	按键端口初始化

  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	//使能复用功能时钟

    //GPIOB.4 中断线以及中断初始化配置   下降沿触发
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource4);

  	EXTI_InitStructure.EXTI_Line=EXTI_Line4;	//T5
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);	 	//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器

   //GPIOB.5	  中断线以及中断初始化配置 下降沿触发 //T6
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource5);
  	EXTI_InitStructure.EXTI_Line=EXTI_Line5;
  	EXTI_Init(&EXTI_InitStructure);	  	//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器

   //GPIOA.1	  中断线以及中断初始化配置  下降沿触发	//T7
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource1);
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
  	EXTI_InitStructure.EXTI_Line=EXTI_Line1;
  	EXTI_Init(&EXTI_InitStructure);	  	//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器

/************************************************************************
   //GPIOA.0	  中断线以及中断初始化配置 上升沿触发 PA0  WK_UP
 	 GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0); 

  	EXTI_InitStructure.EXTI_Line=EXTI_Line0;
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  	EXTI_Init(&EXTI_InitStructure);		//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器


  	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;			//使能按键WK_UP所在的外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//抢占优先级2， 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;					//子优先级3
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
  	NVIC_Init(&NVIC_InitStructure); 
***************************************************************************/

//    NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;			//使能按键KEY1所在的外部中断通道
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;	//抢占优先级2， 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;					//子优先级2
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
//  	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//使能按键KEY2所在的外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	//抢占优先级2， 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;					//子优先级2
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
  	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;			//使能按键KEY3所在的外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	//抢占优先级2， 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;					//子优先级2
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
  	NVIC_Init(&NVIC_InitStructure);

/**************************************************************************
  	NVIC_InitStructure.NVIC_IRQChannel = EXTI5_IRQn;			//使能按键KEY1所在的外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//抢占优先级2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;					//子优先级1 
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
  	NVIC_Init(&NVIC_InitStructure);  	  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器

	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;			//使能按键KEY0所在的外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//抢占优先级2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;					//子优先级0 
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
  	NVIC_Init(&NVIC_InitStructure);  	  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器
****************************************************************************/
}

u32 test[3]={0};
volatile s16 Encoder_Postion=0;
//外部中断10-15服务程序
void EXTI15_10_IRQHandler(void)	//整圈2690 误差7  最好在40-->6cm
{
//	delay_ms(10);//消抖
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
////		if(T6_IN==0)	//经测试不行
////		{
////			pos_test++;
////		}
////		else
////		{
////			pos_test--;
////		}
//////		if(T5_IN==0)	//经测试不行
//////		{
//////			pos_test++;
//////		}
//////		else
//////		{
//////			pos_test--;
//////		}
//////	}

//	EXTI_ClearITPendingBit(EXTI_Line2);  //清除LINE2上的中断标志位  
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
	EXTI_ClearITPendingBit(EXTI_Line4);  //清除LINE4上的中断标志位  
}

volatile u8 trigger_flag=0;
//外部中断5服务程序
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
	EXTI_ClearITPendingBit(EXTI_Line5);  //清除LINE3上的中断标志位  
}

void EXTI1_IRQHandler(void)	//T7
{
	test[2]++;
	if(trigger_flag==1)
	{
		if(T7_IN==0)	//下降沿
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
	EXTI_ClearITPendingBit(EXTI_Line1);  //清除LINE4上的中断标志位  
}
/************************************************************
//外部中断0服务程序 
void EXTI0_IRQHandler(void)
{
	delay_ms(10);//消抖
	if(WK_UP==1)	 	 //WK_UP按键
	{				 
		BEEP=!BEEP;	
	}
	EXTI_ClearITPendingBit(EXTI_Line0); //清除LINE0上的中断标志位  
}
 
//外部中断2服务程序
void EXTI2_IRQHandler(void)
{
	delay_ms(10);//消抖
	if(KEY2==0)	  //按键KEY2
	{
		LED0=!LED0;
	}		 
	EXTI_ClearITPendingBit(EXTI_Line2);  //清除LINE2上的中断标志位  
}
//外部中断3服务程序
void EXTI3_IRQHandler(void)
{
	delay_ms(10);//消抖
	if(KEY1==0)	 //按键KEY1
	{				 
		LED1=!LED1;
	}		 
	EXTI_ClearITPendingBit(EXTI_Line3);  //清除LINE3上的中断标志位  
}

void EXTI4_IRQHandler(void)
{
	delay_ms(10);//消抖
	if(KEY0==0)	 //按键KEY0
	{
		LED0=!LED0;
		LED1=!LED1; 
	}		 
	EXTI_ClearITPendingBit(EXTI_Line4);  //清除LINE4上的中断标志位  
}
************************************************************************/

