/**----------------------------------------------------------------------------
 
   \file main.cpp

--                                                                           --
--              ECEN 5803 Mastering Embedded System Architecture             --
--                  Project 1 Module 3                                       --
--                Microcontroller Firmware                                   --
--                      main.cpp                                            --
--                                                                           --
-------------------------------------------------------------------------------
--
--  Designed for:  University of Colorado at Boulder
--               
--                
--  Designed by:  Tim Scherr
--  Revised by:  Rahul Yamasani & Srivishnu Alvakonda
-- 
-- Version: 2.1
-- Date of current revision:  2017-09-20  
-- Target Microcontroller: Freescale MKL25ZVMT4 
-- Tools used:  ARM mbed compiler
--              ARM mbed SDK
--              Freescale FRDM-KL25Z Freedom Board
--               
-- 
-- Functional Description:  Main code file generated by mbed, and then
--                           modified to implement a super loop bare metal OS.
--
--      Copyright (c) 2015, 2016 Tim Scherr  All rights reserved.



--
*/

#define MAIN
#include "shared.h"
#undef MAIN


extern volatile uint16_t SwTimerIsrCounter; 

//DigitalOut greenLED(LED2);
//DigitalOut blueLED(LED3);

Ticker tick;             //  Creates a timer interrupt using mbed methods
 /****************      ECEN 5803 add code as indicated   ***************/
                // Add code to control red, green and blue LEDs here
                                                    

Timer timer2;

Serial pc(USBTX, USBRX);     

/*
SPI lcd(PTC4, PTC5, PTC6, PTC7); // mosi, miso, sclk
*/ 
void flip()  
{                
    //greenLED = !greenLED;
}
 
__asm int read_reg0(){
    BX LR
}
__asm int read_reg1(){
    MOV R0,R1
    BX LR
}
__asm int read_reg2(){
    MOV R0,R2
    BX LR
}
__asm int read_reg3(){
    MOV R0,R3
    BX LR
}
__asm int read_reg4(){
    MOV R0,R4
    BX LR
}
__asm int read_reg5(){
    MOV R0,R5
    BX LR
}
__asm int read_reg6(){
    MOV R0,R6
    BX LR
}
__asm int read_reg7(){
    MOV R0,R7
    BX LR
}
__asm int read_reg8(){
    MOV R0,R8
    BX LR
}
__asm int read_reg9(){
    MOV R0,R9
    BX LR
}
__asm int read_reg10(){
    MOV R0,R10
    BX LR
}
__asm int read_reg11(){
    MOV R0,R11
    BX LR
}
__asm int read_reg12(){
    MOV R0,R12
    BX LR
}
__asm int read_reg13(){
    MOV R0,R13
    BX LR
}
__asm int read_reg14(){
    MOV R0,R14
    BX LR
}
__asm int read_reg15(){
    MOV R0,R15
    BX LR
}

  

void display_registers(void)
{
  
    int r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r13,r14,r15;
    r0 = read_reg0();
    pc.printf(" \n \r r0 %x \n\r", r0);
    r1 = read_reg1();
    pc.printf(" r1 %x \n\r", r1);
    r2 = read_reg2();
    pc.printf(" r2 %x \n\r", r2);
    r3 = read_reg3();
    pc.printf(" r3 %x \n\r", r3);
    r4 = read_reg4();
    pc.printf(" r4 %x \n\r", r4);
    r5 = read_reg5();
    pc.printf(" r5 %x \n\r", r5);
    r6 = read_reg6();
    pc.printf(" r6 %x \n\r", r6);
    r7 = read_reg7();
    pc.printf(" r7 %x \n\r", r7);
    r8 = read_reg8();
    pc.printf(" r8 %x \n\r", r8);
    r9 = read_reg9();
    pc.printf(" r9 %x \n\r", r9);
    r10 = read_reg10();
    pc.printf(" r10 %x \n\r", r10);
    r11 = read_reg11();
    pc.printf(" r11 %x \n\r", r11);
    r12 = read_reg12();
    pc.printf(" r12 %x \n\r", r12);
    r13 = read_reg13();
    pc.printf(" r13 %x \n\r", r13);
    r14 = read_reg14();
    pc.printf(" r14 %x \n\r", r14);
    r15 = read_reg15();
    pc.printf(" r15 %x \n\r", r15);
}
 
void read_memory(void)
{
  int mem_value;
  int i=0;
  for (i=0;i<10;i++)
  {
    mem_value = *(char*)(0x00000000+i);  
    pc.printf("\r\n memory value at 0x%p: %x\n\r", i, mem_value);
  }
}   
int main() 
{
/****************      ECEN 5803 add code as indicated   ***************/
                    //  Add code to call timer0 function every 100 uS

    pc.printf("Hello World!\n"); 
    uint32_t  count = 0;   
    
    tick.attach(&timer0, 0.0001);
// initialize serial buffer pointers
   rx_in_ptr =  rx_buf; /* pointer to the receive in data */
   rx_out_ptr = rx_buf; /* pointer to the receive out data*/
   tx_in_ptr =  tx_buf; /* pointer to the transmit in data*/
   tx_out_ptr = tx_buf; /* pointer to the transmit out */
    
   
  // Print the initial banner
    pc.printf("\r\nHello World!\n\n\r");

    /****************      ECEN 5803 add code as indicated   ***************/
    // uncomment this section after adding monitor code.  
   /* send a message to the terminal  */                    
   
   UART_direct_msg_put("\r\nSystem Reset\r\nCode ver. ");
   UART_direct_msg_put( CODE_VERSION );
   UART_direct_msg_put("\r\n");
   UART_direct_msg_put( COPYRIGHT );
   UART_direct_msg_put("\r\n");

   set_display_mode();                                      
    //
    
    
    
    while(1)       /// Cyclical Executive Loop
    {

        count++;               // counts the number of times through the loop
//      __enable_interrupts();
//      __clear_watchdog_timer();

   /****************      ECEN 5803 add code as indicated   ***************/
    // uncomment this section after adding monitor code. 
    
        serial();            // Polls the serial port
        chk_UART_msg();     // checks for a serial port message received
        monitor();           // Sends serial port output messages depending
                         //     on commands received and display mode
        
        
        
        if ((SwTimerIsrCounter & 0x1FFF) > 0x0FFF)
    
        {
            flip();  // Toggle Green LED
        }
   
    } 
       
}

