/*
 * uart_command_library.c
 *
 *  Created on: Mar 28, 2025
 *      Author: sarayetel
 */

#include <string.h>
#include "main.h"
#include "configurations/user_configurations.h"
#include "uart_command_library.h"
#include "led_manger.h"


extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;

uint8_t uart1_rx_interrupt_buff[UART1_RX_LENGTH];

/* Private define ------------------------------------------------------------*/
#define RECEIVE_DATA_BUFFER_SIZE (10)
/* Private macro -------------------------------------------------------------*/

/* enums ---------------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
uint8_t received_data_buffer[RECEIVE_DATA_BUFFER_SIZE];
uint8_t rec_data_buf_index = 0;

/* Functions -----------------------------------------------------------------*/

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
//	if((huart->Instance == USART1) && (huart->RxEventType == HAL_UART_RXEVENT_TC)){
	if(huart->Instance == USART1){
		///CHECK: check this pRxBuffPtr pointer, points to received data
//		received_data_buffer[rec_data_buf_index] = *(huart->pRxBuffPtr);

		received_data_buffer[rec_data_buf_index] = uart1_rx_interrupt_buff[0];
		rec_data_buf_index++;

		HAL_UART_Receive_IT(&huart1, uart1_rx_interrupt_buff, UART1_RX_LENGTH);
	}
}

void received_data_init(uint8_t clear_command)
{
	if((rec_data_buf_index == RECEIVE_DATA_BUFFER_SIZE) || (clear_command == 1)){
		rec_data_buf_index = 0;

		memset(received_data_buffer, 0, RECEIVE_DATA_BUFFER_SIZE);
	}
}

void received_data_parser(void)
{
	char *data_pointer = NULL;
	char *temp_data_pointer = NULL;

	data_pointer = strstr((void *)received_data_buffer, "Green ");
	if((data_pointer != NULL) && (data_pointer == (char *)received_data_buffer)){

		temp_data_pointer = strstr((void *)received_data_buffer, "on");
		if((temp_data_pointer != NULL) && (temp_data_pointer == (data_pointer + strlen("Green ")))) {
			green_led_command(GPIO_PIN_SET);
			received_data_init(1);
		}

		temp_data_pointer = strstr((void *)received_data_buffer, "off");
		if((temp_data_pointer != NULL) && (temp_data_pointer == (data_pointer + strlen("Green ")))) {
			green_led_command(GPIO_PIN_RESET);
			received_data_init(1);
		}

	} else if(strstr((void *)received_data_buffer, "\r\n")) {
		received_data_init(1);

	}

	//clear the buffer if buffer overflowed
	received_data_init(0);
}
