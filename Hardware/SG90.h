#ifndef __SG90_H
#define __SG90_H

#include "PWM.h"

void SG90_Init(void);		//舵机初始化
void SG90_Advance(void);	//前进
void SG90_Retreat(void);	//后退
void SG90_TrunRight(void);	//右转
void SG90_TrunLeft(void);	//左转
void SG90_CrazyAdvance(void);		//快速前进
void SG90_CrazyRetreat(void);		//快速后退
void SG90_CrazyTrunRight(void);		//快速右转
void SG90_CrazyTrunLeft(void);		//快速左转
void SG90_Down(void);		//趴下
void SG90_Up(void);			//立正
void SG90_Hard(void);		//握手
void SG90_Rock(void);		//摇摆
void SG90_Sit(void);		//坐下
void SG90_SitHard(void);	//坐下握手
void SG90_Ass(void);		//撅屁股
#endif
