
#ifndef __BOARD_H__
#define __BOARD_H__

#include "stm32f10x.h"
#include "string.h"
#include "ANO_Math.h"

#define ARMAPI extern "C"

#define ANO_RCC_LED0			RCC_APB2Periph_GPIOC
#define ANO_PORT_LED0		GPIOC
#define ANO_Pin_LED0		GPIO_Pin_13

#define LED0_OFF   ANO_PORT_LED0->BSRR = ANO_Pin_LED0;
#define LED0_ON    ANO_PORT_LED0->BRR  = ANO_Pin_LED0;//SET 0
/***************I2C GPIO定义******************/
#define ANO_GPIO_I2C	GPIOB
#define I2C_Pin_SCL		GPIO_Pin_11
#define I2C_Pin_SDA		GPIO_Pin_10
#define ANO_RCC_I2C		RCC_APB2Periph_GPIOB
/*********************************************/
/***************SPI2 GPIO定义******************/
#define ANO_GPIO_SPI2		GPIOB
#define ANO_GPIO_CE2		GPIOA
#define ANO_GPIO_CSN		GPIOA
#define SPI2_Pin_SCK		GPIO_Pin_13
#define SPI2_Pin_MISO		GPIO_Pin_14
#define SPI2_Pin_MOSI		GPIO_Pin_15
#define SPI2_Pin_CE2		GPIO_Pin_10
#define SPI2_Pin_CSN		GPIO_Pin_9
#define RCC_GPIO_SPI2		RCC_APB2Periph_GPIOB
#define RCC_GPIO_CE2		RCC_APB2Periph_GPIOA
/*********************************************/

/***************硬件中断优先级******************/
#define NVIC_UART_P	5
#define NVIC_UART_S	1
/***********************************************/

#include "ANO_Config.h"
#include "ANO_Drv_SPI2.h"
#include "ANO_Drv_I2C_soft.h"
#include "ANO_Drv_MPU6050.h"
#include "ANO_Drv_Nrf24l01.h"
#include "ANO_Drv_PWM.h"
#include "ANO_Drv_EEPROM.h"

void ANO_Quadcopter_board_Init(void);
void SysTick_IRQ(void);
uint32_t GetSysTime_us(void);


#endif /* __BOARD_H__ */

// 




