#include "mbed.h"
Serial pc(USBTX, USBRX);  //serial channel over HDK USB interface
Timer timer;
/************************************************************************//**
* \file main.c
* \brief LAB EXERCISE 5.2 - SQUARE ROOT APPROXIMATION
*
* Write an assembly code subroutine to approximate the square root of an 
* argument using the bisection method. All math is done with integers, so the 
* resulting square root will also be an integer
******************************************************************************
* GOOD LUCK!
 ****************************************************************************/

 #include "stdint.h"
 
 
 /** @cond DO_NOT_INCLUDE_WITH_DOXYGEN */
 #include "string.h"
 /** @endcond */
 
 /**
 * @brief 5863 Write a brief description of the function here
 *
 * Detailed description of the function after one line gap
 *
 * @note You can also add a note this way
 *
 * @param[in] 
 *  You can also start writing on a new line. 
 *  And continue on the next line. This is how you describe an input parameter
 *
 * @return
 *  This is how you describe the return value
 * 
 */
 
__asm int my_sqrt(int x){
    
    
    PUSH {R4-R7} ;
    LDR R1, =0      ;done = 0
    LDR R7, =0 ;a=0
    LDR R2, =0xFFFF ;b=2^31 -1
    LDR R3, =0xFFFFFFFF ;c=-1
DO_WHILE
    MOV  R4, R3    ;c_old = c HERE R4 is being considered as c_old
    ADDS R5, R2, R7 ;R5 = a+b
    ASRS R5, R5, #1 ;R5 >> 1 which is nothing but (a+b/2) 
    MOV  R3, R5 ;c = (a+b)/2
    MOV  R6,R3
    MULS R6, R3, R6       ;R6 = c*c
    CMP  R6,R0 ;compare c*c and x (input integer)
    BEQ  DONE
    BLT LESS_THAN
    MOV  R2, R3 ;setting b=c
    B FINAL

LESS_THAN
    MOV R7,R3 ;setting a=c
    B FINAL


DONE
    LDR R1, =1 ;setting done = 1
    B FINAL ;return C


FINAL
    CMP R1, #1 ;compare done = 1
    BEQ END
    BNE COMPARE


COMPARE
    CMP R4, R3 ;compare c_old and c
    BNE DO_WHILE
    BEQ END


END
    MOV R0, R3
    POP {R4-R7}
    BX LR
}

void printCpuCycles(double readValue, int number, int sqrt)
{
    double cpuCycles = 0;
     
    cpuCycles = (readValue * 48000000);   // read value * frequqncy of clock
    pc.printf("Sqrt of %d using bisection menthod is %d \n\r", number, sqrt);
    pc.printf("Total time of execution for sqrt of(%d)is %f \n\r", number, readValue);
    pc.printf("Number of CPU cycles for sqrt(%d): %d\n\r\n\r", number, (int)cpuCycles);    
}
/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/
 /**
 * @brief Main function
 *
 * Detailed description of the main
 */
int main(void){
    
    volatile int r, j=0;
    
    double timer_read = 0.0;
    double sum = 0;   
    
    pc.printf("/*----------------------------------------------------------------------------*/\r\n\r\n");
    pc.printf("Frequency of KL25Z (ARM Cortex M0+): 48 MHZ\n\r\n\r");
    
    timer.start();
    
    timer.reset();
    r = my_sqrt(2);     // should be 1
    timer_read = timer.read();
    printCpuCycles(timer_read, 2, r);  
    sum = sum + timer_read;
    timer.reset();
    
    
      
    r = my_sqrt(4);    // should be 2
    timer_read = timer.read();
    printCpuCycles(timer_read, 4, r); 
    sum = sum + timer_read; 
    timer.reset(); 
    

         
    r = my_sqrt(22);    // should be 4
    timer_read = timer.read();
    printCpuCycles(timer_read, 22, r);  
    sum = sum + timer_read;
    timer.reset();  
    
    r = my_sqrt(121);   // should be 11
    timer_read = timer.read();
    printCpuCycles(timer_read, 121, r);  
    sum = sum + timer_read;
    
    pc.printf("Total time of operation: %f\n\r\n\r", sum);
    sum = sum * 48000000;
    pc.printf("CPU cycles: %d\n\r\n\r", (int)(sum));
    
    pc.printf("/*----------------------------------------------------------------------------*/\r\n\r\n"); 

}

// *******************************ARM University Program Copyright © ARM Ltd 2014*************************************/

