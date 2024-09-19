#include "stm32f10x.h"                  // Device header
#include "PWM.h"
#include "Delay.h"

#define Speed 300
#define Crazy_Speed 200

void SG90_Init(void)		//舵机初始化
{
	PWM_Init();
}

void SG90_U1SetAngleLeft_Front(float Angle)		//左前脚，接A0口
{
	PWM_SetCompare1(Angle / 180 * 200 + 50);   
	
}

void SG90_U3SetAngle_Left_Behind(float Angle)		//左后脚，接A2口
{
	PWM_SetCompare3(Angle / 180 * 200 + 50);   
	
}

void SG90_U2SetAngleRight_Front(float Angle)		//右后脚，接A1口
{
	PWM_SetCompare2(Angle / 180 * 200 + 50);   
	
}

void SG90_U4SetAngleRight_Behind(float Angle)		//右前脚，接A3口
{
	PWM_SetCompare4(Angle / 180 * 200 + 50);   
	
}

void SG90_Advance(void)			//前进
{
	static uint8_t AdvanceFlag = 1;
	if (AdvanceFlag == 1)
	{
		SG90_U1SetAngleLeft_Front(90);
		SG90_U3SetAngle_Left_Behind(45);
		SG90_U2SetAngleRight_Front(90);
		SG90_U4SetAngleRight_Behind(135);	
		Delay_ms(Speed);
		AdvanceFlag++;
	}
	else if(AdvanceFlag == 2)
	{
		SG90_U1SetAngleLeft_Front(135);
		SG90_U3SetAngle_Left_Behind(45);
		SG90_U2SetAngleRight_Front(45);
		SG90_U4SetAngleRight_Behind(135);	
		Delay_ms(Speed);
		AdvanceFlag++;
	}
	else if(AdvanceFlag == 3)
	{
		SG90_U1SetAngleLeft_Front(135);
		SG90_U3SetAngle_Left_Behind(90);
		SG90_U2SetAngleRight_Front(45);
		SG90_U4SetAngleRight_Behind(90);	
		Delay_ms(Speed);
		AdvanceFlag++;
	}
	else if(AdvanceFlag == 4)
	{
		SG90_U1SetAngleLeft_Front(90);
		SG90_U3SetAngle_Left_Behind(90);
		SG90_U2SetAngleRight_Front(90);
		SG90_U4SetAngleRight_Behind(90);
		Delay_ms(Speed);		
		AdvanceFlag++;
	}
	else if(AdvanceFlag == 5)
	{
		SG90_U1SetAngleLeft_Front(45);
		SG90_U3SetAngle_Left_Behind(90);
		SG90_U2SetAngleRight_Front(135);
		SG90_U4SetAngleRight_Behind(90);	
		Delay_ms(Speed);
		AdvanceFlag++;
	}
	else if(AdvanceFlag == 6)
	{
		SG90_U1SetAngleLeft_Front(45);
		SG90_U3SetAngle_Left_Behind(135);
		SG90_U2SetAngleRight_Front(135);
		SG90_U4SetAngleRight_Behind(45);	
		Delay_ms(Speed);
		AdvanceFlag++;
	}
	else if(AdvanceFlag == 7)
	{
		SG90_U1SetAngleLeft_Front(90);
		SG90_U3SetAngle_Left_Behind(135);
		SG90_U2SetAngleRight_Front(90);
		SG90_U4SetAngleRight_Behind(45);	
		Delay_ms(Speed);
		AdvanceFlag++;
	}
	else if(AdvanceFlag == 8)
	{
		SG90_U1SetAngleLeft_Front(90);
		SG90_U3SetAngle_Left_Behind(90);
		SG90_U2SetAngleRight_Front(90);
		SG90_U4SetAngleRight_Behind(90);	
		Delay_ms(Speed);
		AdvanceFlag = 1;
	}

}

void SG90_Retreat(void)			//后退
{
	static uint8_t RetreatFlag = 1;

	if(RetreatFlag == 1)
	{
		SG90_U1SetAngleLeft_Front(90);
		SG90_U3SetAngle_Left_Behind(90);
		SG90_U2SetAngleRight_Front(90);
		SG90_U4SetAngleRight_Behind(90);	
		Delay_ms(Speed);
		RetreatFlag++;
	}	
	else if(RetreatFlag == 2)
	{
		SG90_U1SetAngleLeft_Front(90);
		SG90_U3SetAngle_Left_Behind(135);
		SG90_U2SetAngleRight_Front(90);
		SG90_U4SetAngleRight_Behind(45);	
		Delay_ms(Speed);
		RetreatFlag++;
	}
	else if(RetreatFlag == 3)
	{
		SG90_U1SetAngleLeft_Front(45);
		SG90_U3SetAngle_Left_Behind(135);
		SG90_U2SetAngleRight_Front(135);
		SG90_U4SetAngleRight_Behind(45);	
		Delay_ms(Speed);
		RetreatFlag++;
	}
	else if(RetreatFlag == 4)
	{
		SG90_U1SetAngleLeft_Front(45);
		SG90_U3SetAngle_Left_Behind(90);
		SG90_U2SetAngleRight_Front(135);
		SG90_U4SetAngleRight_Behind(90);	
		Delay_ms(Speed);
		RetreatFlag++;
	}
	else if(RetreatFlag == 5)
	{
		SG90_U1SetAngleLeft_Front(90);
		SG90_U3SetAngle_Left_Behind(90);
		SG90_U2SetAngleRight_Front(90);
		SG90_U4SetAngleRight_Behind(90);
		Delay_ms(Speed);		
		RetreatFlag++;
	}
	else if(RetreatFlag == 6)
	{
		SG90_U1SetAngleLeft_Front(135);
		SG90_U3SetAngle_Left_Behind(90);
		SG90_U2SetAngleRight_Front(45);
		SG90_U4SetAngleRight_Behind(90);	
		Delay_ms(Speed);
		RetreatFlag++;
	}
	else if(RetreatFlag == 7)
	{
		SG90_U1SetAngleLeft_Front(135);
		SG90_U3SetAngle_Left_Behind(45);
		SG90_U2SetAngleRight_Front(45);
		SG90_U4SetAngleRight_Behind(135);	
		Delay_ms(Speed);
		RetreatFlag++;
	}
	else if (RetreatFlag == 8)
	{
		SG90_U1SetAngleLeft_Front(90);
		SG90_U3SetAngle_Left_Behind(45);
		SG90_U2SetAngleRight_Front(90);
		SG90_U4SetAngleRight_Behind(135);	
		Delay_ms(Speed);
		RetreatFlag = 1;
	}
}

void SG90_TrunRight(void)		//右转
{
	static uint8_t TrunRightFlag = 1;
	if (TrunRightFlag == 1)
	{
		SG90_U1SetAngleLeft_Front(90);
		SG90_U3SetAngle_Left_Behind(45);
		SG90_U2SetAngleRight_Front(90);
		SG90_U4SetAngleRight_Behind(45);	
		Delay_ms(Speed);
		TrunRightFlag++;
	}
	else if(TrunRightFlag == 2)
	{
		SG90_U1SetAngleLeft_Front(135);
		SG90_U3SetAngle_Left_Behind(45);
		SG90_U2SetAngleRight_Front(135);
		SG90_U4SetAngleRight_Behind(45);	
		Delay_ms(Speed);
		TrunRightFlag++;
	}
	else if(TrunRightFlag == 3)
	{
		SG90_U1SetAngleLeft_Front(135);
		SG90_U3SetAngle_Left_Behind(90);
		SG90_U2SetAngleRight_Front(135);
		SG90_U4SetAngleRight_Behind(90);	
		Delay_ms(Speed);
		TrunRightFlag++;
	}
	else if(TrunRightFlag == 4)
	{
		SG90_U1SetAngleLeft_Front(90);
		SG90_U3SetAngle_Left_Behind(90);
		SG90_U2SetAngleRight_Front(90);
		SG90_U4SetAngleRight_Behind(90);
		Delay_ms(Speed);		
		TrunRightFlag++;
		TrunRightFlag = 1;
	}

}

void SG90_TrunLeft(void)		//左转
{
	static uint8_t TrunLeftFlag = 1;
	if (TrunLeftFlag == 1)
	{
		SG90_U1SetAngleLeft_Front(135);
		SG90_U3SetAngle_Left_Behind(90);
		SG90_U2SetAngleRight_Front(135);
		SG90_U4SetAngleRight_Behind(90);	
		Delay_ms(Speed);
		TrunLeftFlag++;
	}
	else if(TrunLeftFlag == 2)
	{
		SG90_U1SetAngleLeft_Front(135);
		SG90_U3SetAngle_Left_Behind(45);
		SG90_U2SetAngleRight_Front(135);
		SG90_U4SetAngleRight_Behind(45);	
		Delay_ms(Speed);
		TrunLeftFlag++;
	}
	else if(TrunLeftFlag == 3)
	{
		SG90_U1SetAngleLeft_Front(90);
		SG90_U3SetAngle_Left_Behind(45);
		SG90_U2SetAngleRight_Front(90);
		SG90_U4SetAngleRight_Behind(45);	
		Delay_ms(Speed);
		TrunLeftFlag++;
	}
	else if(TrunLeftFlag == 4)
	{
		SG90_U1SetAngleLeft_Front(90);
		SG90_U3SetAngle_Left_Behind(90);
		SG90_U2SetAngleRight_Front(90);
		SG90_U4SetAngleRight_Behind(90);
		Delay_ms(Speed);		
		TrunLeftFlag++;
		TrunLeftFlag = 1;
	}

}

void SG90_CrazyAdvance(void)	//快速前进
{
	static uint8_t AdvanceFlag = 1;
	if (AdvanceFlag == 1)
	{
		SG90_U1SetAngleLeft_Front(90);
		SG90_U3SetAngle_Left_Behind(45);
		SG90_U2SetAngleRight_Front(90);
		SG90_U4SetAngleRight_Behind(135);	
		Delay_ms(Crazy_Speed);
		AdvanceFlag++;
	}
	else if(AdvanceFlag == 2)
	{
		SG90_U1SetAngleLeft_Front(135);
		SG90_U3SetAngle_Left_Behind(45);
		SG90_U2SetAngleRight_Front(45);
		SG90_U4SetAngleRight_Behind(135);	
		Delay_ms(Crazy_Speed);
		AdvanceFlag++;
	}
	else if(AdvanceFlag == 3)
	{
		SG90_U1SetAngleLeft_Front(135);
		SG90_U3SetAngle_Left_Behind(90);
		SG90_U2SetAngleRight_Front(45);
		SG90_U4SetAngleRight_Behind(90);	
		Delay_ms(Crazy_Speed);
		AdvanceFlag++;
	}
	else if(AdvanceFlag == 4)
	{
		SG90_U1SetAngleLeft_Front(90);
		SG90_U3SetAngle_Left_Behind(90);
		SG90_U2SetAngleRight_Front(90);
		SG90_U4SetAngleRight_Behind(90);
		Delay_ms(Crazy_Speed);		
		AdvanceFlag++;
	}
	else if(AdvanceFlag == 5)
	{
		SG90_U1SetAngleLeft_Front(45);
		SG90_U3SetAngle_Left_Behind(90);
		SG90_U2SetAngleRight_Front(135);
		SG90_U4SetAngleRight_Behind(90);	
		Delay_ms(Crazy_Speed);
		AdvanceFlag++;
	}
	else if(AdvanceFlag == 6)
	{
		SG90_U1SetAngleLeft_Front(45);
		SG90_U3SetAngle_Left_Behind(135);
		SG90_U2SetAngleRight_Front(135);
		SG90_U4SetAngleRight_Behind(45);	
		Delay_ms(Crazy_Speed);
		AdvanceFlag++;
	}
	else if(AdvanceFlag == 7)
	{
		SG90_U1SetAngleLeft_Front(90);
		SG90_U3SetAngle_Left_Behind(135);
		SG90_U2SetAngleRight_Front(90);
		SG90_U4SetAngleRight_Behind(45);	
		Delay_ms(Crazy_Speed);
		AdvanceFlag++;
	}
	else if(AdvanceFlag == 8)
	{
		SG90_U1SetAngleLeft_Front(90);
		SG90_U3SetAngle_Left_Behind(90);
		SG90_U2SetAngleRight_Front(90);
		SG90_U4SetAngleRight_Behind(90);	
		Delay_ms(Crazy_Speed);
		AdvanceFlag = 1;
	}

}

void SG90_CrazyRetreat(void)	//快速后退
{
	static uint8_t RetreatFlag = 1;
	if(RetreatFlag == 1)
	{
		SG90_U1SetAngleLeft_Front(90);
		SG90_U3SetAngle_Left_Behind(90);
		SG90_U2SetAngleRight_Front(90);
		SG90_U4SetAngleRight_Behind(90);	
		Delay_ms(Crazy_Speed);
		RetreatFlag++;
	}	
	else if(RetreatFlag == 2)
	{
		SG90_U1SetAngleLeft_Front(90);
		SG90_U3SetAngle_Left_Behind(135);
		SG90_U2SetAngleRight_Front(90);
		SG90_U4SetAngleRight_Behind(45);	
		Delay_ms(Crazy_Speed);
		RetreatFlag++;
	}
	else if(RetreatFlag == 3)
	{
		SG90_U1SetAngleLeft_Front(45);
		SG90_U3SetAngle_Left_Behind(135);
		SG90_U2SetAngleRight_Front(135);
		SG90_U4SetAngleRight_Behind(45);	
		Delay_ms(Crazy_Speed);
		RetreatFlag++;
	}
	else if(RetreatFlag == 4)
	{
		SG90_U1SetAngleLeft_Front(45);
		SG90_U3SetAngle_Left_Behind(90);
		SG90_U2SetAngleRight_Front(135);
		SG90_U4SetAngleRight_Behind(90);	
		Delay_ms(Crazy_Speed);
		RetreatFlag++;
	}
	else if(RetreatFlag == 5)
	{
		SG90_U1SetAngleLeft_Front(90);
		SG90_U3SetAngle_Left_Behind(90);
		SG90_U2SetAngleRight_Front(90);
		SG90_U4SetAngleRight_Behind(90);
		Delay_ms(Crazy_Speed);		
		RetreatFlag++;
	}
	else if(RetreatFlag == 6)
	{
		SG90_U1SetAngleLeft_Front(135);
		SG90_U3SetAngle_Left_Behind(90);
		SG90_U2SetAngleRight_Front(45);
		SG90_U4SetAngleRight_Behind(90);	
		Delay_ms(Crazy_Speed);
		RetreatFlag++;
	}
	else if(RetreatFlag == 7)
	{
		SG90_U1SetAngleLeft_Front(135);
		SG90_U3SetAngle_Left_Behind(45);
		SG90_U2SetAngleRight_Front(45);
		SG90_U4SetAngleRight_Behind(135);	
		Delay_ms(Crazy_Speed);
		RetreatFlag++;
	}
	else if (RetreatFlag == 8)
	{
		SG90_U1SetAngleLeft_Front(90);
		SG90_U3SetAngle_Left_Behind(45);
		SG90_U2SetAngleRight_Front(90);
		SG90_U4SetAngleRight_Behind(135);	
		Delay_ms(Crazy_Speed);
		RetreatFlag = 1;
	}
}

void SG90_CrazyTrunRight(void)	//快速右转
{
	static uint8_t TrunRightFlag = 1;
	if (TrunRightFlag == 1)
	{
		SG90_U1SetAngleLeft_Front(90);
		SG90_U3SetAngle_Left_Behind(45);
		SG90_U2SetAngleRight_Front(90);
		SG90_U4SetAngleRight_Behind(45);	
		Delay_ms(Crazy_Speed);
		TrunRightFlag++;
	}
	else if(TrunRightFlag == 2)
	{
		SG90_U1SetAngleLeft_Front(135);
		SG90_U3SetAngle_Left_Behind(45);
		SG90_U2SetAngleRight_Front(135);
		SG90_U4SetAngleRight_Behind(45);	
		Delay_ms(Crazy_Speed);
		TrunRightFlag++;
	}
	else if(TrunRightFlag == 3)
	{
		SG90_U1SetAngleLeft_Front(135);
		SG90_U3SetAngle_Left_Behind(90);
		SG90_U2SetAngleRight_Front(135);
		SG90_U4SetAngleRight_Behind(90);	
		Delay_ms(Crazy_Speed);
		TrunRightFlag++;
	}
	else if(TrunRightFlag == 4)
	{
		SG90_U1SetAngleLeft_Front(90);
		SG90_U3SetAngle_Left_Behind(90);
		SG90_U2SetAngleRight_Front(90);
		SG90_U4SetAngleRight_Behind(90);
		Delay_ms(Crazy_Speed);		
		TrunRightFlag++;
		TrunRightFlag = 1;
	}

}

void SG90_CrazyTrunLeft(void)	//快速左转
{
	static uint8_t TrunLeftFlag = 1;
	if (TrunLeftFlag == 1)
	{
		SG90_U1SetAngleLeft_Front(135);
		SG90_U3SetAngle_Left_Behind(90);
		SG90_U2SetAngleRight_Front(135);
		SG90_U4SetAngleRight_Behind(90);	
		Delay_ms(Crazy_Speed);
		TrunLeftFlag++;
	}
	else if(TrunLeftFlag == 2)
	{
		SG90_U1SetAngleLeft_Front(135);
		SG90_U3SetAngle_Left_Behind(45);
		SG90_U2SetAngleRight_Front(135);
		SG90_U4SetAngleRight_Behind(45);	
		Delay_ms(Crazy_Speed);
		TrunLeftFlag++;
	}
	else if(TrunLeftFlag == 3)
	{
		SG90_U1SetAngleLeft_Front(90);
		SG90_U3SetAngle_Left_Behind(45);
		SG90_U2SetAngleRight_Front(90);
		SG90_U4SetAngleRight_Behind(45);	
		Delay_ms(Crazy_Speed);
		TrunLeftFlag++;
	}
	else if(TrunLeftFlag == 4)
	{
		SG90_U1SetAngleLeft_Front(90);
		SG90_U3SetAngle_Left_Behind(90);
		SG90_U2SetAngleRight_Front(90);
		SG90_U4SetAngleRight_Behind(90);
		Delay_ms(Crazy_Speed);		
		TrunLeftFlag++;
		TrunLeftFlag = 1;
	}

}

void SG90_Down(void)			//趴下
{
	SG90_U1SetAngleLeft_Front(0);
	SG90_U3SetAngle_Left_Behind(180);
	SG90_U2SetAngleRight_Front(0);
	SG90_U4SetAngleRight_Behind(180);	
	Delay_ms(Crazy_Speed);
}

void SG90_Up(void)				//立正
{
	SG90_U1SetAngleLeft_Front(90);
	SG90_U3SetAngle_Left_Behind(90);
	SG90_U2SetAngleRight_Front(90);
	SG90_U4SetAngleRight_Behind(90);	
	Delay_ms(Crazy_Speed);
}

void SG90_Hard(void)			//握手
{
	static uint8_t HardFlag = 1;
	if (HardFlag == 1)
	{
		SG90_U1SetAngleLeft_Front(0);
		SG90_U3SetAngle_Left_Behind(90);
		SG90_U2SetAngleRight_Front(90);
		SG90_U4SetAngleRight_Behind(90);	
		Delay_ms(250);
		HardFlag++;
	}
	else if(HardFlag == 2)
	{
		SG90_U1SetAngleLeft_Front(45);
		SG90_U3SetAngle_Left_Behind(90);
		SG90_U2SetAngleRight_Front(90);
		SG90_U4SetAngleRight_Behind(90);	
		Delay_ms(250);
		HardFlag = 1;
	}
}

void SG90_Rock(void)			//摇摆
{
	static uint8_t RockFlag = 1;
	if (RockFlag == 1)
	{
		SG90_U1SetAngleLeft_Front(50);
		SG90_U3SetAngle_Left_Behind(50);
		SG90_U2SetAngleRight_Front(130);
		SG90_U4SetAngleRight_Behind(130);	
		Delay_ms(350);
		RockFlag++;
	}
	else if(RockFlag == 2)
	{
		SG90_U1SetAngleLeft_Front(130);
		SG90_U3SetAngle_Left_Behind(130);
		SG90_U2SetAngleRight_Front(50);
		SG90_U4SetAngleRight_Behind(50);	
		Delay_ms(350);
		RockFlag = 1;
	}
}

void SG90_Sit(void)				//坐下
{
	SG90_U1SetAngleLeft_Front(90);
	SG90_U3SetAngle_Left_Behind(30);
	SG90_U2SetAngleRight_Front(150);
	SG90_U4SetAngleRight_Behind(90);	
	Delay_ms(Crazy_Speed);
}

void SG90_SitHard(void)			//坐下握手
{
	static uint8_t Flag = 1;
	if (Flag == 1)
	{
		SG90_U1SetAngleLeft_Front(0);
		SG90_U3SetAngle_Left_Behind(30);
		SG90_U2SetAngleRight_Front(150);
		SG90_U4SetAngleRight_Behind(90);	
		Delay_ms(250);
		Flag++;
	}
	else if(Flag == 2)
	{
		SG90_U1SetAngleLeft_Front(45);
		SG90_U3SetAngle_Left_Behind(30);
		SG90_U2SetAngleRight_Front(150);
		SG90_U4SetAngleRight_Behind(90);		
		Delay_ms(250);
		Flag = 1;
	}
}

void SG90_Ass(void)				//撅屁股
{
	SG90_U1SetAngleLeft_Front(10);
	SG90_U3SetAngle_Left_Behind(80);
	SG90_U2SetAngleRight_Front(100);
	SG90_U4SetAngleRight_Behind(170);	
	Delay_ms(250);
}


