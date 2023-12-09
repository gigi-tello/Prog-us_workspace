#include "API_keypad.h"

//ADC 10bit
uint8_t obtener_boton_presionado(){
	uint32_t req = leer_adc();
    uint8_t boton = BOT_NINGUNO;
    if (req < 50) {
        boton = BOT_ADELANTE;
    } else if (req < 250) {
        boton = BOT_ARRIBA;
    } else if (req < 500) {
        boton = BOT_ABAJO;
    } else if (req < 790) {
        boton = BOT_ATRAS;
    }
    return boton;
}

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
