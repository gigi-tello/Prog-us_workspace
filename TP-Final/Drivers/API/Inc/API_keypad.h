#ifndef API_KEYPAD_H
#define API_KEYPAD_H

#include "common.h"
#include "API_adc.h"

#define BOT_ADELANTE 1
#define BOT_ARRIBA 2
#define BOT_ABAJO 3
#define BOT_ATRAS 4
#define BOT_NINGUNO 0

#define STR_ADELANTE (uint8_t *)"Boton adelante"//\n\r";
#define STR_ARRIBA  (uint8_t *)"Boton arriba"//\n\r";
#define STR_ABAJO (uint8_t *)"Boton abajo"//\n\r";
#define STR_ATRAS (uint8_t *)"Boton atras"//\n\r";
#define STR_NINGUNO (uint8_t *)"Ningun boton"//\n\r";

uint8_t obtener_boton_presionado();
uint8_t * str_boton(uint8_t boton);

#endif /*API_KEYPAD_H*/
