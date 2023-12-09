#include <API_lcd.h>

void lcd_init (void){
    // Inicialización para 4 bit
    HAL_Delay(50);  // Esperar >40ms
    lcd_enviar_comando (INIT_CMD);
    HAL_Delay(5);  // Esperar >4.1ms
    lcd_enviar_comando (INIT_CMD);
    HAL_Delay(1);  // Esperar >100us
    lcd_enviar_comando (INIT_CMD);
    HAL_Delay(10);
    lcd_enviar_comando (MODO_4BIT);
    HAL_Delay(10);

  // dislay initialisation
    lcd_enviar_comando (FUNCTION_SET); // FDL=0 (4 bit mode), N = 1 (2 line display) F = 0 (5x8 characters)
    HAL_Delay(1);
    lcd_enviar_comando (LCD_OFF); //Display on/off control --> D=0,C=0, B=0  ---> display off
    HAL_Delay(1);
    lcd_enviar_comando (CLEAR_LCD);  // clear display
    HAL_Delay(1);
    HAL_Delay(1);
    lcd_enviar_comando (ENTRY_MODE_SET); //Entry mode set --> I/D = 1 (increment cursor) & S = 0 (no shift)
    HAL_Delay(1);
    lcd_enviar_comando (BLINK_CURSOR); //Display on/off control --> D = 1, C and B = 0. (Cursor and blink, last two bits)
}

void lcd_enviar_comando (char cmd){
  char data_u, data_l;
    uint8_t data_t[4];
    data_u = (cmd&0xf0);
    data_l = ((cmd<<4)&0xf0);
    data_t[0] = data_u|0x0C;  //en=1, rs=0
    data_t[1] = data_u|0x08;  //en=0, rs=0
    data_t[2] = data_l|0x0C;  //en=1, rs=0
    data_t[3] = data_l|0x08;  //en=0, rs=0
    HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) data_t, 4, 100);
}


void lcd_enviar_dato (char dato){
    char data_u, data_l;
    uint8_t data_t[4];
    data_u = (dato&0xf0);
    data_l = ((dato<<4)&0xf0);
    data_t[0] = data_u|0x0D;  //en=1, rs=1
    data_t[1] = data_u|0x09;  //en=0, rs=1
    data_t[2] = data_l|0x0D;  //en=1, rs=1
    data_t[3] = data_l|0x09;  //en=0, rs=1
    HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) data_t, 4, 100);
}
void lcd_enviar_cadena (char *str){
    while (*str) lcd_enviar_dato (*str++);
}

void lcd_pos_cursor(uint8_t fil, uint8_t col){
    switch (fil){
        case 0:
            col |= 0x80;
            break;
        case 1:
            col |= 0xC0;
            break;
    }
    lcd_enviar_comando(col);
}

void lcd_borrar(void){
	lcd_enviar_comando(CLEAR_LCD);
    HAL_Delay(5);

}
