/**
  ******************************************************************************
  * @file    API_keypad.c
  * @author  Giselle Tello de Meneses
  * @brief   Biblioteca para manejar el keypad del shield.
  * El keypad es un arreglo de botones que forman un divisor resistivo entre
  * 5 V y GND, y el valor resultante se puede leer con una entrada analógica.
  ******************************************************************************
  **/

#include "API_keypad.h"

/**
 * \brief Evalúa qué botón se presionó.
 *
 *  El shield LCD tiene un arreglo de botones que forma un divisor resistivo
 *  que cambia según el pulsador que se presiona, aproximadamente 1V por botón.
 *  Se fijaron límites según los resistores mencionados en la hoja de datos,
 *  dejando un margen.
 *  La salida está conectada a A0.
 *
 * \return El botón presionado.
 */

uint8_t obtener_boton_presionado(){
    uint8_t boton = BOT_NINGUNO;
    uint32_t req = leer_adc();

    if (req < LIMITE_BOT_ADELANTE) {
        boton = BOT_ADELANTE;
    } else if (req < LIMITE_BOT_ARRIBA) {
        boton = BOT_ARRIBA;
    } else if (req < LIMITE_BOT_ABAJO) {
        boton = BOT_ABAJO;
    } else if (req < LIMITE_BOT_ATRAS) {
        boton = BOT_ATRAS;
    }

    return boton;
}

/**
 * \brief Devuelve una cadena indicando el botón presionado.
 *
 *  Función para debuggear el funcionamiento de obtener_boton_presionado()
 *
 * \param boton El botón devuelto por obtener_boton_presionado().
 * \return La cadena correspondiente
 */
uint8_t * str_boton(uint8_t boton){
    uint8_t * string = (uint8_t *)"";
    switch(boton){
    case BOT_ADELANTE:
        string = STR_ADELANTE;
        break;
    case BOT_ARRIBA:
        string = STR_ARRIBA;
        break;
    case BOT_ABAJO:
        string = STR_ABAJO;
        break;
    case BOT_ATRAS:
        string = STR_ATRAS;
        break;
    default:
        string = STR_NINGUNO;
        break;
    }
    return string;
}
