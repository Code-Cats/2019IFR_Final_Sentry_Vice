#ifndef USART2_MAINBOARD_ANALYSIS_H
#define USART2_MAINBOARD_ANALYSIS_H

#include "sys.h"

typedef struct
{
	u8 statu;
	u8 data[5];
	u8 count;
}MainBoardSendTypeDef;

#define MAINBOARD_SENDDATA_DEFAULT \
{\
	0,\
	{0x5A,0,0,0,0xA5},\
	0,\
}\

typedef struct
{
	u8 headOK_state;
	u8 valid_state;	//����֡��Ч��־λ
	u8 databuffer[5];
	u8 count;
}ReceiveDataTypeDef;

typedef struct
{
	u8 valve[6];
	u8 servo[2];	//�ݶ����λ
	u8 image_cut[2];
}MainControlDataTypeDef;

extern MainBoardSendTypeDef SendData;
extern ReceiveDataTypeDef ReceiveData;
extern MainControlDataTypeDef MainControlData;

void Data_Receive(u8 data);	//�����崫���������ݽ�����������ͨ�ã�
void MainControlData_Deal(u8 *pData);	//����֡ͷ�ĵ�һ֡Ϊ����֡��ǰ4λΪVALVE��5-6λΪ����λ��7-8Ϊ���λ
void MainBoard_SendData(void);

#endif

