/**
  ******************************************************************************
  * @file    API_debounce.c
  * @author  Giselle Tello de Meneses
  * @brief   Este archivo contiene las funciones para
  * hacer el debounce del botón de la placa NUCLEO-F439ZI
  ******************************************************************************
  **/


#include "API_debounce.h"

/*
* @brief Inicializa el debounce
* * @retval void
* * @param debounceState puntero a debounceState_t
*/
void debounceFSM_init(debounceState_t* debounceState){
	*debounceState = BUTTON_UP;
}

/*
* @brief This function handles Memory management fault.
* * @retval void
* * @param debounceState puntero a debounceState_t
*/
void debounceFSM_update(debounceState_t* debounceState){
	uint16_t buttonState = BSP_PB_GetState(BUTTON_USER);

	switch(*debounceState){
	case BUTTON_UP:
		if(buttonState == BUTTON_PRESSED){
			*debounceState = BUTTON_FALLING;
		}
		break;
	case BUTTON_FALLING:
		if(buttonState == BUTTON_PRESSED){
			*debounceState = BUTTON_DOWN;
		}else if(buttonState == BUTTON_NOT_PRESSED){
			*debounceState = BUTTON_UP;
		}
		break;
	case BUTTON_DOWN:
		if(buttonState == BUTTON_NOT_PRESSED){
			*debounceState = BUTTON_RISING;
		}
		break;
	case BUTTON_RISING:
		if(buttonState == BUTTON_NOT_PRESSED){
			*debounceState = BUTTON_UP;
		}else if(buttonState == BUTTON_PRESSED){
			*debounceState = BUTTON_DOWN;
		}
		break;
	default:
		debounceFSM_init(debounceState);
		break;
	}
}
