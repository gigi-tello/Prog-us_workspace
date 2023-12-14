/**
  ******************************************************************************
  * @file    API_lcd.c
  * @author  Giselle Tello de Meneses
  * @brief   Biblioteca para manejar el lcd.
  ******************************************************************************
  **/

#include "API_lcd.h"

void lcd_init (void){
//	  HAL_Delay(10);
//	  HAL_GPIO_WritePin(TEST_PORT, TEST_PIN, 0);
//	  HAL_Delay(10);
//	  HAL_GPIO_WritePin(TEST_PORT, TEST_PIN, 1);
//	  HAL_Delay(25);
//	  HAL_GPIO_WritePin(TEST_PORT, TEST_PIN, 0);
//	  HAL_Delay(10);
//	  HAL_GPIO_WritePin(TEST_PORT, TEST_PIN, 1);
//	  HAL_Delay(25);
//	  HAL_GPIO_WritePin(TEST_PORT, TEST_PIN, 0);
//	  HAL_Delay(10);

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

//void lcd_enviar_comando (char cmd){
//  char data_u, data_l;
//    uint8_t data_t[4];
//    data_u = (cmd&0xf0);
//    data_l = ((cmd<<4)&0xf0);
//    data_t[0] = data_u|0x0C;  //en=1, rs=0
//    data_t[1] = data_u|0x08;  //en=0, rs=0
//    data_t[2] = data_l|0x0C;  //en=1, rs=0
//    data_t[3] = data_l|0x08;  //en=0, rs=0
//    HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) data_t, 4, 100);
//}
//
//
//void lcd_enviar_dato (char dato){
//    char data_u, data_l;
//    uint8_t data_t[4];
//    data_u = (dato&0xf0);
//    data_l = ((dato<<4)&0xf0);
//    data_t[0] = data_u|0x0D;  //en=1, rs=1
//    data_t[1] = data_u|0x09;  //en=0, rs=1
//    data_t[2] = data_l|0x0D;  //en=1, rs=1
//    data_t[3] = data_l|0x09;  //en=0, rs=1
//    HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) data_t, 4, 100);
//}
void lcd_enviar_cadena (char *str){
	  HAL_Delay(10);
	  HAL_GPIO_WritePin(TEST_PORT, TEST_PIN, 0);
	  HAL_Delay(10);
	  HAL_GPIO_WritePin(TEST_PORT, TEST_PIN, 1);
	  HAL_Delay(25);
	  HAL_GPIO_WritePin(TEST_PORT, TEST_PIN, 0);
	  HAL_Delay(10);
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

 void lcd_enviar(char data, int rs) {
    HAL_GPIO_WritePin(RS_PORT, RS_PIN, rs);  // rs = 1 for data, rs=0 for command
    /* write the data to the respective pin */
    HAL_GPIO_WritePin(D7_PORT, D7_PIN, ((data>>3)&0x01));
    HAL_GPIO_WritePin(D6_PORT, D6_PIN, ((data>>2)&0x01));
    HAL_GPIO_WritePin(D5_PORT, D5_PIN, ((data>>1)&0x01));
    HAL_GPIO_WritePin(D4_PORT, D4_PIN, ((data>>0)&0x01));
    /* Toggle EN PIN to send the data
     * if the HCLK > 100 MHz, use the  20 us delay
     * if the LCD still doesn't work, increase the delay to 50, 80 or 100..
     */
    HAL_GPIO_WritePin(EN_PORT, EN_PIN, 1);
    HAL_Delay(5);
//  delay (20);
    HAL_GPIO_WritePin(EN_PORT, EN_PIN, 0);
    HAL_Delay(5);
//  delay (20);
}

 void lcd_enviar_comando (char cmd)
 {
     char datatosend;
     /* send upper nibble first */
     datatosend = ((cmd>>4)&0x0f);
     lcd_enviar(datatosend,0);  // RS must be while sending command
     /* send Lower Nibble */
     datatosend = ((cmd)&0x0f);
     lcd_enviar(datatosend, 0);
 }

 void lcd_enviar_dato (char data)
 {
     char datatosend;

     /* send higher nibble */
     datatosend = ((data>>4)&0x0f);
     lcd_enviar(datatosend, 1);  // rs =1 for sending data
     /* send Lower nibble */
     datatosend = ((data)&0x0f);
     lcd_enviar(datatosend, 1);
 }
