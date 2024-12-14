/*
 * ds1307.h
 *
 *  Created on: Dec 14, 2024
 *      Author: Salmon1611
 */

#ifndef INC_DS1307_H_
#define INC_DS1307_H_

#include "main.h"

#define DS1307_I2C_ADDR     0x68
#define DS1307_REG_SECOND     0x00
#define DS1307_REG_MINUTE     0x01
#define DS1307_REG_HOUR      0x02
#define DS1307_REG_DOW        0x03
#define DS1307_REG_DATE       0x04
#define DS1307_REG_MONTH      0x05
#define DS1307_REG_YEAR       0x06
#define DS1307_REG_CONTROL     0x07
#define DS1307_REG_UTC_HR    0x08
#define DS1307_REG_UTC_MIN    0x09
#define DS1307_REG_CENT        0x10
#define DS1307_TIMEOUT        1000
typedef struct {
    uint8_t    sec;
    uint8_t min;
    uint8_t hour;
    uint8_t dow;
    uint8_t date;
    uint8_t month;
    uint16_t year;
}DS1307_STRUCT;

void DS1307_config();
void DS1307_gettime(DS1307_STRUCT *ds1307);
void DS1307_settime(DS1307_STRUCT *ds1307);
uint8_t dayOfWeek(uint8_t day, uint8_t month, uint16_t year);
#endif /* INC_DS1307_H_ */
