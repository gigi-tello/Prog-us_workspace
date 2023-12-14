/**
  ******************************************************************************
  * @file    API_rtc.c
  * @author  Giselle Tello de Meneses
  * @brief   Biblioteca para manejar el RTC DS3231.
  * El integrado se comunica por I2C y, además de la fecha y hora, cuenta con un
  * sensor de temperatura.
  ******************************************************************************
  **/

#include "API_rtc.h"

// Convierte de decimal a bcd
uint8_t dec2bcd(int val){
  return (uint8_t)( (val/10*16) + (val%10) );
}
// Convierte de bcd a decimal
// Multiplica al nibble alto por 10, y le suma el nibble bajo
static uint8_t bcd2dec(uint8_t bcd){
  int dec = ((bcd & 0xF0) >> 4) * 10 + (bcd & 0x0F);
  return dec;
}

dateTime_t leer_fecha_hora(void){
	dateTime_t dato;
	uint8_t dato_leido[7];
	HAL_I2C_Mem_Read(&hi2c1, RTC_ADDR, MEM_REG, 1, dato_leido, CANT_REG_FH, RTC_TIMEOUT);

	dato.seg = bcd2dec(dato_leido[0]);
	dato.min = bcd2dec(dato_leido[1]);
	dato.hora = bcd2dec(dato_leido[2]);
	//dato_leido[3] corresponde al día de la semana
	dato.dia = bcd2dec(dato_leido[4]);
	dato.mes = bcd2dec(dato_leido[5]);
	dato.anio = bcd2dec(dato_leido[6]);

	return dato;
}

/**
 * \brief Genera una cadena para mostrar la fecha.
 *
 * \param char* temp El puntero a la cadena.
 */
void obtener_fecha(char* fecha){

	dateTime_t fecha_hora = leer_fecha_hora();

	sprintf(fecha, FORMATO_FECHA, fecha_hora.dia, fecha_hora.mes, fecha_hora.anio);
	return;
}

/**
 * \brief Genera una cadena para mostrar la hora.
 *
 * \param char* temp El puntero a la cadena.
 */
void obtener_hora(char* hora){
	dateTime_t fecha_hora = leer_fecha_hora();

	sprintf(hora, FORMATO_HORA, fecha_hora.hora, fecha_hora.min);
	return;
}

void ajustar_fecha_hora(uint8_t anio, uint8_t mes, uint8_t dia_semana, uint8_t dia_mes, uint8_t hora, uint8_t min, uint8_t seg){
	uint8_t set_time[7];
	set_time[0] = dec2bcd(seg);
	set_time[1] = dec2bcd(min);
	set_time[2] = dec2bcd(hora);
	set_time[3] = dec2bcd(dia_semana);
	set_time[4] = dec2bcd(dia_mes);
	set_time[5] = dec2bcd(mes);
	set_time[6] = dec2bcd(anio);

	HAL_I2C_Mem_Write(&hi2c1, RTC_ADDR, MEM_REG, 1, set_time, CANT_REG_FH, RTC_TIMEOUT);
}

/**
 * \brief Lee la temperatura del DS3231
 *
 * Lee la temperatura desde los registros 0x11 y 0x12.
 * En 0x11 está la parte entera del valor, y en 0x12 la parte decimal.
 * La resolución es 0.25gC por eso la parte decimal se divide por 4
 *
 * \return La temperatura sensada.
 */
temp_t leer_temp (void){
	uint8_t temp[2];
	HAL_I2C_Mem_Read(&hi2c1, RTC_ADDR, TEMP_REG, 1, temp, CANT_REG_TEMP, RTC_TIMEOUT);

	return ((temp[0])+(temp[1]>>6)*0.25);
}

/**
 * \brief Genera una cadena para mostrar la temperatura.
 *
 * \param char* temp El puntero a la cadena.
 */
void obtener_temp(char* temp){
	temp_t temperatura = leer_temp();

	sprintf(temp, FORMATO_TEMP, temperatura);
	return;
}


