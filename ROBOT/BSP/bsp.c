#include "bsp.h"

void BSP_Init(void)
{
	LED_Init();

	USART2_Mainboard_Init(256000);
	//TIM3_PWM_Init(ESC_CYCLE-1,72-1);	//5.11����//ESC_CYCLE=20000,20ms
	//	pwm_init();	//�����׵�
	TIM1_Int_Init(2000-1,72-1);	//	72MHZƵ�ʣ���Ƶ720(��֪��ΪʲôƵ���쳣���ʻ�����72)��100khz����Ƶ�ʣ�����100��Ϊ1ms,����200��Ϊ2ms
	//  Switch_Init();

	L1_2_Init();
	ECD1_2_Init();
	//T1_7_IN_Init();	//T1-T7����
	//P5_8_IN_Init();
	EXTIX_Encoder_Init();
}



