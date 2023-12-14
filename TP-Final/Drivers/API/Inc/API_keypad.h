/**
  ******************************************************************************
  * @file    API_keypad.h
  * @author  Giselle Tello de Meneses
  * @brief   Encabezado de la biblioteca para manejar el keypad del shield.
  * El keypad es un arreglo de botones que forman un divisor resistivo entre
  * 5 V y GND, y el valor resultante se puede leer con una entrada analógica.
  ******************************************************************************
  **/

#ifndef API_KEYPAD_H
#define API_KEYPAD_H

#include "common.h"
#include "API_adc.h"
#include "API_delay.h"

//Macros para los botones
#define BOT_ADELANTE 1
#define BOT_ARRIBA 2
#define BOT_ABAJO 3
#define BOT_ATRAS 4
#define BOT_NINGUNO 0

//Valores de detección con el ADC en 10 bit
#define LIMITE_BOT_ADELANTE 50
#define LIMITE_BOT_ARRIBA 250
#define LIMITE_BOT_ABAJO 500
#define LIMITE_BOT_ATRAS 790

//Cadenas para str_boton(uint8_t boton).
//Se comentó el \n\r para enviarlas al lcd
#define STR_ADELANTE (uint8_t *)"Boton adelante"//\n\r";
#define STR_ARRIBA  (uint8_t *)"Boton arriba"//\n\r";
#define STR_ABAJO (uint8_t *)"Boton abajo"//\n\r";
#define STR_ATRAS (uint8_t *)"Boton atras"//\n\r";
#define STR_NINGUNO (uint8_t *)"Ningun boton"//\n\r";

uint8_t obtener_boton_presionado();
uint8_t * str_boton(uint8_t boton);

#endif /*API_KEYPAD_H*/
