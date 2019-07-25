#include "stm32f10x.h"
#include "timer.h"
#include "gpio_led.h"
#include "pwm.h"
#include "base_deal.h"
#include "gpio_switch.h"
#include "gpio_valve.h"
#include "delay.h"
#include "bsp.h"
#include "usart2_mainboard_analysis.h"

extern s16 Encoder_Postion;

extern SwitchTypeDef Switch;
/************************************************
STM32F103C8T6С�̰�
************************************************/


 u32 trigger_count=0;
// u16 pwm_tem=500;
 int main(void)
 {
	delay_init();
	delay_ms(200);
//	//AFIO->MAPR|=AFIO_MAPR_SWJ_CFG_JTAGDISABLE;	//	����JTAG��ֻ����SWD��ʽ����,ò���������û���𵽸��е�����
	BSP_Init();	 
  while(1)	//T6_IN T7_IN
	{
		MainBoard_SendData();
		delay_ms(1);
//GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);//����GPIO��ӳ�亯��		
//		PWM_PB4_Set(pwm_tem);
//		PWM_PB5_Set(pwm_tem);

////		if(Switch.Limit.rawdata[0]==1||Switch.Limit.rawdata[1]==1)
////		{
////			trigger_count++;
////			LED1=1;
////		}
////		else
////		{
////			LED1=0;
////		}
////		
////		if(Switch.Limit.rawdata[2]==1||Switch.Limit.rawdata[3]==1)
////		{
////			trigger_count++;
////			LED2=1;
////		}
////		else
////		{
////			LED2=0;
////		}
	}
 }
