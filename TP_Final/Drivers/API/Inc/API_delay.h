#include "common.h"

typedef struct{
   tick_t startTime;	 //Tiempo de inicio del delay
   tick_t duration;		 //Duración en ms del delay
   bool_t running;		 //Estado del delay. 'true' corriendo, 'false' detenido
} delay_t;

//Prototipos de funciones
void delayInit( delay_t * delay, tick_t duration );
bool_t delayRead( delay_t * delay );
void delayWrite( delay_t * delay, tick_t duration );
