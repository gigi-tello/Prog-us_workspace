/**
  ******************************************************************************
  * @file    API_debounce.h
  * @author  Giselle Tello de Meneses
  * @brief   Este archivo contiene los prototipos y las funciones para
  * hacer el debounce del botón de la placa NUCLEO-F439ZI
  ******************************************************************************
  **/

//Declaraciones de variables
#include <stdint.h>
#include "stm32f4xx_nucleo_144.h"

#define BUTTON_PRESSED 1
#define BUTTON_NOT_PRESSED 0

//Prototipos de funciones
typedef enum{
	BUTTON_UP,
	BUTTON_FALLING,
	BUTTON_DOWN,
	BUTTON_RISING,
} debounceState_t;

void debounceFSM_init(debounceState_t* debounceState);		// Inicializa el debounce
void debounceFSM_update(debounceState_t* debounceState);	// Lee el estado, resuelve la lógica de transición de estados y actualiza las salidas
