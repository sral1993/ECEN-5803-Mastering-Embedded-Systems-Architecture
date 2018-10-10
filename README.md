# Embedded System Design Evaluations
In this project, I have evaluated various MCU's and MPU's for suitability of three applications.
<br>
1. Flow meter <br>
2. Signal Analyzer <br>
3. VOIP Gateway <br>

<b> Flow meter </b> <br>
The main emphasis is to determine whether the Freescale KL25Z MCU is a right choice for the Sierra’s Model 240V In-line Volumetric Vortex Meter. A collective decision has to be made considering all of their technical specifications and requirements:
1. Design a novel Assembly Arithmetic algorithm as an alternative to the FPU.
2. Perform an analysis to integrate the hardware components along with KL25Z
3. Evaluate the Mbed® SDK and Keil® uVision in terms of adaptability
4. Understand the limitations in Hardware/Software integration
5. Provide with realistic estimation of system performance and cost analysis
6. Come up with the final recommendation on KL25Z for the functional Flowmeter under desired specifications

<img src="https://github.com/sral1993/ECEN-5803-Mastering-Embedded-Systems-Architecture/blob/master/Vortex%20Flow%20meter/Flowmeter_Blockdiagram.png" alt="BD">
<br>
Module 1:
Evaluate Assembly arithmetic for complex mathematical operations to overcome the absence of the floating point arithmetic.
<br>Module 2:<br>
Evaluate Mbed® as Software development kit(SDK) & Hardware development kit (HDK) and interface with onboard peripherals, communication protocols
<br>Module 3:<br>
Evaluate the capability to schedule various tasks just on bare metal and develop a debug monitor to display the flow and relevant characteristics of the flow meter through a serial port with the help of a timer and UART.
<br>Module 4:<br>
Evaluate the Real Time implementation of Flowmeter and perform the critical Hardware/ Software integration
<br>
From the above analysis, it is observed that KL25Z meets all the hardware and software requirements and acts as the perfect MCU platform for the Sierra’s Flowmeter. The only lagging feature is the absence of FPU, that might affect the output accuracy. However, from the analysis of CPU usage, it is determined that the required functionality can be built on software. The best part is all these features come within desired power ratings and cost limits.<br>
An added advantage is that KL25Z has sufficient I2C, SPI and UART protocol interfaces, multiple ADC and PWM for future expandability. It also has a low power mode which can support the future power saving requirements.<br>
Considering all the factors, Rahul and Vishnu make a strong recommendation for Freescale KL25Z MCU as GO in Sierras Flowmeter.
<br>
<img src="https://github.com/sral1993/ECEN-5803-Mastering-Embedded-Systems-Architecture/blob/master/Vortex%20Flow%20meter/Simulink_Blockdiagram.png" alt="BD">

<br> <br>


