/*
 * uart_handle.c
 *
 *  Created on: Dec 15, 2024
 *      Author: Salmon1611
 */
#include "uart_handle.h"
#include "stdbool.h"
#include "led_control.h"
#include "ds1307.h"

extern volatile uint8_t SCI1_rxdone;
extern uint16_t g_rx1_cnt;
extern char g_rx1_char;
extern uint8_t cntTimeRev1;
extern char g_rx1_buffer[MAX_BUFFER_UART1];
extern DS1307_STRUCT time;
extern char g_led_status[16];
extern UART_HandleTypeDef huart1;
bool UART1_IsDoneFrame(void)
{
	if(cntTimeRev1>0)
	{
		cntTimeRev1--;
		if(cntTimeRev1 == 0)
		{
			return true;
		}
	}
	return false;
}

void GeneralCmd()
{
	for(uint16_t i=0;i< g_rx1_cnt;i++)
		{

		if(strncmp(g_rx1_buffer+i,"c:do0:",6)==0)
				{

					if(strcmp(g_rx1_buffer+i+6,"0")==0)
					{
						controlLED(0, 0);
					}
					else if(strcmp(g_rx1_buffer+i+6,"1")==0)
					{
						controlLED(0, 1);
					}
				}
		else if(strncmp(g_rx1_buffer+i,"c:do1:",6)==0)
						{

							if(strcmp(g_rx1_buffer+i+6,"0")==0)
							{
								controlLED(1, 0);
							}
							else if(strcmp(g_rx1_buffer+i+6,"1")==0)
							{
								controlLED(1, 1);
							}
						}
		else if(strncmp(g_rx1_buffer+i,"c:do2:",6)==0)
								{

									if(strcmp(g_rx1_buffer+i+6,"0")==0)
									{
										controlLED(2, 0);
									}
									else if(strcmp(g_rx1_buffer+i+6,"1")==0)
									{
										controlLED(2, 1);
									}
								}
		else if(strncmp(g_rx1_buffer+i,"c:do3:",6)==0)
								{

									if(strcmp(g_rx1_buffer+i+6,"0")==0)
									{
										controlLED(3, 0);
									}
									else if(strcmp(g_rx1_buffer+i+6,"1")==0)
									{
										controlLED(3, 1);
									}
								}
		else if(strncmp(g_rx1_buffer+i,"c:do4:",6)==0)
								{

									if(strcmp(g_rx1_buffer+i+6,"0")==0)
									{
										controlLED(4, 0);
									}
									else if(strcmp(g_rx1_buffer+i+6,"1")==0)
									{
										controlLED(4, 1);
									}
								}
		else if(strncmp(g_rx1_buffer+i,"c:do5:",6)==0)
								{

									if(strcmp(g_rx1_buffer+i+6,"0")==0)
									{
										controlLED(5, 0);
									}
									else if(strcmp(g_rx1_buffer+i+6,"1")==0)
									{
										controlLED(5, 1);
									}
								}
		else if(strncmp(g_rx1_buffer+i,"c:do6:",6)==0)
								{

									if(strcmp(g_rx1_buffer+i+6,"0")==0)
									{
										controlLED(6, 0);
									}
									else if(strcmp(g_rx1_buffer+i+6,"1")==0)
									{
										controlLED(6, 1);
									}
								}
		else if(strncmp(g_rx1_buffer+i,"c:do7:",6)==0)
								{

									if(strcmp(g_rx1_buffer+i+6,"0")==0)
									{
										controlLED(7, 0);
									}
									else if(strcmp(g_rx1_buffer+i+6,"1")==0)
									{
										controlLED(7, 1);
									}
								}
		else if(strncmp(g_rx1_buffer+i,"c:year:",7)==0)
								{

									if(atoi(g_rx1_buffer+i+7)>2000 && atoi(g_rx1_buffer+i+7) <3000)
									{
										time.year = atoi(g_rx1_buffer+i+7);
										DS1307_settime(&time);
									}
								}
		else if(strncmp(g_rx1_buffer+i,"c:month:",8)==0)
								{

									if(atoi(g_rx1_buffer+i+8)>=1 && atoi(g_rx1_buffer+i+8) <=12)
									{
										time.month = atoi(g_rx1_buffer+i+8);
										DS1307_settime(&time);
									}
								}
		else if(strncmp(g_rx1_buffer+i,"c:date:",7)==0)
								{

									if(atoi(g_rx1_buffer+i+7)>=1 && atoi(g_rx1_buffer+i+7) <=31)
									{
										time.date = atoi(g_rx1_buffer+i+7);
										DS1307_settime(&time);
									}
								}
		else if(strncmp(g_rx1_buffer+i,"c:hour:",7)==0)
								{

									if(atoi(g_rx1_buffer+i+7)>=0 && atoi(g_rx1_buffer+i+7) <=24)
									{
										time.hour = atoi(g_rx1_buffer+i+7);
										DS1307_settime(&time);
									}
								}
		else if(strncmp(g_rx1_buffer+i,"c:min:",6)==0)
								{

									if(atoi(g_rx1_buffer+i+6)>=0 && atoi(g_rx1_buffer+i+6) <=59)
									{
										time.min = atoi(g_rx1_buffer+i+6);
										DS1307_settime(&time);
									}
								}
		else if(strncmp(g_rx1_buffer+i,"c:sec:",6)==0)
								{

									if(atoi(g_rx1_buffer+i+6)>=0 && atoi(g_rx1_buffer+i+6) <=59)
									{
										time.sec = atoi(g_rx1_buffer+i+6);
										DS1307_settime(&time);
									}
								}
		else if(strncmp(g_rx1_buffer+i,"c:forcesend",11)==0)
								{
									LED_status_update();

								}
		}
}

void Uart_Cmd_Handler()
{
	if(UART1_IsDoneFrame()&&g_rx1_cnt>=3)
		{
			GeneralCmd();
			g_rx1_cnt=0;
			memset(g_rx1_buffer,0,sizeof(g_rx1_buffer));
		}
}

