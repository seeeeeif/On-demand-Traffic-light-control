/*
 * Gpio.h
 *
 * Created: 1/12/2023 2:55:19 AM
 *  Author: RGB
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#include "../../Utilites/types.h"
#include "../../Utilites/Commen_macro.h"
#include "../../Utilites/macro_Config.h"
#include <avr/io.h>

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/


#define PORT_A               0
#define PORT_B               1
#define PORT_C               2
#define PORT_D               3

#define PIN_0                0
#define PIN_1                1
#define PIN_2                2
#define PIN_3                3
#define PIN_4                4
#define PIN_5                5
#define PIN_6                6
#define PIN_7                7


typedef enum
{
	PIN_INPUT,PIN_OUTPUT
}GPIO_PinDirectionType;

typedef enum
{
	PORT_INPUT,PORT_OUTPUT=0xFF
}GPIO_PortDirectionType;

void DIO_init(uint8 portNumber, uint8 pinNumber, GPIO_PinDirectionType direction);


void DIO_write(uint8 portNumber, uint8 pinNumber, uint8 value);

uint8 DIO_read(uint8 portNumber, uint8 pinNumber);

void DIO_setupPortDirection(uint8 portNumber, uint8 direction);

void DIO_writePort(uint8 portNumber, uint8 value);

uint8 DIO_readPort(uint8 portNumber);

void DIO_toggle(uint8_t portNumber, uint8_t pinNumber);

#endif /* GPIO_H_ */