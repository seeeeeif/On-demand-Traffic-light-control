/*
 * traffic.c
 *
 * Created: 1/16/2023 6:07:16 PM
 *  Author: RGB
 */ 
#include "traffic.h" 
boolean Yellow_is_blinking=0;
boolean buttonClick =0;
uint8 red_flag =0;
uint8 yellow_flag =0;
uint8 green_flag =0;
uint8 counter =0;
 void traffic_init(void)
 {
	 	// Initializing Direction and Value of LED DIO PINS
	 	//car_LEDS
	 	ledInit(PORT_A,PIN_0); //green
	 	ledInit(PORT_A,PIN_1); //Yellow
	 	ledInit(PORT_A,PIN_2); //red

	 	//pedestrian_LEDS
	 	ledInit(PORT_B,PIN_0); //green
	 	ledInit(PORT_B,PIN_1); //Yellow
	 	ledInit(PORT_B,PIN_2); //red

	 	// initializing Interrupt Button Pin
	 	//PushButtonInit(PORTD_ID,PIN2_ID); //INT0


	 	//Initializing INTERRUPT 0
	 	Exi0Init();
	 	//Enable INTERRUPT 0
	 	Exi0Enable();
 }
 void traffic_nornal(void)
 {
	/* // Green led for cars & Red led for ped. is on for five seconds
	 ledOn(PORT_A,PIN_0);
	 ledOn(PORT_B,PIN_2);
	 buttonClick=1;
	 Timer0_Delay(20);

	 // After 5 second  Green led for cars & Red led for ped. switched OFF
	 // And yellow LEDs of both will blinking for five second
	 ledOff(PORT_A,PIN_0);
	 ledOff(PORT_B,PIN_2);
	 buttonClick=0;
	 Blinking_yellow();
	 ledOff(PORT_A,PIN_1);
	 ledOff(PORT_B,PIN_1);


	 // After yellow blinking for 5 seconds
	 // Red led for cars & green led for ped. is on for five seconds
	 // then yellow blinking again

	 ledOn(PORT_A,PIN_2);
	 ledOn(PORT_B,PIN_0);
	 Timer0_Delay(20);               
	 ledOff(PORT_A,PIN_2);
	 ledOff(PORT_B,PIN_0);

	 Blinking_yellow();

	 ledOff(PORT_A,PIN_1);
	 ledOff(PORT_B,PIN_1);
*/
red_flag=1;
// LED RED CAR ON
ledOn(PORT_A,PIN_0);
// LED RED PEPOLE OFF
ledOff(PORT_B,PIN_0);
// LED GREEN PEPOLE ON
ledOn(PORT_B,PIN_2);

// DELAY 5 sec
Timer0_Delay(20);
// LED RED CAR OFF
ledOff(PORT_A,PIN_0);
// LED GREEN PEPOLE OFF
ledOff(PORT_B,PIN_2);
red_flag=0;

yellow_flag=1;
for(counter=0;counter<10;counter++)
{
	ledToggle(PORT_A,PIN_1);
	ledToggle(PORT_B,PIN_1);
	Timer0_Delay(2);
}
ledOff(PORT_A,PIN_1);
ledOff(PORT_B,PIN_1);
yellow_flag=0;

green_flag=1;
ledOn(PORT_A,PIN_2);
ledOn(PORT_B,PIN_0);
// DELAY 5 sec
Timer0_Delay(20);
ledOff(PORT_A,PIN_2);
ledOff(PORT_B,PIN_0);
green_flag=0;

yellow_flag=1;
for(counter=0;counter<10;counter++)
{
	ledToggle(PORT_A,PIN_1);
	ledToggle(PORT_B,PIN_1);
	Timer0_Delay(2);
}
ledOff(PORT_A,PIN_1);
ledOff(PORT_B,PIN_1);
yellow_flag=0;


 } 
/* void Blinking_yellow()
 {

	 Yellow_is_blinking = 1;

	 ledToggle(PORT_A,PIN_1);
	 ledToggle(PORT_B,PIN_1);  // YELLOW LED FOR PEDESTRIANS
	 Timer0_Delay(5);

	 ledToggle(PORT_A,PIN_1);
	 ledToggle(PORT_B,PIN_1);  // YELLOW LED FOR PEDESTRIANS
	 Timer0_Delay(5);

	 ledToggle(PORT_A,PIN_1);
	 ledToggle(PORT_B,PIN_1);   // YELLOW LED FOR PEDESTRIANS
	 Timer0_Delay(5);

	 ledToggle(PORT_A,PIN_1);
	 ledToggle(PORT_B,PIN_1);   // YELLOW LED FOR PEDESTRIANS
	 Timer0_Delay(5);

	 ledToggle(PORT_A,PIN_1);
	 ledToggle(PORT_B,PIN_1); // YELLOW LED FOR PEDESTRIANS
	 Timer0_Delay(5);

	 Yellow_is_blinking = 0;
 }
*/
 void traffic_ped(void)
 { 
	 /*
	 //BIT_IS_SET(PORTA_ID,PIN2_ID)
	   if (buttonClick==1)  // check if the button is pressed when the cars' RED LED is on
		 {
		   ledOff(PORT_A,PIN_0);  // GREEN LED FOR CARS
		   Blinking_yellow ();
		   ledOff(PORT_A,PIN_1);  // YELLOW LED FOR CARS
		   ledOff(PORT_B,PIN_1);  // YELLOW LED FOR PEDESTRIANS
		   ledOff(PORT_B,PIN_2); // RED LED FOR PEDSTRAINS
		   ledOn(PORT_A,PIN_2);  // RED LED FOR CARS
		   ledOn(PORT_B,PIN_0);  // GREEN LED FOR PEDSTRAINS
	     	 Timer0_Delay(20);

		 }

	         SECOND CASE:
		      If BUTTON is pressed when the cars' Green LED is on or the cars' Yellow LED is blinking,
		

	else if( BIT_IS_SET(PORT_A,PIN_0) ||   Yellow_is_blinking ==1){
		 // the pedestrian Red LED will be on
				 ledOff(PORT_A,PIN_0);  // GREEN LED FOR CARS
				 ledOn(PORT_B,PIN_2);  // RED LED FOR PEDESTRIANS

		// then both Yellow LEDs start to blink for five seconds,
			    Blinking_yellow ();
			    ledOff(PORT_A,PIN_1);  // YELLOW LED FOR CARS
			    ledOff(PORT_B,PIN_1);  // YELLOW LED FOR PEDESTRIANS
			    ledOff(PORT_B,PIN_2);  // RED LED FOR PEDESTRIANS
		// then the cars' Red LED and pedestrian Green LEDs are on for five seconds,
				 ledOn(PORT_A,PIN_2);  // RED LED FOR CARS
				 ledOn(PORT_B,PIN_0);  // GREEN LED FOR PEDESTRIANS
				 Timer0_Delay(20);
	}

	// 	 At the end of the two states :
	// 	 the cars' Red LED will be off and both Yellow LEDs start blinking for 5 seconds
	// 	 and the pedestrian's Green LED is still on
            ledOff(PORT_B,PIN_0);  // GREEN LED FOR PEDESTRIANS 
	        ledOff(PORT_A,PIN_2);  // RED LED FOR CARS
			Blinking_yellow ();
			ledOff(PORT_A,PIN_1);  // YELLOW LED FOR CARS
			ledOff(PORT_B,PIN_1);  // YELLOW LED FOR PEDESTRIANS

	//   After 5 seconds the pedestrian Green LED will be off
	//   and both the pedestrian Red LED and the cars' Green LED will be on.
		  ledOff(PORT_B,PIN_0);  // GREEN LED FOR PEDESTRIANS

		  ledOn(PORT_A,PIN_0);  // GREEN LED FOR CARS
		  ledOn(PORT_B,PIN_2);  // RED LED FOR PEDESTRIANS
		  Timer0_Delay(20);
		  ledOff(PORT_A,PIN_0);  // GREEN LED FOR CARS
		  ledOff(PORT_B,PIN_2);  // RED LED FOR PEDESTRIANS
		  ledOff(PORT_B,PIN_0);  // GREEN LED FOR PEDESTRIANS
		 */ 
		if(red_flag==1)
		{
			// LED RED CAR ON
			ledOn(PORT_A,PIN_0);
			// LED RED PEPOLE OFF
			ledOff(PORT_B,PIN_0);
			// LED GREEN PEPOLE ON
			ledOn(PORT_B,PIN_2);
			
			// DELAY 5 sec
			Timer0_Delay(20);
			// LED RED CAR OFF
			ledOff(PORT_A,PIN_0);
			// LED GREEN PEPOLE OFF
			ledOff(PORT_B,PIN_2);
		}
		else if(yellow_flag==1 ||green_flag==1)
		{
			// yellow car and people
			ledOff(PORT_A,PIN_1);
			ledOff(PORT_B,PIN_1);
			
			ledOff(PORT_A,PIN_2);
			ledOff(PORT_B,PIN_0);
			
			ledOn(PORT_A,PIN_1);
			for(counter=0;counter<10;counter++)
			{
				ledToggle(PORT_A,PIN_1);
				ledToggle(PORT_B,PIN_1);
				Timer0_Delay(2);
			}
			
			ledOff(PORT_A,PIN_1);
			ledOff(PORT_B,PIN_1);
			
			// LED RED CAR ON
			ledOn(PORT_A,PIN_0);
			// LED RED PEPOLE OFF
			ledOff(PORT_B,PIN_0);
			// LED GREEN PEPOLE ON
			ledOn(PORT_B,PIN_2);
			
			// DELAY 5 sec
			Timer0_Delay(20);
			// LED RED CAR OFF
			ledOff(PORT_A,PIN_0);
			// LED GREEN PEPOLE OFF
			ledOff(PORT_B,PIN_2);
		}

 }
