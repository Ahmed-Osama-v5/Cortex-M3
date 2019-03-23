/*
 * gpio.c
 *
 *  Created on: Mar 23, 2019
 *      Author: dev1
 */


#include "stm32f10x.h"
#include "gpio.h"

void setPinAsOut(GPIO_TypeDef *port, uint8_t pin, outMode_t mode, speed_t speed)
{
	if(pin <= 7)
	{
		pin *= 4;

		switch(speed)
		{
		case SPEED_10_MHZ:
			port->CRL |= (1 << pin);
			pin++;
			port->CRL &= ~(1 << pin);
			break;
		case SPEED_2_MHZ:
			port->CRL &= ~(1 << pin);
			pin++;
			port->CRL |= (1 << pin);
			break;
		case SPEED_50_MHZ:
			port->CRL |= (1 << pin);
			pin++;
			port->CRL |= (1 << pin);
			break;
		default: // SPEED_10_MHZ
			port->CRL |= (1 << pin);
			pin++;
			port->CRL &= ~(1 << pin);
			break;
		}

		pin++;

		switch(mode)
		{
		case PUSH_PULL_OUT:
			port->CRL &= ~(1 << pin);
			pin++;
			port->CRL &= ~(1 << pin);
			break;
		case OPEN_DRAIN_OUT:
			port->CRL |= (1 << pin);
			pin++;
			port->CRL &= ~(1 << pin);
			break;
		case ALTERNATIVE_PUSH_PULL_OUT:
			port->CRL &= ~(1 << pin);
			pin++;
			port->CRL |= (1 << pin);
			break;
		case ALTERNATIVE_OPEN_DRAIN_OUT:
			port->CRL |= (1 << pin);
			pin++;
			port->CRL |= (1 << pin);
			break;
		default: // PUSH_PULL_OUT
			port->CRL &= ~(1 << pin);
			pin++;
			port->CRL &= ~(1 << pin);
			break;
		}
	}

	else
	{
		pin -= 8;
		pin *= 4;

		switch(speed)
		{
		case SPEED_10_MHZ:
			port->CRH |= (1 << pin);
			pin++;
			port->CRH &= ~(1 << pin);
			break;
		case SPEED_2_MHZ:
			port->CRH &= ~(1 << pin);
			pin++;
			port->CRH |= (1 << pin);
			break;
		case SPEED_50_MHZ:
			port->CRH |= (1 << pin);
			pin++;
			port->CRH |= (1 << pin);
			break;
		default: // SPEED_10_MHZ
			port->CRH |= (1 << pin);
			pin++;
			port->CRH &= ~(1 << pin);
			break;
		}

		pin++;

		switch(mode)
		{
		case PUSH_PULL_OUT:
			port->CRH &= ~(1 << pin);
			pin++;
			port->CRH &= ~(1 << pin);
			break;
		case OPEN_DRAIN_OUT:
			port->CRH |= (1 << pin);
			pin++;
			port->CRH &= ~(1 << pin);
			break;
		case ALTERNATIVE_PUSH_PULL_OUT:
			port->CRH &= ~(1 << pin);
			pin++;
			port->CRH |= (1 << pin);
			break;
		case ALTERNATIVE_OPEN_DRAIN_OUT:
			port->CRH |= (1 << pin);
			pin++;
			port->CRH |= (1 << pin);
			break;
		default: // PUSH_PULL_OUT
			port->CRH &= ~(1 << pin);
			pin++;
			port->CRH &= ~(1 << pin);
			break;
		}
	}
}

void setPinAsIn(GPIO_TypeDef *port, uint8_t pin, inMode_t mode)
{
	if(pin <= 7)
	{
		pin *= 4;

		port->CRL &= ~(1 << pin);
		pin++;
		port->CRL &= ~(1 << pin);
		pin++;

		switch(mode)
		{
		case ANALOG_IN:
			port->CRL &= ~(1 << pin);
			pin++;
			port->CRL &= ~(1 << pin);
			break;
		case FLOAT_IN:
			port->CRL |= (1 << pin);
			pin++;
			port->CRL &= ~(1 << pin);
			break;
		case PULLED_DOWN_IN:
			port->CRL &= ~(1 << pin);
			pin++;
			port->CRL |= (1 << pin);
			break;
		case PULLED_UP_IN:
			port->CRL |= (1 << pin);
			pin++;
			port->CRL |= (1 << pin);
			break;
		default: // PULLED_UP_IN
			port->CRL &= ~(1 << pin);
			pin++;
			port->CRL &= ~(1 << pin);
			break;
		}
	}

	else
	{
		pin -= 8;
		pin *= 4;

		port->CRH &= ~(1 << pin);
		pin++;
		port->CRH &= ~(1 << pin);
		pin++;

		switch(mode)
		{
		case ANALOG_IN:
			port->CRH &= ~(1 << pin);
			pin++;
			port->CRH &= ~(1 << pin);
			break;
		case FLOAT_IN:
			port->CRH |= (1 << pin);
			pin++;
			port->CRH &= ~(1 << pin);
			break;
		case PULLED_DOWN_IN:
			port->CRH &= ~(1 << pin);
			pin++;
			port->CRH |= (1 << pin);
			break;
		case PULLED_UP_IN:
			port->CRH |= (1 << pin);
			pin++;
			port->CRH |= (1 << pin);
			break;
		default: // PULLED_UP_IN
			port->CRH &= ~(1 << pin);
			pin++;
			port->CRH &= ~(1 << pin);
			break;
		}
	}
}
