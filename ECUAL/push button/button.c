/*
 * button.c
 *
 * Created: 1/12/2023 3:00:21 AM
 *  Author: RGB
 */ 
#include "button.h"

void Button_Init(uint8 portNumber  ,uint8 pinNumber )
{
	DIO_init( portNumber,  pinNumber, 0);
}

void BUTTON_READ(uint8 portNumber, uint8 pinNumber, uint8 * value)
{
	DIO_read(portNumber, pinNumber );
}