/*


REFERENCES:
1.  http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dai0273a/index.html
2.  https://os.mbed.com/users/jmehring/code/Dhrystone/docs/f96b0b385ec4/main_8cpp_source.html
for the submission of Module 3 for ECEN 5803 Project 1 
by Srivishnu Alvakonda & Rahul Yamasani
*/

#include "mbed.h"
#include "dhry.h"

DigitalOut myled(LED1);
Timer timer;
Serial pc(USBTX, USBRX);  //serial channel over HDK USB interface

int main() {
    double benchtime, dps, VAX_DMIPS;
    unsigned long loops;
    
    pc.baud(9600);
    pc.printf("Dhrystone Benchmark Program C/1 12/01/84\r\n");
    timer.start();
    while(1) {
        loops = 0l;
        myled = 1;
        timer.reset();
        do {
            Proc0();
            Proc0();
            loops += LOOPS;
            benchtime = timer.read();
        } while (benchtime <= 20.000);
        myled = 0;
        dps = (double)loops / benchtime;
        VAX_DMIPS = dps/1757.0;
        pc.printf("Dhrystone time for %ld passes = %.3f sec\r\n", loops, benchtime);
        pc.printf("This machine benchmarks at %.0f dhrystones/second\r\n", dps);
        pc.printf("This machine has %.0f  VAX DMIPS\r\n", VAX_DMIPS);
        wait(1.0);
    }
}
