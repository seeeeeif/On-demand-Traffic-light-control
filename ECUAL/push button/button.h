/*
 * button.h
 *
 * Created: 1/12/2023 3:00:05 AM
 *  Author: RGB
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/GPIO/Gpio.h"

void Button_Init(uint8 portNumber  ,uint8 pinNumber );
void BUTTON_READ(uint8 portNumber, uint8 pinNumber, uint8 * value);



#endif /* BUTTON_H_ */