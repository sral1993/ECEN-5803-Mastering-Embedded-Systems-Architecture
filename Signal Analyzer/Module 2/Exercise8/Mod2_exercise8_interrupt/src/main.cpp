/*----------------------------------------------------------------------------
LAB EXERCISE 8.2 - INTERRUPT IN/OUT
PROGRAMMING USING MBED API
 ----------------------------------------
 In this exercise you need to use the mbed API functions to:
 
	1) Define InterruptIn and ISR for the button press
	2) In the interrupt service routine, the LED is used to indicate when a
	button was pressed:
			+ USER_BUTTON - LED1

	3) Put the processor into sleep mode upon exiting from the ISR
			
	GOOD LUCK!
 *----------------------------------------------------------------------------*/

#include "mbed.h"

// LED states (all direct driven)
#define LED_ON   1
#define LED_OFF  0

//Define outputs
DigitalOut LD2(PA_5);
DigitalOut EXT_LED(PA_9);
//BusOut Led(LED1, PA_9);


//Define interrupt inputs
InterruptIn button1(PA_10);
InterruptIn button2(PB_3);
InterruptIn button3(PB_5);
InterruptIn button4(PB_4);


//Define ISRs for the interrupts
void button_1_handler(){
	
	LD2 = LED_ON;
 
}

void button_2_handler(){
	
	LD2 = LED_OFF;

	
}

void button_3_handler(){
	
	EXT_LED = LED_ON;

	
}

void button_4_handler(){
	
	EXT_LED = LED_OFF;
	
}

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
	
	__enable_irq();			//enable interrupts
	
	//initially turn off  LED
	LD2 = LED_OFF;
  	EXT_LED = LED_OFF;
	
	//Interrupt handlers
	//Attach the address of the ISR to the rising edge
	button1.rise(&button_1_handler);
  	button2.rise(&button_2_handler);
  	button3.rise(&button_3_handler);
  	button4.rise(&button_4_handler);

	//__wfi();
	//Sleep on exit
	while(1){
		
		sleep();
	
	}
}

// *******************************ARM University Program Copyright (c) ARM Ltd 2014*************************************

