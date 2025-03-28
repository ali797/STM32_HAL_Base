/*
 * led_manger.h
 *
 *  Created on: Mar 26, 2025
 *      Author: sarayetel
 */

#ifndef INC_LED_MANGER_H_
#define INC_LED_MANGER_H_

#include "main.h"

void led_manager_with_push_botton(void);

/* inline functions --------------------------------------------------*/

static inline void green_led_command(GPIO_PinState pin_state){
	HAL_GPIO_WritePin(LED4_Green_GPIO_Port, LED4_Green_Pin, pin_state);
}

#endif /* INC_LED_MANGER_H_ */
