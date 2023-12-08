#include "API_rtc.h"

// Convert normal decimal numbers to binary coded decimal
uint8_t dec2bcd(int val)
{
  return (uint8_t)( (val/10*16) + (val%10) );
}
// Convert binary coded decimal to normal decimal numbers
// Multiplica al nibble alto por 10, y le suma el nibble bajo
static uint8_t bcd2dec(uint8_t bcd)
{
  int dec = ((bcd & 0xF0) >> 4) * 10 + (bcd & 0x0F);
  return dec;
}

dateTime_t leer_fecha_hora(void){
	dateTime_t dato;
	uint8_t dato_leido[7];
	HAL_I2C_Mem_Read(&hi2c1, RTC_ADDR, MEM_ADDR, 1, dato_leido, 7, RTC_TIMEOUT);

	dato.seg = bcd2dec(dato_leido[0]);
	dato.min = bcd2dec(dato_leido[1]);
	dato.hora = bcd2dec(dato_leido[2]);

	dato.dia = bcd2dec(dato_leido[4]);
	dato.mes = bcd2dec(dato_leido[5]);
	dato.anio = bcd2dec(dato_leido[6]);

	return dato;
}

uint8_t* obtener_fecha(void){
	uint8_t fecha[11];
	dateTime_t fecha_hora = leer_fecha_hora();

	sprintf(fecha, FORMATO_FECHA, fecha_hora.dia, fecha_hora.mes, fecha_hora.anio);
	return &fecha;
}

uint8_t* obtener_hora(void){
	uint8_t hora[6];
	dateTime_t fecha_hora = leer_fecha_hora();

	sprintf(hora, FORMATO_HORA, fecha_hora.hora, fecha_hora.min);
	return *hora;
}

void Set_Time (uint8_t sec, uint8_t min, uint8_t hour, uint8_t dow, uint8_t dom, uint8_t month, uint8_t year)
{
	uint8_t set_time[7];
	set_time[0] = dec2bcd(sec);
	set_time[1] = dec2bcd(min);
	set_time[2] = dec2bcd(hour);
	set_time[3] = dec2bcd(dow);
	set_time[4] = dec2bcd(dom);
	set_time[5] = dec2bcd(month);
	set_time[6] = dec2bcd(year);

	HAL_I2C_Mem_Write(&hi2c1, RTC_ADDR, 0x00, 1, set_time, 7, 1000);
}
