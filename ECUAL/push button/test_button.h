/*
 * test_button.h
 *
 * Created: 1/12/2023 3:00:44 AM
 *  Author: RGB
 */ 


#ifndef TEST_BUTTON_H_
#define TEST_BUTTON_H_

//Here we make a test for LEDS & Push button
#include "button.h"
#include "../LEDS/LED.h"

void Testing_Push_Button_and_LEDS ()
{
	// TESTING Buttons DRIVER ////
	ledInit (PORT_C,PIN_5);
	Button_Init(PORT_D, PIN_2);

	while (1)
	{
		uint8_t button_state ;
		BUTTON_READ(PORT_D, PIN_2, &button_state );

		if (button_state == 1)
		{
			ledOn(PORT_C,PIN_5);
		}
		else if (button_state == 0)
		{
			ledOff (PORT_C,PIN_5);
		}

	}
}



#endif /* TEST_BUTTON_H_ */