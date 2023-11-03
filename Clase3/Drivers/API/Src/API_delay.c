#include "API_delay.h"
#include "stm32f4xx_nucleo_144.h"   /* <- BSP include */

void delayInit( delay_t * delay, tick_t duration ){
	bool running_init_state = false;

	delayWrite(delay, duration);
	delay->running = running_init_state;
}

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

void delayWrite( delay_t * delay, tick_t duration ){
	delay->duration = duration;
}
