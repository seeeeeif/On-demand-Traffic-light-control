/*
 * led.c
 *
 * Created: 1/12/2023 2:59:12 AM
 *  Author: RGB
 */ 

#include "led.h"

void ledInit(uint8 portNumber  ,uint8 pinNumber ){

	DIO_init( portNumber,  pinNumber, 1);
}

void ledOn(uint8  portNumber ,uint8 pinNumber){

	DIO_write(portNumber,pinNumber, 1);       //Set the given pin in the given port to one(on)
}

void ledOff(uint8  portNumber  ,uint8 pinNumber){

	DIO_write( portNumber,  pinNumber ,0);      //Set the given pin in the given port to zero(off)
}

void ledToggle (uint8 portNumber  , uint8 pinNumber)
{
	DIO_toggle(portNumber,pinNumber);
}