/*
 * push_botton.h
 *
 *  Created on: Mar 26, 2025
 *      Author: sarayetel
 */

#ifndef INC_PUSH_BOTTON_H_
#define INC_PUSH_BOTTON_H_

#include <stdint.h>

/**
 * @brief: این تابع استراکچر پوش باتن را مقدار دهی اولیه میکند
 */
void push_botton_init(void);

/**
 * @brief: در صورتی که کلید پوش باتن به مدت اعلام شده در ورودی، فشرده شده
 * و نگهداشته شود یک بار خروجی یک برخواهد گرداند
 * @inputs: میزان تایم بر حسب میلی ثانیه رو مشخص میکنه که باید کلید فشرده
 * شود
 * @return: نشان دهنده این است که کلید به مدت گفته شده فشرده و نگهداشته
 * شده است
 */
GPIO_PinState push_botton_hold_handler(uint32_t hold_time_ms);


#endif /* INC_PUSH_BOTTON_H_ */
