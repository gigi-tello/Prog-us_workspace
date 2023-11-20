#include "common.h"
#include "stm32f4xx_nucleo_144.h"

#define HAL_UART_INIT_OK true
#define HAL_UART_INIT_ERROR false

bool_t uartInit();
void uartSendString(uint8_t * pstring);
void uartSendStringSize(uint8_t * pstring, uint16_t size);
// void uartReceiveStringSize(uint8_t * pstring, uint16_t size);
