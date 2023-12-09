#ifndef API_LCD_H
#define API_LCD_H

#include "common.h"
#include "i2c.h"

#define SLAVE_ADDRESS_LCD 0x4E // change this according to ur setup

#define RS_COMANDO 0
#define RS_DATO 1

#define EN_BAJO 0
#define EN_ALTO 1

#define INIT_CMD 0x30
#define MODO_4BIT 0x20
#define CLEAR_LCD 0x01
#define FUNCTION_SET 0x28 // DL=0 (4 bit mode), N = 1 (2 line display) F = 0 (5x8 characters)
#define ENTRY_MODE_SET 0x06 //I/D = 1 (increment cursor) & S = 0 (no shift)
#define LCD_OFF 0x08 // D=0,C=0, B=0
#define BLINK_CURSOR 0x0C //D = 1, C and B = 0.

void lcd_init(void);
void lcd_enviar_comando(char);
void lcd_enviar_dato(char);
void lcd_enviar_cadena(char*);
void lcd_pos_cursor(uint8_t, uint8_t);
void lcd_borrar(void);

#endif /*API_LCD_H*/
