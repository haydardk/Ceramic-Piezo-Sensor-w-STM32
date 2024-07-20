/*
 * Ceramic_Piezo_ADC.c
 *
 *  Created on: Jul 17, 2024
 *      Author: CASPER
 */
#include "Ceramic_Piezo_ADC.h"

extern int veri;
extern uint16_t raw_valueA;
extern uint16_t raw_valueB;
extern float pulse;
extern char piezo_data[20];

void Read_Vibration_A(){
	HAL_ADC_Start(&hadc1);
	ADC_ChannelConfTypeDef sConfig = {0} ;
	sConfig.Channel = ADC_CHANNEL_7;
	sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
	HAL_ADC_Start(&hadc1);

	if( HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY) == HAL_OK ){
		raw_valueA= HAL_ADC_GetValue(&hadc1);
		veri++;
	}
	HAL_ADC_Stop(&hadc1);
	if(raw_valueA > 100000){
		raw_valueA = 200;
	}
	//pulse = pow(2,(raw_valueA));
	pulse = raw_valueA;
}
void Read_Vibration_B(){
	HAL_ADC_Start(&hadc1);
	ADC_ChannelConfTypeDef sConfig = {0} ;
	sConfig.Channel = ADC_CHANNEL_8;
	sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
	HAL_ADC_Start(&hadc1);

	if( HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY) == HAL_OK ){
		raw_valueB= HAL_ADC_GetValue(&hadc1);
		veri++;
	}
	HAL_ADC_Stop(&hadc1);
	if(raw_valueB > 100000){
		raw_valueB = 200;
	}
	//pulse = pow(2,(raw_valueB));
	pulse = raw_valueB;
}
void Check_Pulse(){
	Read_Vibration_A();
	if(pulse > PULSE_THRESHOLD){
	HAL_GPIO_WritePin(PULSE_DETECTION_PORT, PULSE_DETECTION_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
	}else{
	HAL_GPIO_WritePin(PULSE_DETECTION_PORT, PULSE_DETECTION_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
	}
	Read_Vibration_B();
	if(pulse > PULSE_THRESHOLD){
	HAL_GPIO_WritePin(PULSE_DETECTION_PORT, PULSE_DETECTION_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
	}else{
	HAL_GPIO_WritePin(PULSE_DETECTION_PORT, PULSE_DETECTION_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
	}

}


