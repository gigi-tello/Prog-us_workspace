/**
  ******************************************************************************
  * @file    pantallas.h
  * @author  Giselle Tello de Meneses
  * @brief   Biblioteca con las pantallas a mostrar en el lcd
  ******************************************************************************
  **/

#include "pantallas.h"
//#include "usart.h"
    delay_t delay={           //Inicializo la estructura del delay
            .startTime = 0,
            .duration = 0,
            .running = false
    };
tick_t tiempo_refresco = TIEMPO_REFRESCO;
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
void pag_opciones(void){

	bool_t opcion_seleccionada = false;
	bool_t lectura_boton_habilitada = true;

	uint8_t boton = BOT_NINGUNO;
	uint8_t pos_cursor = OPCION_MOSTRAR_FECHA;

    tick_t tiempo_debounce_btn = TIEMPO_DEBOUNCE_BOTON;
//    delay_t btn_delay={           //Inicializo la estructura del delay
//            .startTime = 0,
//            .duration = 0,
//            .running = false
//    };
	//char* btn_str;

	delayInit(&delay, tiempo_debounce_btn);

	lcd_borrar();
	lcd_pos_cursor(0, 1);
    lcd_enviar_cadena(MSJ_MOSTRAR_FECHA);
    lcd_pos_cursor(1, 1);
    lcd_enviar_cadena(MSJ_MOSTRAR_TEMP);
	pag_fila_cursor(pos_cursor);

    while(false == opcion_seleccionada){
        if(delayRead(&delay)){    //Si delayRead devuelve true se cumplió el
        	lectura_boton_habilitada = true; //tiempo, entonces cambio el estado del led
        }

        if(lectura_boton_habilitada){
        	boton = obtener_boton_presionado();
    		//btn_str =  str_boton(boton);
        }

  	  //HAL_UART_Transmit(&huart3, btn_str, strlen(btn_str), 1000);
  	  //HAL_UART_Transmit(&huart3, (char *)"\r\n", strlen("\r\n"), 1000);

    	switch (boton){
    	case BOT_ABAJO :
    		if(pos_cursor == OPCION_MOSTRAR_FECHA){
    			pos_cursor = OPCION_MOSTRAR_TEMP;
    			pag_fila_cursor(pos_cursor);
    			lectura_boton_habilitada = false;
    		}
    		break;
    	case BOT_ARRIBA :
    		if(pos_cursor == OPCION_MOSTRAR_TEMP){
    			pos_cursor = OPCION_MOSTRAR_FECHA;
    			pag_fila_cursor(pos_cursor);
    			lectura_boton_habilitada = false;
    		}
    		break;
    	case BOT_ADELANTE :
    		if(pos_cursor == OPCION_MOSTRAR_FECHA){
    			mostrar_pantalla = PAGINA_FECHA;
    		}
    		else if(pos_cursor == OPCION_MOSTRAR_TEMP){
    			mostrar_pantalla = PAGINA_TEMP;
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
void pag_fecha(void){

	char fecha[LARGO_CADENA_FECHA] = "";
	char hora[LARGO_CADENA_HORA] =  "";
	bool_t boton_presionado = false;
	uint8_t boton = BOT_NINGUNO;

	delayInit(&delay, tiempo_refresco);

	while(false == boton_presionado){



		if(delayRead(&delay)){    //Si se cumplió el tiempo de refresco
			obtener_fecha(fecha); //reimprimo la pantalla
			obtener_hora(hora);

			lcd_borrar();
			lcd_pos_cursor(0, 4);
			lcd_enviar_cadena(fecha);

			lcd_pos_cursor(1, 5);
			lcd_enviar_cadena(hora);
		}

		boton = obtener_boton_presionado();

		switch (boton){
		case BOT_ATRAS:
			mostrar_pantalla = PAGINA_OPCIONES;
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
void pag_temp(void){

    char cad_temperatura[LARGO_CADENA_TEMP] = "";
	bool_t boton_presionado = false;
	uint8_t boton = BOT_NINGUNO;
	delayInit(&delay, tiempo_refresco);

	while(false == boton_presionado){


		if(delayRead(&delay)){    			//Si se cumplió el tiempo de refresco
			obtener_temp(cad_temperatura); //reimprimo la pantalla
			lcd_borrar();
			lcd_pos_cursor(0, 0);
			lcd_enviar_cadena(cad_temperatura);
		}


		boton = obtener_boton_presionado();

		switch (boton){
		case BOT_ATRAS:
			mostrar_pantalla = PAGINA_OPCIONES;
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
    void pag_fila_cursor(uint8_t opcion){
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
        //lcd_enviar_cadena();
    }
/**
 * \brief Muestra la pantalla de inicio
 *
 * 		----------------
 *     |Trabajo practico|
 *     |     CESE       |
 *		----------------
 *
 */
void pag_inicio(void){
    lcd_enviar_cadena(MSJ_INICIO_FILA_1);
    lcd_pos_cursor(1,5);
    lcd_enviar_cadena(MSJ_INICIO_FILA_2);
    HAL_Delay(DELAY_PANT_INICIO);
}
