#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "OLED_Data.h"
#include "SG90.h"
#include "Serial.h"
#include "string.h"
#include "Serial3.h" 

float Angle;
uint8_t SG90_Status;		//舵机状态
uint8_t Face_Status;		//脸模显示状态

int main(void)
{
	/*模块初始化*/
	OLED_Init();		//OLED初始化
	SG90_Init();		//舵机初始化
	Serial_Init();		//串口初始化
	USART3_Init(9600);//串口1波特率设置为9600
	
	OLED_ShowImage(0,0,128,64,FaceDou);		//开机显示表情
	OLED_Update();
	
	Delay_ms(1000);
	SG90_Up();
	
	while (1)
	{
		if ((Serial_RxFlag == 1)||(USART3_Serial_RxFlag==1))		
		{
			if(USART3_Serial_RxFlag==1)strcpy(Serial_RxPacket,USART3_Serial_RxPacket);
			if (strcmp(Serial_RxPacket, "Advance") == 0){SG90_Status =1;Face_Status =1;}
			if (strcmp(Serial_RxPacket, "Retreat") == 0){SG90_Status =2;Face_Status =2;}
			if (strcmp(Serial_RxPacket, "Right") == 0){SG90_Status =3;Face_Status =3;}
			if (strcmp(Serial_RxPacket, "Left") == 0){SG90_Status =4;Face_Status =4;}
			if (strcmp(Serial_RxPacket, "Down") == 0){SG90_Status =5;Face_Status =5;}
			if (strcmp(Serial_RxPacket, "Up") == 0){SG90_Status =6;Face_Status =6;}
			if (strcmp(Serial_RxPacket, "Hard") == 0){SG90_Status =7;Face_Status =7;}
			if (strcmp(Serial_RxPacket, "Rock") == 0){SG90_Status =8;Face_Status =8;}
			if (strcmp(Serial_RxPacket, "Sit") == 0){SG90_Status =9;Face_Status =9;}
			if (strcmp(Serial_RxPacket, "Sit_Hard") == 0){SG90_Status =10;Face_Status =10;}
			if (strcmp(Serial_RxPacket, "Advance_plus") == 0){SG90_Status =11;Face_Status =11;}
			if (strcmp(Serial_RxPacket, "Retreat_plus") == 0){SG90_Status =12;Face_Status =12;}
			if (strcmp(Serial_RxPacket, "Right_plus") == 0){SG90_Status =13;Face_Status =13;}
			if (strcmp(Serial_RxPacket, "Left_plus") == 0){SG90_Status =14;Face_Status =14;}
			if (strcmp(Serial_RxPacket, "Ass") == 0){SG90_Status =15;Face_Status =15;}
			if (strcmp(Serial_RxPacket, "Dou") == 0){Face_Status =16;}
			if (strcmp(Serial_RxPacket, "Crazy") == 0){Face_Status =17;}
			Serial_RxFlag = 0;
			USART3_Serial_RxFlag = 0;
		}
		
		
		switch(SG90_Status)		//舵机状态选择
		{
			case 1: SG90_Advance();break;
			case 2: SG90_Retreat();break;
			case 3: SG90_TrunRight();break;
			case 4: SG90_TrunLeft();break;
			case 5: SG90_Down();break;
			case 6: SG90_Up();break;
			case 7: SG90_Hard();break;
			case 8: SG90_Rock();break;
			case 9: SG90_Sit();break;
			case 10: SG90_SitHard();break;
			case 11: SG90_CrazyAdvance();break;
			case 12: SG90_CrazyRetreat();break;
			case 13: SG90_CrazyTrunRight();break;
			case 14: SG90_CrazyTrunLeft();break;
			case 15: SG90_Ass();break;
		}
			
		switch(Face_Status)		//脸模显示状态选择
		{
			case 1: OLED_ShowImage(0,0,128,64,FaceDou);OLED_Update();break;
			case 2: OLED_ShowImage(0,0,128,64,FaceDou);OLED_Update();break;
			case 3: OLED_ShowImage(0,0,128,64,FaceRight);OLED_Update();break;
			case 4: OLED_ShowImage(0,0,128,64,FaceLeft);OLED_Update();break;
			case 5: OLED_ShowImage(0,0,128,64,FaceSleep);OLED_Update();break;
			case 6: OLED_ShowImage(0,0,128,64,FaceBlock);OLED_Update();break;
			case 7: OLED_ShowImage(0,0,128,64,FaceDou);OLED_Update();break;
			case 8: OLED_ShowImage(0,0,128,64,FaceCry);OLED_Update();break;
			case 9: OLED_ShowImage(0,0,128,64,FaceDou);OLED_Update();break;
			case 10: OLED_ShowImage(0,0,128,64,FaceDou);OLED_Update();break;
			case 11: OLED_ShowImage(0,0,128,64,FaceEvil);OLED_Update();break;
			case 12: OLED_ShowImage(0,0,128,64,FaceEvil);OLED_Update();break;
			case 13: OLED_ShowImage(0,0,128,64,FaceEvil);OLED_Update();break;
			case 14: OLED_ShowImage(0,0,128,64,FaceEvil);OLED_Update();break;
			case 15: OLED_ShowImage(0,0,128,64,FaceAss);OLED_Update();break;
			case 16: OLED_ShowImage(0,0,128,64,FaceDou);OLED_Update();break;
			case 17: OLED_ShowImage(0,0,128,64,FaceEvil);OLED_Update();break;
		}

	}
}
