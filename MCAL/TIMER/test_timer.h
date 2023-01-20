/*
 * test_timer.h
 *
 * Created: 1/12/2023 2:57:46 AM
 *  Author: RGB
 */ 


#ifndef TEST_TIMER_H_
#define TEST_TIMER_H_


#include"TIMER.h"
#include "../../ECUAL/LEDS/LED.h"

void Testing_Timers(void)
{
	ledInit (PORT_C,PIN_5);
	while (1)
	{
		ledOff(PORT_C,PIN_5);
		Timer0_Delay(20);
		ledOn(PORT_C,PIN_5);
		Timer0_Delay(20);
	}
}




#endif /* TEST_TIMER_H_ */