/*
 * traffic light.c
 *
 * Created: 1/12/2023 2:47:26 AM
 * Author : RGB
 */ 

#include "APP/APP.h"
#include "MCAL/TIMER/Test_TIMER.h"
#include "MCAL/INT/Test_INT.h"
#include "ECUAL/push button/test_button.h"

int main(void){

	app_inits();

	 while(1)
	 {
	 	app_start();
	 }

	//Testing_Timers();
    //Test_INT();
	//Testing_Push_Button_and_LEDS();
}

