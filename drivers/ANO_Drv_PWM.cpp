/******************** (C) COPYRIGHT 2014 ANO Tech ***************************
 * ����		 �������ƴ�
 * �ļ���  ��ANO_Drv_PWM.cpp
 * ����    ��PWM��ض�ʱ��
 * ����    ��www.anotc.com
 * �Ա�    ��anotc.taobao.com
 * ����QȺ ��190169595
**********************************************************************************/
#include "ANO_Drv_PWM.h"

ANO_PWM pwm;

void ANO_PWM::out_Init(uint16_t hz)
{
	#if 1
	TIM_TimeBaseInitTypeDef		TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  				TIM_OCInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA| RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO,ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	uint16_t PrescalerValue = 0;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	/* Compute the prescaler value */
	PrescalerValue = (uint16_t) (SystemCoreClock / (hz*1000)) - 1;
	/* Time base configuration */
	TIM_TimeBaseStructure.TIM_Period = 999;		//
	TIM_TimeBaseStructure.TIM_Prescaler = PrescalerValue;	//pwmʱ�ӷ�Ƶ
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;	
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;		//���ϼ���
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	
	/* PWM1 Mode configuration: Channel */
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;//��ʼռ�ձ�Ϊ0
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
	TIM_ARRPreloadConfig(TIM3, ENABLE);
	TIM_Cmd(TIM3, ENABLE);
		
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	PrescalerValue = (uint16_t) (SystemCoreClock / 24000000) - 1;
	/* Time base configuration */
	TIM_TimeBaseStructure.TIM_Period = 999;		//��������	
	TIM_TimeBaseStructure.TIM_Prescaler = PrescalerValue;	//pwmʱ�ӷ�Ƶ
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;	
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;		//���ϼ���
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
	
	/* PWM1 Mode configuration: Channel */
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
   
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
  TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
  TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
  TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Set;
	
	TIM_OCInitStructure.TIM_Pulse = 0;//��ʼռ�ձ�Ϊ0

	

	
	TIM_OC4Init(TIM1, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable);	

	

	TIM_OC1Init(TIM1, &TIM_OCInitStructure);
  TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);
	
	TIM_ARRPreloadConfig(TIM1, ENABLE);
	
	TIM_Cmd(TIM1, ENABLE);	
	  /* TIM1 Main Output Enable */
  TIM_CtrlPWMOutputs(TIM1, ENABLE);

//  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
//  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//  //TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
//  TIM_OCInitStructure.TIM_Pulse = 0;
//  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
//  TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
// // TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
// // TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCIdleState_Reset;

//  TIM_OC1Init(TIM1, &TIM_OCInitStructure);
//	TIM_OC4Init(TIM1, &TIM_OCInitStructure);

//  /* TIM1 counter enable */
//  TIM_Cmd(TIM1, ENABLE);

//  /* TIM1 Main Output Enable */
//  TIM_CtrlPWMOutputs(TIM1, ENABLE);
#endif

#if 0
GPIO_InitTypeDef GPIO_InitStructure;
  TIM_TimeBaseInitTypeDef		TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  				TIM_OCInitStructure;	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO,ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;  //TIM3->CH1?��TIM3->CH2
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;  //TIM3->CH3?��TIM3->CH4
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_11;  //TIM1->CH1?��TIM1->CH4
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	

	/* Time base configuration */	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3 , ENABLE);
	TIM_TimeBaseStructure.TIM_Period = 1000;		
	TIM_TimeBaseStructure.TIM_Prescaler = 17;	
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;	
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;		//?����???��y
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	TIM_ARRPreloadConfig(TIM3, ENABLE);	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1 , ENABLE);
	TIM_TimeBaseStructure.TIM_Period = 1000;		
	TIM_TimeBaseStructure.TIM_Prescaler = 17;	
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;	
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;		//?����???��y
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
	TIM_ARRPreloadConfig(TIM1, ENABLE);		
	
	/* PWM1 Mode configuration: Channel */
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	
	
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
	TIM_OC1Init(TIM1, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);	
	
	TIM_OC4Init(TIM1, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable);

	TIM_Cmd(TIM3, ENABLE);
	
	TIM_CtrlPWMOutputs(TIM1, ENABLE);
	TIM_Cmd(TIM1, ENABLE);
	
	TIM3->CCR1 = 0;
	TIM3->CCR2 = 0;
	TIM3->CCR3 = 0;
	TIM3->CCR4 = 0;
	
	TIM1->CCR1 = 0;
	TIM1->CCR4 = 0;
#endif
}



void ANO_PWM::SetPwm(uint16_t pwm[MAXMOTORS])
{
	for(u8 i=0;i<MAXMOTORS;i++)
	{
		if(pwm[i] < 1000)
			pwm[i] = 1000;
		else if(pwm[i] > 2000)
			pwm[i] = 2000;
	}
	
	/****************************
	TIM3_CH1:ǰ��
	TIM3_CH2:ǰ
	TIM3_CH3:ǰ��
	TIM3_CH4:����
	TIM1_CH1:��
	TIM1_CH4;����
	*****************************/
//	TIM1->CCR4 = pwm[2] - 1000;//����
//	TIM3->CCR1 = pwm[3] - 1000;//ǰ��
//	TIM3->CCR4 = pwm[0] - 1000;//����
//	TIM3->CCR3 = pwm[1] - 1000;//ǰ��
//	TIM3->CCR2 = pwm[4] - 1000;//ǰ
//	TIM1->CCR1 = pwm[5] - 1000;//��

	
	/****************************
	TIM3_CH1:����
	TIM3_CH2:��
	TIM3_CH3:����
	TIM3_CH4:ǰ��
	TIM1_CH1:ǰ
	TIM1_CH4;ǰ��
	****************************/
	#if 1
	
	TIM3->CCR3 = (pwm[0] - 1000)/1.5;//����
	TIM3->CCR4 = (pwm[1] - 1000)/1.5;//ǰ��	
	TIM3->CCR1 = (pwm[2] - 1000)/1.5;//����	
  TIM1->CCR4 = (pwm[3] - 1000)/1.5;//ǰ��	
	TIM1->CCR1 = (pwm[4] - 1000)/1.5;//ǰ
	TIM3->CCR2 = (pwm[5] - 1000)/1.5;//��

#else
	TIM3->CCR3 = (pwm[0] - 1000);//����
	TIM3->CCR4 = (pwm[1] - 1000);//ǰ��	
	TIM3->CCR1 = (pwm[2] - 1000);//����	
  TIM1->CCR4 = (pwm[3] - 1000);//ǰ��	
	TIM1->CCR1 = (pwm[4] - 1000);//ǰ
	TIM3->CCR2 = (pwm[5] - 1000);//��


#endif

}


/******************* (C) COPYRIGHT 2014 ANO TECH *****END OF FILE************/
