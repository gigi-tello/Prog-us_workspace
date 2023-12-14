/**
  ******************************************************************************
  * @file    pantallas.h
  * @author  Giselle Tello de Meneses
  * @brief   Biblioteca con las pantallas a mostrar en el lcd
  ******************************************************************************
  **/

#include "pantallas.h"

/**
 * \brief Pantalla con el menu de opciones
 * 		----------------
 *     |>Mostrar fecha  |
 *     | Mostrar temp   |
 *		----------------
 *
 * 	Con los botones ARRIBA y ABAJO se marca la opción, y con el botón ADELANTE
 * 	se entra a la opción seleccionada.
 *  El cursor '>' cambia de línea para indicar la opción marcada.
 *  La variable de posición del cursor también sirve como variable de opción
 *  seleccionada.
 *  Implementa un debounce simple para evitar el rebote de los botones del keypad
 *
 */

void pant_opciones(void){
    /*

    */
	bool_t opcion_seleccionada = false; 	//Flag para cambiar de pantalla
	bool_t lectura_boton_habilitada = true;

	uint8_t boton = BOT_NINGUNO; 				//Botón presionado
	uint8_t pos_cursor = OPCION_MOSTRAR_FECHA; 	//Posición del cursor

    tick_t tiempo_debounce_btn = 100;
    delay_t btn_delay={           //Inicializo la estructura del delay
            .startTime = 0,
            .duration = 0,
            .running = false
    };

	delayInit(&btn_delay, tiempo_debounce_btn);

	lcd_borrar();
	lcd_pos_cursor(0, 1);
    lcd_enviar_cadena(MSJ_MOSTRAR_FECHA);
    lcd_pos_cursor(1, 1);
    lcd_enviar_cadena(MSJ_MOSTRAR_TEMP);
	pant_fila_cursor(pos_cursor);

    while(opcion_seleccionada == false){
        if(delayRead(&btn_delay)){    			//Debounce - Cuando se cumple
        	lectura_boton_habilitada = true;	//el tiempo, habilito el botón
        }

        if(lectura_boton_habilitada){
        	boton = obtener_boton_presionado();
        }

    	switch (boton){
    	case BOT_ABAJO :
    		if(pos_cursor == OPCION_MOSTRAR_FECHA){
    			pos_cursor = OPCION_MOSTRAR_TEMP;
    			pant_fila_cursor(pos_cursor);
    			lectura_boton_habilitada = false;
    		}
    		break;
    	case BOT_ARRIBA :
    		if(pos_cursor == OPCION_MOSTRAR_TEMP){
    			pos_cursor = OPCION_MOSTRAR_FECHA;
    			pant_fila_cursor(pos_cursor);
    			lectura_boton_habilitada = false;
    		}
    		break;
    	case BOT_ADELANTE :
    		if(pos_cursor == OPCION_MOSTRAR_FECHA){
    			mostrar_pantalla = PANTALLA_FECHA;
    		}
    		else if(pos_cursor == OPCION_MOSTRAR_TEMP){
    			mostrar_pantalla = PANTALLA_TEMP;
    		}
    		opcion_seleccionada = true;
    		break;
    	default:
    		break;
    	}

    }
}

/**
 * \brief Pantalla que muestra la fecha y hora
 *
 * 		----------------
 *     |    dd/mm/aa    |
 *     |     hh:mm      |
 *		----------------
 *
 * 	El botón ATRAS vuelve al menú principal.
 *
 */
void pant_fecha(void){

	char fecha[LARGO_CADENA_FECHA] = "";
	char hora[LARGO_CADENA_HORA] =  "";
	bool_t boton_presionado = false;
	uint8_t boton = BOT_NINGUNO;

	obtener_fecha(fecha);
	obtener_hora(hora);

    lcd_borrar();
    lcd_pos_cursor(0, 4);
    lcd_enviar_cadena(fecha);

    lcd_pos_cursor(1, 5);
    lcd_enviar_cadena(hora);

    while(boton_presionado == false){
    	boton = obtener_boton_presionado();

        switch (boton){
            case BOT_ATRAS:
            	mostrar_pantalla = PANTALLA_OPCIONES;
            	boton_presionado = true;
                break;
            default:
                break;
        }

    }

}
/**
 * \brief Pantalla que muestra la temperatura
 *
 * 		----------------
 *     | Temp: TT.tt C  |
 *     |                |
 *		----------------
 *
 * 	El botón ATRAS vuelve al menú principal.
 *
 */
void pant_temp(void){
    char cad_temperatura[LARGO_CADENA_TEMP] = "";
	bool_t boton_presionado = false;
	uint8_t boton = BOT_NINGUNO;

    obtener_temp(cad_temperatura);

    lcd_borrar();
    lcd_pos_cursor(0, 0);
    lcd_enviar_cadena(cad_temperatura);

    while(boton_presionado == false){
    	boton = obtener_boton_presionado();

        switch (boton){
            case BOT_ATRAS:
            	mostrar_pantalla = PANTALLA_OPCIONES;
            	boton_presionado = true;
                break;
            default:
                break;
        }

    }

}

/**
 * \brief Ubica al cursor en la opción marcada
 *
 *	Utilizando el dato de la opción marcada, borra el cursor
 *	de la otra opción, y lo dibuja en la correspondiente.
 *
 * \param opcion La opción marcada
 *
 */
void pant_fila_cursor(uint8_t opcion){
    switch (opcion){
        case OPCION_MOSTRAR_FECHA:
        	lcd_pos_cursor(OPCION_MOSTRAR_TEMP, 0);
            break;
        case OPCION_MOSTRAR_TEMP:
        	lcd_pos_cursor(OPCION_MOSTRAR_FECHA, 0);
            break;
    }
    lcd_enviar_cadena(" ");
    lcd_pos_cursor(opcion, 0);
    lcd_enviar_cadena(CARACTER_CURSOR);
}
