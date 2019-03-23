/*
 * gpio.h
 *
 *  Created on: Mar 23, 2019
 *      Author: dev1
 */

#ifndef GPIO_H_
#define GPIO_H_

typedef enum{SPEED_10_MHZ, SPEED_2_MHZ, SPEED_50_MHZ} speed_t;
typedef enum{PUSH_PULL_OUT, OPEN_DRAIN_OUT, ALTERNATIVE_PUSH_PULL_OUT, ALTERNATIVE_OPEN_DRAIN_OUT} outMode_t;
typedef enum{ANALOG_IN, FLOAT_IN, PULLED_DOWN_IN, PULLED_UP_IN} inMode_t;

void setPinAsOut(GPIO_TypeDef *port, uint8_t pin, outMode_t mode, speed_t speed);
void setPinAsIn(GPIO_TypeDef *port, uint8_t pin, inMode_t mode);

#endif /* GPIO_H_ */
