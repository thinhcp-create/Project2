/*
 * led7seg.c
 *
 *  Created on: Dec 13, 2024
 *      Author: Salmon1611
 */


#include "led7seg.h"

// Hàm hiển thị số từ 0 đến 9 trên LED 7 thanh
void display_digit(uint8_t digit) {
    // Đảm bảo chỉ hiển thị các số từ 0 đến 9
    if (digit > 9) return;

    // Xuất mức tín hiệu tương ứng cho các số từ 0 đến 9
    switch (digit) {
        case 0:
            HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);
            break;
        case 1:
            HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);
            break;
        case 2:
            HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_RESET);
            break;
        case 3:
            HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_RESET);
            break;
        case 4:
            HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_RESET);
            break;
        case 5:
            HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_RESET);
            break;
        case 6:
            HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_RESET);
            break;
        case 7:
            HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);
            break;
        case 8:
            HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_RESET);
            break;
        case 9:
            HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_RESET);
            break;
    }
}

