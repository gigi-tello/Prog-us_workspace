#include <stdint.h>
#include "stm32f4xx_nucleo_144.h"

#define BUTTON_PRESSED 1
#define BUTTON_NOT_PRESSED 0

typedef enum{
	BUTTON_UP,
	BUTTON_FALLING,
	BUTTON_DOWN,
	BUTTON_RISING,
} debounceState_t;

void debounceFSM_init(debounceState_t* debounceState);		// debe cargar el estado inicial
void debounceFSM_update(debounceState_t* debounceState);	// debe leer las entradas, resolver la lógica de transición de estados y actualizar las salidas

/* La función readKey debe leer una variable interna del módulo y devolver true o false si la tecla fue presionada.  Si devuelve true, debe resetear (poner en false) el estado de la variable.*/
// bool_t readKey();
