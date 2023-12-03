#include "API_adc.h"

uint32_t leer_adc(ADC_HandleTypeDef hadc){
	uint32_t valor = 0;

	HAL_ADC_Start(&hadc);
	if (HAL_ADC_PollForConversion(&hadc, HAL_MAX_DELAY) == HAL_OK){
		valor = HAL_ADC_GetValue(&hadc);
	}
	HAL_ADC_Stop(&hadc);

	return valor;
}
