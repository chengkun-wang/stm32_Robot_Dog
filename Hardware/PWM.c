#include "stm32f10x.h"                  // Device header

void PWM_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	TIM_InternalClockConfig(TIM2);//定时器2初始化
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 2000-1;
	TIM_TimeBaseInitStructure.TIM_Prescaler = 720-1;
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);
	
	TIM_OCInitTypeDef TIM_OCInitTypeDefStructure1; 
	TIM_OCStructInit(&TIM_OCInitTypeDefStructure1);
	TIM_OCInitTypeDefStructure1.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitTypeDefStructure1.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitTypeDefStructure1.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitTypeDefStructure1.TIM_Pulse = 0;
	TIM_OC1Init(TIM2,&TIM_OCInitTypeDefStructure1);	
	
	TIM_OCInitTypeDef TIM_OCInitTypeDefStructure2;
	TIM_OCStructInit(&TIM_OCInitTypeDefStructure2);
	TIM_OCInitTypeDefStructure2.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitTypeDefStructure2.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitTypeDefStructure2.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitTypeDefStructure2.TIM_Pulse = 0;
	TIM_OC2Init(TIM2,&TIM_OCInitTypeDefStructure2);
	
	
	TIM_OCInitTypeDef TIM_OCInitTypeDefStructure3;
	TIM_OCStructInit(&TIM_OCInitTypeDefStructure3);
	TIM_OCInitTypeDefStructure3.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitTypeDefStructure3.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitTypeDefStructure3.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitTypeDefStructure3.TIM_Pulse = 0;
	TIM_OC3Init(TIM2,&TIM_OCInitTypeDefStructure3);	
	
	
	TIM_OCInitTypeDef TIM_OCInitTypeDefStructure4;
	TIM_OCStructInit(&TIM_OCInitTypeDefStructure4);
	TIM_OCInitTypeDefStructure4.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitTypeDefStructure4.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitTypeDefStructure4.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitTypeDefStructure4.TIM_Pulse = 0;
	TIM_OC4Init(TIM2,&TIM_OCInitTypeDefStructure4);		
	
	TIM_Cmd(TIM2,ENABLE);
}

void PWM_SetCompare1(uint16_t Compare)
{
	TIM_SetCompare1(TIM2, Compare);		//设置CCR1的值
}

void PWM_SetCompare2(uint16_t Compare)
{
	TIM_SetCompare2(TIM2, Compare);		//设置CCR2的值
}

void PWM_SetCompare3(uint16_t Compare)
{
	TIM_SetCompare3(TIM2, Compare);		//设置CCR3的值
}

void PWM_SetCompare4(uint16_t Compare)
{
	TIM_SetCompare4(TIM2, Compare);		//设置CCR4的值
}
