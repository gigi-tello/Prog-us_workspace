#include "API_adc.h"

uint32_t leer_adc(void){
	// ADC_HandleTypeDef hadc;
	uint32_t valor = 0;

	HAL_ADC_Start(&hadc1);
	if (HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY) == HAL_OK){
		valor = HAL_ADC_GetValue(&hadc1);
	}
	HAL_ADC_Stop(&hadc1);

	return valor;
}
