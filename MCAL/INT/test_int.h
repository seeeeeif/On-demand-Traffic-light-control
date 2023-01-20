/*
 * test_int.h
 *
 * Created: 1/12/2023 2:56:41 AM
 *  Author: RGB
 */ 


#ifndef TEST_INT_H_
#define TEST_INT_H_

#include "../../ECUAL/leds/led.h"
#include "../TIMER/timer.h"
#include "int.h"
#include "../../ECUAL/push button/button.h"

void Test_INT()
{

	ledInit (PORT_C,PIN_5);
	Button_Init(PORTD, PIN_2);
	Exi0Init();
	Exi0Enable();
	ledOn(PORT_C,PIN_5);

}



#endif /* TEST INT_H_ */