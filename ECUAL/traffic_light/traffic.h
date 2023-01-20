/*
 * traffic.h
 *
 * Created: 1/16/2023 6:05:57 PM
 *  Author: RGB
 */ 


#ifndef TRAFFIC_H_
#define TRAFFIC_H_


#include "../../ECUAL/leds/led.h"
#include "../../MCAL/TIMER/timer.h"
#include "../../MCAL/INT/int.h"
#include "../../ECUAL/push button/button.h"

 typedef unsigned char boolean;
 
 void traffic_init(void);
 void traffic_nornal(void);
 void traffic_ped(void);
void Blinking_yellow ();
void PED_Mood();
#endif /* TRAFFIC_H_ */