/*
 * uart_command_library.h
 *
 *  Created on: Mar 28, 2025
 *      Author: sarayetel
 */

#ifndef INC_UART_COMMAND_LIBRARY_H_
#define INC_UART_COMMAND_LIBRARY_H_

#define UART1_RX_LENGTH (1)

extern uint8_t uart1_rx_interrupt_buff[UART1_RX_LENGTH];

void received_data_parser(void);

#endif /* INC_UART_COMMAND_LIBRARY_H_ */
