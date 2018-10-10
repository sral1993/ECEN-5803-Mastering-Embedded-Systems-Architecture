/*

REFERENCES:
1.  https://os.mbed.com/components/FRDM-KL25Z-on-board-Accelerometer/
2.  https://os.mbed.com/components/FRDM-KL25Z-onboard-Capacitive-Touch-Sens/

for the submission of Module 2 for ECEN 5803 Project 1 
by Srivishnu Alvakonda & Rahul Yamasani

*/


#include "mbed.h"
#include "MMA8451Q.h"
#include "TSISensor.h"

Timer timer;
Timer timer2;
Serial pc(USBTX, USBRX);     

#define MMA8451_I2C_ADDRESS (0x1d<<1)
 
int main(void) 
{
    MMA8451Q acc(PTE25, PTE24, MMA8451_I2C_ADDRESS);
    PwmOut rled(LED_RED);
    PwmOut gled(LED_GREEN);
    PwmOut bled(LED_BLUE);
    TSISensor tsi;
    timer.start();
    timer2.start();
    double timer_read = 0.0;
    double timer_read2 = 0.0;
    
   int i = 0;
    while (true) 
    {               
        timer.reset();        
        rled = 1.0 - abs(acc.getAccX());
        gled = 1.0 - abs(acc.getAccY());
        bled = 1.0 - abs(acc.getAccZ());
        gled = 1.0 - tsi.readPercentage();
        timer_read += timer.read();
        wait(0.1);
        
        i++;
        
        if (i==100)
        {
            timer_read2 = timer2.read();
            pc.printf("\n\rCPU Load Execution time: %f\n\r", timer_read);
            pc.printf("Total Program Execution time: %f\n\r\n\r", timer_read2);
            
            double processor_load = double(timer_read/timer_read2);
            processor_load *= 100;
            pc.printf("RESULT\n\r");
            pc.printf("Processor load in percentage of CPU cycles %f\n\r", processor_load);
            pc.printf("CPU available percentage is %f\n\r", 100.0 - processor_load);
        }
    }    

}
