/*
 * led_manager.c
 *
 *  Created on: Mar 26, 2025
 *      Author: sarayetel
 */

#include "main.h"
#include "configurations/user_configurations.h"
#include "push_botton.h"
#include "led_manger.h"

void led_manager_with_push_botton(void)
{
#if LED_MANGER_WITH_PUSH_BOTTON == LED_MANGER_WITH_PUSH_BOTTON_ENABLE
	if (push_botton_hold_handler(500)) {
		green_led_command(GPIO_PIN_SET);
		HAL_Delay(500);

	} else {
		green_led_command(GPIO_PIN_RESET);

	}
#endif //LED_MANGER_WITH_PUSH_BOTTON == LED_MANGER_WITH_PUSH_BOTTON_ENABLE
}
