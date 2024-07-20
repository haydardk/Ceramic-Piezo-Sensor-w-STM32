/*
 * Ceramic_Piezo_ADC.h
 *
 *  Created on: Jul 17, 2024
 *      Author: CASPER
 */

#ifndef INC_CERAMIC_PIEZO_ADC_H_
#define INC_CERAMIC_PIEZO_ADC_H_


#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"

#define PULSE_THRESHOLD 200
#define PULSE_DETECTION_PORT GPIOB
#define PULSE_DETECTION_PIN GPIO_PIN_1

extern ADC_HandleTypeDef hadc1;

void Read_Vibration_A();
void Read_Vibration_B();
void Check_Pulse();

#endif /* INC_CERAMIC_PIEZO_ADC_H_ */
