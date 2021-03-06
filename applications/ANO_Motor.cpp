/******************** (C) COPYRIGHT 2014 ANO Tech ***************************
 * 作者		 ：匿名科创
 * 文件名  ：ANO_Motor.cpp
 * 描述    ：电机控制相关函数
 * 官网    ：www.anotc.com
 * 淘宝    ：anotc.taobao.com
 * 技术Q群 ：190169595
**********************************************************************************/
#include "ANO_Motor.h"

ANO_Motor motor;

void ANO_Motor::writeMotor(uint16_t throttle, int32_t pidTermRoll, int32_t pidTermPitch, int32_t pidTermYaw)
{
#if 0	//HEX6+
	motorPWM[0] = throttle - 0.866 * pidTermRoll + 0.5 *  pidTermPitch + pidTermYaw; //后右
	motorPWM[1] = throttle - 0.866 * pidTermRoll - 0.5 *  pidTermPitch - pidTermYaw; //前右+
	motorPWM[2] = throttle + 0.866 * pidTermRoll + 0.5 *  pidTermPitch + pidTermYaw; //后左
	motorPWM[3] = throttle + 0.866 * pidTermRoll - 0.5 *  pidTermPitch - pidTermYaw; //前左-
	motorPWM[4] = throttle + 0                   -pidTermPitch				 + pidTermYaw;	//前
	motorPWM[5] = throttle + 0 									 +pidTermPitch				 - pidTermYaw;	//后

#else //HEX6X
	motorPWM[0] = throttle - 0.866 * pidTermRoll + 0.5 *  pidTermPitch - pidTermYaw; //后右
	motorPWM[1] = throttle - 0.866 * pidTermRoll - 0.5 *  pidTermPitch + pidTermYaw; //前右
	motorPWM[2] = throttle + 0.866 * pidTermRoll + 0.5 *  pidTermPitch - pidTermYaw; //后左
	motorPWM[3] = throttle + 0.866 * pidTermRoll - 0.5 *  pidTermPitch + pidTermYaw; //前左
	motorPWM[4] = throttle + 0                   -pidTermPitch				 - pidTermYaw;	//前
	motorPWM[5] = throttle + 0 									 +pidTermPitch				 + pidTermYaw;	//后
#endif	
	
	for (u8 i = 0; i < 6; i++) 
		motorPWM[i] = constrain_uint16(motorPWM[i], MINTHROTTLE, MAXTHROTTLE);

	//如果未解锁，则将电机输出设置为最低
	if(!ano.f.ARMED || rc.rawData[THROTTLE] < 1150)	
		for(u8 i=0; i< 6 ; i++)
			motorPWM[i] = 1000;

	//写入电机PWM
	pwm.SetPwm(motorPWM);
	
}

void ANO_Motor::getPWM(uint16_t* pwm)
{
	*(pwm) = motorPWM[0];
	*(pwm+1) = motorPWM[1];
	*(pwm+2) = motorPWM[2];
	*(pwm+3) = motorPWM[3];
	*(pwm+4) = motorPWM[4];
	*(pwm+5) = motorPWM[5];	
}




/******************* (C) COPYRIGHT 2014 ANO TECH *****END OF FILE************/
