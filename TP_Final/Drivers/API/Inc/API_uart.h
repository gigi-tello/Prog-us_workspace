/**
  ******************************************************************************
  * @file    API_uart.h
  * @author  Giselle Tello de Meneses
  * @brief   Este archivo contiene los prototipos y las funciones para
  * controlar la UART3 de la placa NUCLEO-F439ZI
  ******************************************************************************
  **/

#include "common.h"
#include "stm32f4xx_nucleo_144.h"

#define HAL_UART_INIT_OK true
#define HAL_UART_INIT_ERROR false

bool_t uartInit(); //Inicializa la uart3.
void uartSendString(uint8_t * pstring); //Transmite la cadena pstring por la uart.
void uartSendStringSize(uint8_t * pstring, uint16_t size); //Transmite 'size' caracteres de la cadena pstring por la uart.

// void uartReceiveStringSize(uint8_t * pstring, uint16_t size); //Recibe 'size' caracteres a la cadena pstring por la uart. Se deja comentada ya que no se usa por ahora
