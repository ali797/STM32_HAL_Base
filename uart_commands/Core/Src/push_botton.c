/*
 * push_botton.c
 *
 *  Created on: Mar 26, 2025
 *      Author: sarayetel
 */

#include "main.h"
#include "push_botton.h"


/* Private define ------------------------------------------------------------*/
#define MIN_PUSH_TIME_MS (500)

/* Private macro -------------------------------------------------------------*/
#define PUSH_BOTTON_STATUS (HAL_GPIO_ReadPin(PUSH_BOTTON_GPIO_Port, PUSH_BOTTON_Pin))

/* enums ------------------------------------------------------------*/
//typedef enum {
//	FREE 	= 0,
//	PUSHED 	= 1
//} PushBottonStatus;

typedef enum {
	PUSH_BOTTON_UNINITED 	= 0,
	PUSH_BOTTON_INITED 		= 1
}StructInit;

/* Private variables ---------------------------------------------------------*/
typedef struct {
	uint32_t			last_free_time_ms;
	GPIO_PinState	last_status;
	GPIO_PinState	pre_status;
	StructInit		structure_inited;
}PushBottonStruct;

static PushBottonStruct push_botton = {0, 0, 0, 0};

/* Functions -----------------------------------------------------------------*/
void push_botton_init(void)
{
	push_botton.last_free_time_ms = HAL_GetTick();

	push_botton.last_status = GPIO_PIN_RESET;

	push_botton.pre_status = GPIO_PIN_RESET;

	push_botton.structure_inited = PUSH_BOTTON_INITED;
}


GPIO_PinState push_botton_hold_handler(uint32_t hold_time_ms)
{
	if(push_botton.structure_inited == PUSH_BOTTON_UNINITED) {
		push_botton_init();
	}

	if(PUSH_BOTTON_STATUS == GPIO_PIN_SET) {
		push_botton.last_status = GPIO_PIN_SET;

	} else if(PUSH_BOTTON_STATUS == GPIO_PIN_RESET) {
		push_botton.last_status = GPIO_PIN_RESET;
		push_botton.last_free_time_ms = HAL_GetTick();
		push_botton.pre_status = GPIO_PIN_RESET;

	} else {
		//nothing
	}

	if((HAL_GetTick() - push_botton.last_free_time_ms > hold_time_ms) && (push_botton.pre_status == GPIO_PIN_RESET)) {

		push_botton.pre_status = GPIO_PIN_SET;
		return GPIO_PIN_SET;
	}

	return GPIO_PIN_RESET;
}
