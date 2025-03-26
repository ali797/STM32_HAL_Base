/*
 * push_botton.c
 *
 *  Created on: Mar 26, 2025
 *      Author: sarayetel
 */

#include "push_botton.h"
#include "main.h"


/* Private define ------------------------------------------------------------*/
#define MIN_PUSH_TIME_MS (500)

/* Private macro -------------------------------------------------------------*/
#define PUSH_BOTTON_STATUS (HAL_GPIO_ReadPin(PUSH_BOTTON_GPIO_Port, PUSH_BOTTON_Pin))

/* Private variables ---------------------------------------------------------*/
typedef struct {
	uint32_t			last_free_time_ms;
	PushBottonStatus	last_status;
	PushBottonStatus	pre_status;
}PushBottonStruct;

static PushBottonStruct push_botton;

/* Functions -----------------------------------------------------------------*/
void push_botton_init(void)
{
	push_botton.last_free_time_ms = HAL_GetTick();

	push_botton.last_status = FREE;

	push_botton.pre_status = FREE;
}

PushBottonStatus push_botton_hold_handler(uint32_t hold_time_ms)
{
	if(PUSH_BOTTON_STATUS == PUSHED) {
		push_botton.last_status = PUSHED;

	} else if(PUSH_BOTTON_STATUS == FREE) {
		push_botton.last_status = FREE;
		push_botton.last_free_time_ms = HAL_GetTick();
		push_botton.pre_status = FREE;

	} else {
		//nothing
	}

	if((HAL_GetTick() - push_botton.last_free_time_ms > hold_time_ms) && (push_botton.pre_status == FREE)) {
		push_botton.pre_status = PUSHED;
		return PUSHED;
	}

	return FREE;
}
