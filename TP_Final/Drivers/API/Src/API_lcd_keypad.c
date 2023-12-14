#include "API_lcd_keypad.h"
#include "common.h"

//uint8_t d_port[4] = {PORT_D4, PORT_D5, PORT_D6, PORT_D7};
//uint8_t d_pins[4] = {PIN_D4, PIN_D5, PIN_D6, PIN_D7};

//void delay_us(uint16_t us){
//  __HAL_TIM_SET_COUNTER(&htim2, 0);
//  while (__HAL_TIM_GET_COUNTER(&htim2) < us);
//}

uint8_t boton_presionado(uint32_t req){
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

void lcd_send_cmd (char cmd){
  char data_u, data_l;
    uint8_t data_t[4];
    data_u = (cmd&0xf0);
    data_l = ((cmd<<4)&0xf0);
    data_t[0] = data_u|0x0C;  //en=1, rs=0
    data_t[1] = data_u|0x08;  //en=0, rs=0
    data_t[2] = data_l|0x0C;  //en=1, rs=0
    data_t[3] = data_l|0x08;  //en=0, rs=0
    HAL_I2C_Master_Transmit (&hi2c1, LCD_ADDR,(uint8_t *) data_t, 4, 100);
}

void lcd_init (void){
    // 4 bit initialisation
    HAL_Delay(50);  // wait for >40ms
    lcd_send_cmd (0x30);
    HAL_Delay(5);  // wait for >4.1ms
    lcd_send_cmd (0x30);
    HAL_Delay(1);  // wait for >100us
    lcd_send_cmd (0x30);
    HAL_Delay(10);
    lcd_send_cmd (0x20);  // 4bit mode
    HAL_Delay(10);

  // dislay initialisation
    lcd_send_cmd (0x28); // Function set --> DL=0 (4 bit mode), N = 1 (2 line display) F = 0 (5x8 characters)
    HAL_Delay(1);
    lcd_send_cmd (0x08); //Display on/off control --> D=0,C=0, B=0  ---> display off
    HAL_Delay(1);
    lcd_send_cmd (0x01);  // clear display
    HAL_Delay(1);
    HAL_Delay(1);
    lcd_send_cmd (0x06); //Entry mode set --> I/D = 1 (increment cursor) & S = 0 (no shift)
    HAL_Delay(1);
    lcd_send_cmd (0x0C); //Display on/off control --> D = 1, C and B = 0. (Cursor and blink, last two bits)
}

void lcd_send_data (char data){
    char data_u, data_l;
    uint8_t data_t[4];
    data_u = (data&0xf0);
    data_l = ((data<<4)&0xf0);
    data_t[0] = data_u|0x0D;  //en=1, rs=1
    data_t[1] = data_u|0x09;  //en=0, rs=1
    data_t[2] = data_l|0x0D;  //en=1, rs=1
    data_t[3] = data_l|0x09;  //en=0, rs=1
    HAL_I2C_Master_Transmit (&hi2c1, LCD_ADDR,(uint8_t *) data_t, 4, 100);
}
void lcd_send_string (char *str){
    while (*str) lcd_send_data (*str++);
}

//void lcd_enviar(int8_t data, int8_t rs) {
//    HAL_GPIO_WritePin(RS_PORT, RS_PIN, rs);  // rs = 1 for data, rs=0 for command
//    /* write the data to the respective pin */
//    HAL_GPIO_WritePin(D7_PORT, D7_PIN, ((data>>3)&0x01));
//    HAL_GPIO_WritePin(D6_PORT, D6_PIN, ((data>>2)&0x01));
//    HAL_GPIO_WritePin(D5_PORT, D5_PIN, ((data>>1)&0x01));
//    HAL_GPIO_WritePin(D4_PORT, D4_PIN, ((data>>0)&0x01));
//    /* Toggle EN PIN to send the data
//     * if the HCLK > 100 MHz, use the  20 us delay
//     * if the LCD still doesn't work, increase the delay to 50, 80 or 100..
//     */
//    HAL_GPIO_WritePin(EN_PORT, EN_PIN, 1);
//    HAL_Delay(1);
////  delay (20);
//    HAL_GPIO_WritePin(EN_PORT, EN_PIN, 0);
//    HAL_Delay(1);
////  delay (20);
//}
//
//void lcd_enviar_comando(char cmd) {
////	uint8_t datatosend;
////    /* send upper nibble first */
////    datatosend = ((cmd>>4)&0x0f);
////    lcd_enviar(datatosend,RS_COMANDO);  // RS must be while sending command
////    /* send Lower Nibble */
////    datatosend = ((cmd)&0x0f);
////    lcd_enviar(datatosend, RS_COMANDO);
//
//	char data_u, data_l;
//        uint8_t data_t[4];
//        data_u = (cmd&0xf0);
//        data_l = ((cmd<<4)&0xf0);
//        data_t[0] = data_u|0x0C;  //en=1, rs=0
//        data_t[1] = data_u|0x08;  //en=0, rs=0
//        data_t[2] = data_l|0x0C;  //en=1, rs=0
//        data_t[3] = data_l|0x08;  //en=0, rs=0
//        HAL_I2C_Master_Transmit (&hi2c1, LCD_ADDR,(uint8_t *) data_t, 4, 100);
//}
//
//void lcd_enviar_dato (char data)
//{
////	int8_t datatosend;
////
////    /* send higher nibble */
////    datatosend = ((data>>4)&0x0f);
////    lcd_enviar(datatosend, RS_DATO);  // rs =1 for sending data
////    /* send Lower nibble */
////    datatosend = ((data)&0x0f);
////    lcd_enviar(datatosend, RS_DATO);
//
//	char data_u, data_l;
//    uint8_t data_t[4];
//    data_u = (data&0xf0);
//    data_l = ((data<<4)&0xf0);
//    data_t[0] = data_u|0x0D;  //en=1, rs=1
//    data_t[1] = data_u|0x09;  //en=0, rs=1
//    data_t[2] = data_l|0x0D;  //en=1, rs=1
//    data_t[3] = data_l|0x09;  //en=0, rs=1
//    HAL_I2C_Master_Transmit (&hi2c1, LCD_ADDR,(uint8_t *) data_t, 4, 100);
//
//}
//
//void lcd_init(void){
//    // 4 bit initialisation
//    HAL_Delay(50);  // wait for >40ms
//    lcd_enviar_comando (INIT_CMD);
//    HAL_Delay(5);  // wait for >4.1ms
//    lcd_enviar_comando (INIT_CMD);
//    HAL_Delay(1);  // wait for >100us
//    lcd_enviar_comando (INIT_CMD);
//    HAL_Delay(10);
//    lcd_enviar_comando (MODO_4BIT);  // 4bit mode
//    HAL_Delay(10);
//
//  // dislay initialisation
//    lcd_enviar_comando (FUNCTION_SET); // Function set --> DL=0 (4 bit mode), N = 1 (2 line display) F = 0 (5x8 characters)
//    HAL_Delay(1);
//    lcd_enviar_comando (LCD_OFF); //Display on/off control --> D=0,C=0, B=0  ---> display off
//    HAL_Delay(1);
//    lcd_enviar_comando (CLEAR_LCD);  // clear display
//    HAL_Delay(1);
//    HAL_Delay(1);
//    lcd_enviar_comando (ENTRY_MODE_SET); //Entry mode set --> I/D = 1 (increment cursor) & S = 0 (no shift)
//    HAL_Delay(1);
//    lcd_enviar_comando (BLINK_CURSOR); //Display on/off control --> D = 1, C and B = 0. (Cursor and blink, last two bits)
//}
//
//void lcd_send_string (char *str)
//{
//	while (*str) lcd_enviar_dato (*str++);
//}
//
//void lcd_put_cur(int8_t row, int8_t col)
//{
//    switch (row)
//    {
//        case 0:
//            col |= 0x80;
//            break;
//        case 1:
//            col |= 0xC0;
//            break;
//    }
//    lcd_enviar_comando (col);
//}
