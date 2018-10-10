/*----------------------------------------------------------------------------
LAB EXERCISE 8.1 - DIGITAL INPUTS AND OUTPUTS
PROGRAMMING USING MBED API
 ----------------------------------------
 In this exercise you need to use the mbed API functions to:
 
	1) Define BusIn, BusOut interfaces for inputs and outputs
	2) The LED is controlled by the button:
			+ USER_BUTTON - LED1
			
	GOOD LUCK!
 *----------------------------------------------------------------------------*/

#include "mbed.h"

// Input bus selectors
#define BUTTON1  0x1
#define BUTTON2  0x2
#define BUTTON3  0x4
#define BUTTON4  0x8

// Output bus selectors
#define LED_LD2  0x1
#define LED_EXT  0x2

// Button states (all pulled up to 3.3V)
#define BUTTON_DOWN  0
#define BUTTON_UP    1

//Define input bus
BusIn Button(PA_10,PB_3,PB_5,PB_4);

//Define output bus for the  LED
BusOut LED(PA_5, PA_9);



/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){

	int inputs;  // value from input bus
	int outputs; // value for output bus

	while(1){
		
		//Check which button was pressed and light up the corresponding LED
    		inputs = Button.read(); 
    		if((inputs & BUTTON1) == BUTTON_DOWN) {
      			SET_BIT(outputs, LED_LD2);
    		}	
    		if((inputs & BUTTON2) == BUTTON_DOWN) {
      			CLEAR_BIT(outputs, LED_LD2);
    		}
    		if((inputs & BUTTON3) == BUTTON_DOWN) {
      			SET_BIT(outputs, LED_EXT);
    		}
    		if((inputs & BUTTON4) == BUTTON_DOWN) {
      			CLEAR_BIT(outputs, LED_EXT); 
    		}
		LED = outputs;
		
	}
}

// *******************************ARM University Program Copyright (c) ARM Ltd 2014*************************************

