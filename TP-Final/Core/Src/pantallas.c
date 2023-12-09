#include "pantallas.h"

void pag_opciones(void){
    /*
    |>Mostrar fecha  |
    | Mostrar temp   |
    */

	lcd_borrar();
	lcd_pos_cursor(0, 1);
    lcd_enviar_cadena(MSJ_MOSTRAR_FECHA);
    lcd_pos_cursor(1, 1);
    lcd_enviar_cadena(MSJ_MOSTRAR_TEMP);
}

void pag_fila_cursor(uint8_t opcion){
    switch (opcion){
        case OPCION_MOSTRAR_FECHA:
        	lcd_pos_cursor(0, 0);
            break;
        case OPCION_MOSTRAR_TEMP:
        	lcd_pos_cursor(1, 0);
            break;
    }
    lcd_enviar_cadena(CHAR_CURSOR);
}

void pag_fecha(void){
    /*
    |   dd/mm/aaaa   |
    |     hh:mm      |
    */

	char fecha[LARGO_CADENA_FECHA] = "";
	char hora[LARGO_CADENA_HORA] =  "";

	obtener_fecha(fecha);
	obtener_hora(hora);

    lcd_borrar();
    lcd_pos_cursor(0, 4);
    lcd_enviar_cadena(fecha);

    lcd_pos_cursor(1, 5);
    lcd_enviar_cadena(hora);


}

void pag_temp(void){
    /*
    |   Temp: tt C   |
    |                |
    */
    char cad_temperatura[LARGO_CADENA_TEMP] = "";


    obtener_temp(cad_temperatura);
    //sprintf(cad_temperatura,"Temp: %d \004C", temperatura_ext); // \004 está definido en caracteres.h para el símbolo de grado

    lcd_borrar();
    lcd_pos_cursor(0, 0);
    lcd_enviar_cadena(cad_temperatura);

    //lcd_pos_cursor(0, 1);
    //lcd_enviar_cadena(cad_temperatura);
}
