/*----------------------------------------------------------------------------
LAB EXERCISE 12 - Real-Time Operating System
 ----------------------------------------
    Integrate functions developed in previous modules and run then concurrently
    in the mbed RTOS. The following four threads have to be implemented:
    
    1. Display the temperature on the LCD and to the PC
    2. Adjust the brightness of the RGB LED using a potentiometer
    3. Display an incrementing counter on the LCD and to the PC
    4. Blink an LED
  
  NOTE:  For this lab, the LCD, temp sensor and potentiometer are virtual devices.

    GOOD LUCK!
 *----------------------------------------------------------------------------*/

/*

Reference : https://os.mbed.com/handbook/RTOS

*/


#include "mbed.h"
#include "rtos.h"
#include "DS1631.h"
#include "NHD_0216HZ.h"
#include "pindef.h"

/*
Define the mutex
Define the LCD display and the temperature sensor
Define other inputs and outputs
*/

DigitalOut led2(LED1);
PwmOut External_LED(PA_9);
AnalogIn potentiometer(PA_0);  // potentiometer

Thread Display_Temperature_Thread1;
Thread Change_Led_Brightness_Thread2;
Thread Increasing_Counter_Thread3;
Thread Blink_LED_Thread4;

//Initialzie Temp and lcd
#define TEMP_SENSOR_ADDR 0x90
NHD_0216HZ lcd(SPI_CS, SPI_MOSI, SPI_SCLK);
DS1631 temperature_sensor(I2C_SDA, I2C_SCL, TEMP_SENSOR_ADDR);

// Semaphores to signal that the operation of particular thread is complete

Semaphore Temperature_Potentiometer(0);
Semaphore Potentiometer_Count(0);
Semaphore Count_Blink(0);
Semaphore Blink_Temperature(0);

//Mutex - to share a common resource between different threads. Mutex lock and Mutex unlock are used
Mutex Mutex_LCD;
unsigned int count = 0; 
//Display temperature on the LCD
void Temperature_Thread(void const *args){
    
    //write your code here
    float temp = 0.0;
    while(true)
    {
        
        Blink_Temperature.wait(osWaitForever);
        temp = temperature_sensor.read();
        printf("Temperature= %0.1f\n\r", temp);
        
        Mutex_LCD.lock();
        lcd.set_cursor(0,1);
        lcd.printf("Temperature=%0.1f", temp);
        
        Mutex_LCD.unlock();      
        
        Temperature_Potentiometer.release();    
    }
    
}

//Adjust the brightness of the RGB LED
void LED_Brightness_Adjust_Thread(void const *args){
    
    //write your code here
    while(true)
    {
        Temperature_Potentiometer.wait(osWaitForever);
        External_LED.write(potentiometer.read());   
        Potentiometer_Count.release();
    }
    
}


//Display a counter on the LCD
void Increasing_Counter_Thread(void const *args){
    
    //write your code here
    while(true)
    {
       
        Potentiometer_Count.wait(osWaitForever);
        Mutex_LCD.lock();
        lcd.set_cursor(0,0);
        lcd.printf("Count:%04u", count);
        printf("Count:%04u", count);
        count++;
        Mutex_LCD.unlock();
        Count_Blink.release();
          
    }
}

//Blink an LED
void Blinky_LED_Thread(void const *args){
    
    //write your code here
    while(true)
    {
        
        Count_Blink.wait(osWaitForever);
        led2 = 0;
        Thread::wait(500);
        led2 = 1;         
        Thread::wait(500);
        Blink_Temperature.release();
        
    }
    
}


/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
    /*
    Initialise and clear the LCD display
    Start all threads
    Wait for timer interrupt
    */
    
    //Initialise the LCD
    lcd.init_lcd();
    lcd.clr_lcd();    

    
    // Initialize all the threads
    Display_Temperature_Thread1.start(callback(Temperature_Thread, NULL));
    Change_Led_Brightness_Thread2.start(callback(LED_Brightness_Adjust_Thread, NULL));
    Increasing_Counter_Thread3.start(callback(Increasing_Counter_Thread, NULL));
    Blink_LED_Thread4.start(callback(Blinky_LED_Thread, NULL)); 
    
    Blink_Temperature.release();
    
    while(true)
    {
        __WFI();
    }
    
    
}

// *******************************ARM University Program Copyright (c) ARM Ltd 2014*************************************