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

extern s16 Encoder_Postion;

extern s16 Encoder_Postion;
u8 limitvalue[2]={0};
void Control_Task(void)
{
	if(L1_IN==0)
	{
		Encoder_Postion=0+40;
	}
	
	if(L2_IN==0)
	{
		Encoder_Postion=1740-40;
	}
	
	limitvalue[0]=L1_IN;
	limitvalue[1]=L2_IN;
	
	Switch_Scanf();
	Switch_Filter(); 
	if(SendData.statu==0)
	{
		SendData.data[1]=Encoder_Postion>>8;
		SendData.data[2]=(u8)Encoder_Postion;	//[4]为上下岛加速保护，[5]为拖车检测	//[6]为左对位 [7]为右对位
		SendData.data[3]=limitvalue[0]|(limitvalue[1]<<1);
		SendData.statu=1;
	}
	
	MainBoard_SendData();
}


