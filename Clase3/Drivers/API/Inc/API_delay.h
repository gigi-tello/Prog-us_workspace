#include <stdint.h>
#include <stdbool.h>
//Variables
typedef uint32_t tick_t; // Biblioteca: <stdint.h>
typedef bool bool_t;	 // Biblioteca: <stdbool.h>
typedef struct{
   tick_t startTime;
   tick_t duration;
   bool_t running;
} delay_t;

//Funciones
void delayInit( delay_t * delay, tick_t duration );
bool_t delayRead( delay_t * delay );
void delayWrite( delay_t * delay, tick_t duration );
