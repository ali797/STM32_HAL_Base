/*
 * led_manger.h
 *
 *  Created on: Mar 26, 2025
 *      Author: sarayetel
 */

#ifndef INC_LED_MANGER_H_
#define INC_LED_MANGER_H_


/* Private enums ------------------------------------------------------------*/
typedef enum {
	LED_OFF = 0,
	LED_ON 	= 1
}LedCommand;

/* Private inline functions --------------------------------------------------*/

extern inline void green_led_command(LedCommand cmd){
	HAL_GPIO_WritePin(LED4_Green_GPIO_Port, LED4_Green_Pin, cmd);
}

#endif /* INC_LED_MANGER_H_ */
