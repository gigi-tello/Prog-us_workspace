//RTC por I2C. Se alimenta con 3,3 V

#ifndef API_RTC
#define API_RTC

#include "common.h"


#define RTC_ADDR 0xD0
#define MEM_REG 0x00
#define TEMP_REG 0x11
#define CANT_REG_FH 7 //Cantidad de registros que ocupan los datos de fecha y hora
#define CANT_REG_TEMP 2 //Cantidad de registros que ocupan los datos de temperatura

#define RTC_TIMEOUT 1000


#define FORMATO_FECHA "%02u/%02u/%4u" // ej: 01/02/2023
#define FORMATO_HORA "%02u:%02u" // ej: 01:05

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
uint8_t* obtener_fecha(void);
uint8_t* obtener_hora(void);
void ajustar_fecha_hora(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
float leer_temp (void);

#endif /*API_RTC*/
