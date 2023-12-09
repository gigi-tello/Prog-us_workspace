//RTC por I2C. Se alimenta con 3,3 V

#ifndef API_RTC_H
#define API_RTC_H

#include "i2c.h"
#include "common.h"

#define RTC_ADDR 0xD0
#define MEM_REG 0x00
#define TEMP_REG 0x11
#define CANT_REG_FH 7 //Cantidad de registros que ocupan los datos de fecha y hora
#define CANT_REG_TEMP 2 //Cantidad de registros que ocupan los datos de temperatura

#define RTC_TIMEOUT 1000


#define FORMATO_FECHA "%02u/%02u/%2u" // ej: 01/02/23
#define FORMATO_HORA "%02u:%02u" // ej: 01:05
#define FORMATO_TEMP "Temp: %.2f C" // ej: Temp: 25.00 C


#define LARGO_CADENA_FECHA 9
#define LARGO_CADENA_HORA 6
#define LARGO_CADENA_TEMP 15


typedef struct{
	uint8_t anio;
	uint8_t mes;
	uint8_t dia;
	uint8_t hora;
	uint8_t min;
	uint8_t seg;
} dateTime_t;

typedef float temp_t;


dateTime_t leer_fecha_hora (void);
void obtener_fecha(char*);
void obtener_hora(char*);
void obtener_temp(char*);
void ajustar_fecha_hora(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
float leer_temp (void);

#endif /*API_RTC_H*/
