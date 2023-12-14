/**
  ******************************************************************************
  * @file    pantallas.h
  * @author  Giselle Tello de Meneses
  * @brief   Encabezado de la biblioteca con las pantallas a mostrar en el lcd
  ******************************************************************************
  **/

#ifndef PANTALLAS_H
#define PANTALLAS_H

#include "common.h"
#include "API_rtc.h"
#include "API_lcd.h"
#include "API_keypad.h"
#include "API_delay.h"

//Mensajes con las opciones
#define MSJ_MOSTRAR_FECHA "Mostrar fecha"
#define MSJ_MOSTRAR_TEMP "Mostrar temp"
#define CARACTER_CURSOR ">"

//Macros para la opción seleccionada
#define OPCION_MOSTRAR_FECHA 0
#define OPCION_MOSTRAR_TEMP 1

//Macros para las pantallas
#define PANTALLA_OPCIONES 0
#define PANTALLA_FECHA 1
#define PANTALLA_TEMP 2

//Variable con la pantalla a mostrar
extern uint8_t mostrar_pantalla;

void pant_opciones(void);
void pant_fecha(void);
void pant_temp(void);
void pant_fila_cursor(uint8_t);


#endif /*PANTALLAS_H*/
