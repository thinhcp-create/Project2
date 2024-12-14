/*
 * led_control.c
 *
 *  Created on: Dec 14, 2024
 *      Author: Salmon1611
 */
#include "led_control.h"
// Hàm điều khiển LED
void controlLED(uint8_t ledIndex, uint8_t state)
{
    switch (ledIndex) {
        case 0:
            HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, state ? GPIO_PIN_RESET : GPIO_PIN_SET);
            break;
        case 1:
            HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, state ? GPIO_PIN_RESET : GPIO_PIN_SET);
            break;
        case 2:
            HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, state ? GPIO_PIN_RESET : GPIO_PIN_SET);
            break;
        case 3:
            HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, state ? GPIO_PIN_RESET : GPIO_PIN_SET);
            break;
        case 4:
            HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, state ? GPIO_PIN_RESET : GPIO_PIN_SET);
            break;
        case 5:
            HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, state ? GPIO_PIN_RESET : GPIO_PIN_SET);
            break;
        case 6:
            HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, state ? GPIO_PIN_RESET : GPIO_PIN_SET);
            break;
        case 7:
            HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, state ? GPIO_PIN_RESET : GPIO_PIN_SET);
            break;
        default:
            // Không làm gì nếu chỉ số LED không hợp lệ
            break;
    }
}

