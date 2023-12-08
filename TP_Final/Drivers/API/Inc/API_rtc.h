#ifndef API_RTC
#define API_RTC

#include "common.h"

extern I2C_HandleTypeDef hi2c1;

#define RTC_ADDR 0xD0
#define MEM_ADDR 0x00
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



dateTime_t leer_fecha_hora (void);
uint8_t* obtener_fecha(void);
uint8_t* obtener_hora(void);
void Set_Time (uint8_t sec, uint8_t min, uint8_t hour, uint8_t dow, uint8_t dom, uint8_t month, uint8_t year);


#endif /*API_RTC*/
