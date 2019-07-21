#include "control.h"
#include "gpio_led.h"
#include "gpio_switch.h"
#include "timer.h"
#include "base_deal.h"
#include "usart2_mainboard_analysis.h"	


void LED_Runing(void)
{
	if(time_2ms_count%250==0)
	{
		//LED1=LED2;
		LED2=!LED2;
		
	}
	if(L1_IN==0||L2_IN==0)
		{
			LED1=0;
		}
		else
		{
			LED1=1;
		}
}

volatile s16 Encoder_Speed=0;
volatile u8 Encoder_Trigger=0;	//1为负触发 2为正触发
volatile u8 Encoder_Trigger_last=0;	//1为负触发 2为正触发
volatile u32 Encoder_TriggerTime_last=0;
volatile u32 Encoder_Trigger_Timdiff=0;	//时间差


extern volatile s16 Encoder_Postion;
u8 limitvalue[2]={0};
void Control_Task(void)
{
	if(L1_IN==0)
	{
		Encoder_Postion=0+40;
	}
	
	if(L2_IN==0)
	{
		Encoder_Postion=2390;
	}
	
	limitvalue[0]=L1_IN;
	limitvalue[1]=L2_IN;
	
	if(Encoder_Trigger!=0)
	{
		Encoder_Trigger_Timdiff=time_2ms_count-Encoder_TriggerTime_last;
		
		Encoder_Trigger_Timdiff=Encoder_Trigger_Timdiff<1?1:Encoder_Trigger_Timdiff;
		if(Encoder_Trigger_Timdiff>500)
		{
			Encoder_Speed=0;
		}
		else
		{
			Encoder_Speed=500/Encoder_Trigger_Timdiff;
		}
		if(Encoder_Trigger==1)
		{
			Encoder_Speed*=-1;
		}
		else if(Encoder_Trigger==2)
		{
			//do nothing
		}
		else
		{
			Encoder_Speed=0;
		}
		
		Encoder_TriggerTime_last=time_2ms_count;
		Encoder_Trigger_last=Encoder_Trigger;
		Encoder_Trigger=0;
	}
	else	//判断是否超时
	{
		if(time_2ms_count-Encoder_TriggerTime_last>Encoder_Trigger_Timdiff)
		{
			Encoder_Trigger_Timdiff=time_2ms_count-Encoder_TriggerTime_last;
		
			//Encoder_Trigger_Timdiff=Encoder_Trigger_Timdiff<1?1:Encoder_Trigger_Timdiff;此时必然大于1 无需判断
			if(Encoder_Trigger_Timdiff>500)
			{
				Encoder_Speed=0;
			}
			else
			{
				Encoder_Speed=500/Encoder_Trigger_Timdiff;
			}
			if(Encoder_Trigger==1)
			{
				Encoder_Speed*=-1;
			}
			else if(Encoder_Trigger==2)
			{
				//do nothing
			}
			else
			{
				Encoder_Speed=0;
			}
		}
	}
	
	//Switch_Scanf();
	//Switch_Filter(); 
	if(SendData.statu==0)
	{
		s8 send_speed=Encoder_Speed/5;
		SendData.data[1]=Encoder_Postion>>6;
		SendData.data[2]=(u8)(Encoder_Postion<<2)|limitvalue[0]|(limitvalue[1]<<1);	//Pos为14位0-16000
		SendData.data[3]=send_speed;
		SendData.statu=1;
	}
	
	MainBoard_SendData();
}


