#include <API_uart.h>
#include "string.h"

UART_HandleTypeDef huart3;

bool_t uartInit(void){

	uint8_t * config_string = (uint8_t *)"USART3, 115200, UART_WORDLENGTH_8B, UART_STOPBITS_1, UART_PARITY_NONE, UART_MODE_TX_RX, UART_HWCONTROL_NONE, UART_OVERSAMPLING_16\n";

	huart3.Instance = USART3;
	huart3.Init.BaudRate = 9600;
	huart3.Init.WordLength = UART_WORDLENGTH_8B;
	huart3.Init.StopBits = UART_STOPBITS_1;
	huart3.Init.Parity = UART_PARITY_NONE;
	huart3.Init.Mode = UART_MODE_TX_RX;
	huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart3.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&huart3) != HAL_OK)
	{
		//Error_Handler();
		return HAL_UART_INIT_ERROR;
	}
	uartSendString(config_string);
	return HAL_UART_INIT_OK;
};

void uartSendString(uint8_t * pstring){
	uartSendStringSize(pstring, strlen((char *) pstring));
};
void uartSendStringSize(uint8_t * pstring, uint16_t size){
	uint16_t timeout = 1000; //Timeout en milisegundos
	HAL_UART_Transmit(&huart3, pstring, size, timeout);
};

// void uartReceiveStringSize(uint8_t * pstring, uint16_t size);
