/*----------------------------------------------------------------------------
LAB EXERCISE 11.1 - SPI interface
SERIAL COMMUNICATION
 ----------------------------------------
 Interface the LCD display using SPI protocol: display four checks (size 10x10
 pixels) at four corners of the LCD.
 
 Input: None
 Output: LCD display
	
	GOOD LUCK!
 *----------------------------------------------------------------------------*/

#include "mbed.h"
#include "NHD_0216HZ.h"

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/
DigitalOut led(LED1);

int main() {
  	init_spi();
  	init_lcd();
    
  	print_lcd("joyce");
	set_cursor(0,1);
	print_lcd("hello");
	//clr_lcd();
	while(1)
	{
	  led=!led;
		wait(1);
	}
}

// *******************************ARM University Program Copyright (c) ARM Ltd 2014*************************************

