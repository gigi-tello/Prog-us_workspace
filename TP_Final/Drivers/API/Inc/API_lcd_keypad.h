#ifndef API_LCD_KEYPAD
#define API_LCD_KEYPAD

#include "common.h"

//extern TIM_HandleTypeDef htim2;

/* Definiciones de los botones del shield */
#define BOT_ADELANTE 1
#define BOT_ARRIBA 2
#define BOT_ABAJO 3
#define BOT_ATRAS 4
#define BOT_NINGUNO 5

#define STR_ADELANTE (uint8_t *)"Boton adelante\n\r";
#define STR_ARRIBA  (uint8_t *)"Boton arriba\n\r";
#define STR_ABAJO (uint8_t *)"Boton abajo\n\r";
#define STR_ATRAS (uint8_t *)"Boton atras\n\r";
#define STR_NINGUNO (uint8_t *)"Ningun boton\n\r";

/* Definiciones para el lcd */


#define LCD_ADDR 0x4E
//I2C_HandleTypeDef hi2c1;

#define D4_PORT GPIOF
#define D4_PIN GPIO_PIN_14
#define D5_PORT GPIOE
#define D5_PIN GPIO_PIN_11
#define D6_PORT GPIOE
#define D6_PIN GPIO_PIN_9
#define D7_PORT GPIOF
#define D7_PIN GPIO_PIN_13
#define RS_PORT GPIOF
#define RS_PIN GPIO_PIN_12
#define EN_PORT GPIOD
#define EN_PIN GPIO_PIN_15

#define RS_COMANDO 0
#define RS_DATO 1

#define INIT_CMD 0x30
#define MODO_4BIT 0x20
#define CLEAR_LCD 0x01
#define FUNCTION_SET 0x28 // DL=0 (4 bit mode), N = 1 (2 line display) F = 0 (5x8 characters)
#define ENTRY_MODE_SET 0x06 //I/D = 1 (increment cursor) & S = 0 (no shift)
#define LCD_OFF 0x08 // D=0,C=0, B=0
#define BLINK_CURSOR 0x0C //D = 1, C and B = 0.


/* Funciones para los botones */
uint8_t boton_presionado(uint32_t req);
uint8_t * str_boton(uint8_t boton);


/* Funciones para el lcd */
void lcd_send_cmd (char cmd);
void lcd_init (void);
void lcd_send_data (char data);
void lcd_send_string (char *str);

//void delay_us(uint16_t us);
//void lcd_init(void);
//void lcd_enviar(int8_t dato, int8_t rs);
//void lcd_enviar_comando(char);
//void lcd_enviar_dato(char);
//void lcd_send_string (char *str);

// void lcd_send_data (I2C_HandleTypeDef hi2c1, uint8_t data);
// void lcd_send_string (I2C_HandleTypeDef hi2c1, uint8_t *str);

#endif /*API_LCD_KEYPAD*/
