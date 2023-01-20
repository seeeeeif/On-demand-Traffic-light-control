/*
 * led.h
 *
 * Created: 1/12/2023 2:59:26 AM
 *  Author: RGB
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/GPIO/Gpio.h"

void ledInit(uint8  portNumber  ,uint8 pinNumber );

void ledOn(uint8  portNumber  ,uint8 pinNumber);

void ledOff(uint8  portNumber  ,uint8 pinNumber);

void ledToggle (uint8 portNumber  , uint8 pinNumber);



#endif /* LED_H_ */