/*
 * delay.c
 *
 *  Created on: Mar 13, 2019
 *      Author: dev1
 */
#include <inttypes.h>
#include "delay.h"

void delay_ms(uint16_t del)
{
	int i = 0;
	while(del--)
	{
		for(i=0;i<2200;i++)
		{
			asm("NOP");
		}
	}
}
