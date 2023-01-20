/*
 * app.c
 *
 * Created: 1/12/2023 2:58:58 AM
 *  Author: RGB
 */ 

#include "app.h"


void app_inits(void) 
{
    traffic_init();
}

void app_start(void)
{
    traffic_nornal();
}



ISR (INT0_vect)
{
	traffic_ped();

}
