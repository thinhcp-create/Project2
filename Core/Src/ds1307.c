/*
 * ds1307.c
 *
 *  Created on: Dec 14, 2024
 *      Author: Salmon1611
 */
#include "ds1307.h"
extern I2C_HandleTypeDef hi2c1;

uint8_t DS1307_GetRegByte(uint8_t regAddr) {
    uint8_t val=0;
    HAL_I2C_Master_Transmit(&hi2c1, DS1307_I2C_ADDR << 1, &regAddr, 1, DS1307_TIMEOUT);
//    HAL_Delay(5);
    HAL_I2C_Master_Receive(&hi2c1, DS1307_I2C_ADDR << 1, &val, 1, DS1307_TIMEOUT);
    return val;
}
uint8_t DS1307_DecodeBCD(uint8_t bin) {
    return (((bin & 0xf0) >> 4) * 10) + (bin & 0x0f);
}
uint8_t DS1307_EncodeBCD(uint8_t dec) {
    return (dec % 10 + ((dec / 10) << 4));
}
void DS1307_gettime(DS1307_STRUCT *ds1307){
    uint16_t cen;
    ds1307->sec=DS1307_DecodeBCD(DS1307_GetRegByte(DS1307_REG_SECOND) & 0x7f);
    ds1307->min=DS1307_DecodeBCD(DS1307_GetRegByte(DS1307_REG_MINUTE));
    ds1307->hour=DS1307_DecodeBCD(DS1307_GetRegByte(DS1307_REG_HOUR) & 0x3f);
//    ds1307->dow=DS1307_DecodeBCD(DS1307_GetRegByte(DS1307_REG_DOW));
    ds1307->date=DS1307_DecodeBCD(DS1307_GetRegByte(DS1307_REG_DATE));
    ds1307->month=DS1307_DecodeBCD(DS1307_GetRegByte(DS1307_REG_MONTH));
    cen = DS1307_GetRegByte(DS1307_REG_CENT) * 100;
    ds1307->year=DS1307_DecodeBCD(DS1307_GetRegByte(DS1307_REG_YEAR)) + cen;
}
void DS1307_SetRegByte(uint8_t regAddr, uint8_t val) {
    uint8_t bytes[2] = { regAddr, val };
    HAL_I2C_Master_Transmit(&hi2c1, DS1307_I2C_ADDR << 1, bytes, 2, DS1307_TIMEOUT);
}
uint8_t DS1307_GetClockHalt(void) {
    return (DS1307_GetRegByte(DS1307_REG_SECOND) & 0x80) >> 7;
}
void DS1307_settime(DS1307_STRUCT *ds1307){
    DS1307_SetRegByte(DS1307_REG_SECOND, DS1307_EncodeBCD(ds1307->sec | DS1307_GetClockHalt()));
    DS1307_SetRegByte(DS1307_REG_MINUTE, DS1307_EncodeBCD(ds1307->min));
    DS1307_SetRegByte(DS1307_REG_HOUR, DS1307_EncodeBCD(ds1307->hour & 0x3f));//hour_24mode Hour in 24h format, 0 to 23.
    DS1307_SetRegByte(DS1307_REG_DOW, DS1307_EncodeBCD(ds1307->dow));//dayOfWeek Days since last Sunday, 0 to 6.
    DS1307_SetRegByte(DS1307_REG_DATE, DS1307_EncodeBCD(ds1307->date));//date Day of month, 1 to 31.
    DS1307_SetRegByte(DS1307_REG_MONTH, DS1307_EncodeBCD(ds1307->month));//month Month, 1 to 12.
    DS1307_SetRegByte(DS1307_REG_CENT, ds1307->year / 100);
    DS1307_SetRegByte(DS1307_REG_YEAR, DS1307_EncodeBCD(ds1307->year % 100));//2000 to 2099.
}

void DS1307_SetClockHalt(uint8_t halt) {
    uint8_t ch = (halt ? 1 << 7 : 0);
    DS1307_SetRegByte(DS1307_REG_SECOND, ch | (DS1307_GetRegByte(DS1307_REG_SECOND) & 0x7f));
}
/**
 * @brief Sets UTC offset.
 * @note  UTC offset is not updated automatically.
 * @param hr UTC hour offset, -12 to 12.
 * @param min UTC minute offset, 0 to 59.
 */
void DS1307_SetTimeZone(int8_t hr, uint8_t min) {
    DS1307_SetRegByte(DS1307_REG_UTC_HR, hr);
    DS1307_SetRegByte(DS1307_REG_UTC_MIN, min);
}
void DS1307_config(){
    DS1307_SetClockHalt(0);
    DS1307_SetTimeZone(+8, 00);
}

uint8_t dayOfWeek(uint8_t day, uint8_t month, uint16_t year) {
    // M?ng luu tr? s? ngày c?a các tháng
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Ki?m tra nam nhu?n và c?p nh?t s? ngày c?a tháng 2
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        daysInMonth[2] = 29;
    }

    // Tính s? ngày tính t? ngày 1/1/1 d?n ngày c?n ki?m tra
    int totalDays = 0;
    for (int y = 1; y < year; y++) {
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
            totalDays += 366;
        } else {
            totalDays += 365;
        }
    }

    for (int m = 1; m < month; m++) {
        totalDays += daysInMonth[m];
    }

    totalDays += day;

    // Tính th? trong tu?n
    int dayOfWeek = totalDays % 7;

    return dayOfWeek;
}
