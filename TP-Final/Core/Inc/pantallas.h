#ifndef PANTALLAS_H
#define PANTALLAS_H

#include "common.h"
#include "API_rtc.h"
#include "API_lcd.h"

#define MSJ_MOSTRAR_FECHA "Mostrar fecha"
#define MSJ_MOSTRAR_TEMP "Mostrar temp"
#define CHAR_CURSOR ">"

#define OPCION_MOSTRAR_FECHA 0
#define OPCION_MOSTRAR_TEMP 1

void pag_opciones(void);
void pag_fecha(void);
void pag_temp(void);
void pag_fila_cursor(uint8_t);


#endif /*PANTALLAS_H*/
