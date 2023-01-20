/*
 * Gpio.c
 *
 * Created: 1/12/2023 2:55:35 AM
 *  Author: RGB
 */ 

#include "Gpio.h"

void DIO_init(uint8 portNumber, uint8 pinNumber, GPIO_PinDirectionType direction)
{
	

		/* Setup the pin direction as required */
		switch(portNumber)
		{
		case PORT_A:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRA,pinNumber);
			}
			else
			{
				CLEAR_BIT(DDRA,pinNumber);
			}
			break;
		case PORT_B:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRB,pinNumber);
			}
			else
			{
				CLEAR_BIT(DDRB,pinNumber);
			}
			break;
		case PORT_C:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRC,pinNumber);
			}
			else
			{
				CLEAR_BIT(DDRC,pinNumber);
			}
			break;
		case PORT_D:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRD,pinNumber);
			}
			else
			{
				CLEAR_BIT(DDRD,pinNumber);
			}
			break;
		}
	
}


void DIO_write(uint8 portNumber, uint8 pinNumber, uint8 value)
{

		switch(portNumber)
		{
		case PORT_A:
			if(value == HIGH)
			{
				SET_BIT(PORTA,pinNumber);
			}
			else
			{
				CLEAR_BIT(PORTA,pinNumber);
			}
			break;

		case PORT_B:
			if(value == HIGH)
			{
				SET_BIT(PORTB,pinNumber);
			}
			else
			{
				CLEAR_BIT(PORTB,pinNumber);
			}
			break;
		case PORT_C:
			if(value == HIGH)
			{
				SET_BIT(PORTC,pinNumber);
			}
			else
			{
				CLEAR_BIT(PORTC,pinNumber);
			}
			break;
		case PORT_D:
			if(value == HIGH)
			{
				SET_BIT(PORTD,pinNumber);
			}
			else
			{
				CLEAR_BIT(PORTD,pinNumber);
			}
			break;
		}
	
}

uint8 DIO_read(uint8 portNumber, uint8 pinNumber)
{
	uint8 pin_value = LOW;


		switch(portNumber)
		{
		case PORT_A:
			if(BIT_IS_SET(PINA,pinNumber))
			{
				pin_value = HIGH;
			}
			else
			{
				pin_value = LOW;
			}
			break;

		case PORT_B:
			if(BIT_IS_SET(PINB,pinNumber))
			{
				pin_value = HIGH;
			}
			else
			{
				pin_value = LOW;
			}
			break;
		case PORT_C:
			if(BIT_IS_SET(PINC,pinNumber))
			{
				pin_value = HIGH;
			}
			else
			{
				pin_value = LOW;
			}
			break;
		case PORT_D:
			if(BIT_IS_SET(PIND,pinNumber))
			{
				pin_value = HIGH;
			}
			else
			{
				pin_value = LOW;
			}
			break;
		}
	
	return pin_value;
}

void DIO_setupPortDirection(uint8 portNumber, uint8 direction)
{

		/* Setup the port direction as required */
		switch(portNumber)
		{
		case PORT_A:
			DDRA = direction;
			break;
		case PORT_B:
			DDRB = direction;
			break;
		case PORT_C:
			DDRC = direction;
			break;
		case PORT_D:
			DDRD = direction;
			break;
		}
	
}

void DIO_writePort(uint8 portNumber, uint8 value)
{

		switch(portNumber)
		{
		case PORT_A:
			PORTA = value;
			break;

		case PORT_B:
			PORTB = value;
			break;

		case PORT_C:
			PORTC = value;
			break;

		case PORT_D:
			PORTD = value;
			break;
		}
	
}

uint8 DIO_readPort(uint8 portNumber)
{
	uint8 value = LOW;

		switch(portNumber)
		{
		case PORT_A:
			value = PINA;
			break;

		case PORT_B:
			value = PINB;
			break;

		case PORT_C:
			value = PINC;
			break;

		case PORT_D:
			value = PIND;
			break;
		}
	
	return value;
}

void DIO_toggle(uint8 portNumber, uint8 pinNumber)
{
	switch(portNumber){
		case PORT_A:
	 TOGGLE_BIT(PORTA,pinNumber);
		break;
		case PORT_B:
		TOGGLE_BIT(PORTB,pinNumber);
		break;
		case PORT_C:
		TOGGLE_BIT(PORTC,pinNumber);
		break;
		case PORT_D:
		TOGGLE_BIT(PORTD,pinNumber);
		break;
	}
}
