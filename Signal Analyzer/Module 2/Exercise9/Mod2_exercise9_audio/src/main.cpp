/*----------------------------------------------------------------------------
LAB EXERCISE 9 - Analog input and PWM
 ----------------------------------------
	Use two potentiometers to adjust the volume and pitch of the output sound wave.
	
	Inputs: Virtual potentiometers 1 and 2
	Output: Virtual speaker,  Real PC

	GOOD LUCK!
 *----------------------------------------------------------------------------*/

#include "mbed.h"
#include "pindef.h"

/*
Define the PWM speaker output
Define analog inputs
Define serial output
*/

PwmOut speaker(PB_10);
AnalogIn volume(PA_0);//pot1
AnalogIn pitch(PA_1);//pot2
Serial pc(USBTX, USBRX);


//Define variables
float volume_data, pitch_data;
float a = 0.003;
float b = 0.000125;

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
	while(1){
		/*
		Print values of the potentiometers to the PC serial terminal
		Create a saw-tooth sound wave
		Make the period and volume adjustable using the potentiometers
		*/
		
	    	volume_data = volume.read();
		pitch_data = pitch.read();
		pc.printf("pot1 value = %f\r\n", volume_data);
		pc.printf("pot2 value = %f\r\n", pitch_data);
		wait(1);

		//for loop that creates the saw tooth wave
		//linear function a*pitch+b sets the frequency
		//a and b are set to be 8kHz at 0 and 320Hz at 1
		for(float i = 0; i < volume_data; i+=0.05){
			speaker = i;
			speaker.period(a* pitch_data + b);
			//speaker.period(pitch_data/1000);
			wait(0.01);
		}
		
	}
}

// *******************************ARM University Program Copyright � ARM Ltd 2014*************************************


