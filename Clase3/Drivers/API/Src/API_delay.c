#include "API_delay.h"
#include "stm32f4xx_nucleo_144.h"   /* <- BSP include */

/*
 * Carga el valor de duración del retardo en la estructura delay
 * Inicializa delay.running en false
 * */
void delayInit( delay_t * delay, tick_t duration ){
	bool running_init_state = false;

	delayWrite(delay, duration);
	delay->running = running_init_state;
}

/*
 * Verifica el estado del flag running y devuelve un valor booleano que indica
 * si el tiempo se cumplió o no.
 * 	false: toma la marca de tiempo y cambia running a ‘true’
 * 	true: hacer la cuenta para saber si el tiempo del retardo se cumplió o no*/
bool_t delayRead( delay_t * delay ){
	if(delay->running){
		if ((HAL_GetTick() - delay->startTime) >= delay->duration){
			delay->running = false;
			return true;
		}
	} else {
		delay->startTime = HAL_GetTick();
		delay->running = true;
	}
	return false;
}

/*Permite cambiar el tiempo de duración de un delay existente*/
void delayWrite( delay_t * delay, tick_t duration ){
	delay->duration = duration;
}
