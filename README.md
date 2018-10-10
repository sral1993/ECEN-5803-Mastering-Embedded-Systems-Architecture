# Embedded System Design Evaluations
In this project, we have evaluated various MCU's and MPU's for suitability of three applications.
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

<b> Signal Analyzer </b>
  
The project team has the explicit objective of evaluating the hardware and software capabilities of the STM32F401RE MCU, with reference to the required specifications by Keithley, using various hardware and software test tools and methodologies. Of particular focus will be evaluation of the DSP capabilities of the processor, as well as the capability to interface between many different devices, via many different peripherals (ADC, DAC, UART, SPI, GPIO, I2S, etc.), some interfaces being very high speed for signal processing and conditioning.

<br>

<img src="https://github.com/sral1993/ECEN-5803-Mastering-Embedded-Systems-Architecture/blob/master/Signal%20Analyzer/BD.png" alt="BD">
In Module 1, the on-board Real-time clock of ST Nucleo was used to display current time on a UART serial terminal. The online Mbed compiler was used to make and compile the code. The RTC can be configured by setting the time in seconds starting from January 1, 1970.
In Module 2, the external peripherals were interfaced with corresponding protocols. <br>
a. Lab_exercise_2_8: Programming Using Mbed API
LEDs and buttons were interfaced using GPIO pins. The mbed DigitalIn library is used to read the value of a digital input pin. The mbed BusIn library is used to create a number of DigitalIn pins that can be read as one value. The InterruptIn is used to trigger an event when a digital input pin changes. <br>
b. Lab_exercise_2_9: Analog Input and Output
Potentiometers and speakers were interfaced using ADC and PWM. The PWM output is used to generate electrical waves which can be turned into sound by the speaker.
c. Lab_exercise_2_11: Serial Communication
Three types of serial communication are used to interface with three peripherals. The 16x2 LCD using ST7066 controller was interfaced using SPI with the 74HC595N shift register. Also, the DS1631 temperature sensor used I2C protocol and the results were displayed on UART terminal.<br>
In Module 3, the mBed RTOS was used to evaluate the capabilities of the STM32F401RE to run a multi-threaded environment interfacing to many different external devices. Threads, Mutexes, and semaphores were used to properly evaluate the multi-threaded performance. See Module 3 section for further details. <br>
In Module 4, the RTX RTOS, along with ARM DSP libraries and STM32 vendor libraries were used to evaluate the DSP capabilities of the STM32F401RE, by both generating a sinusoidal waveform at a fixed frequency, as well as detecting both sinusoidal and non-sinusoidal waveforms across a range of frequencies.<br>
<b> Harmonic Analysis Algorithm </b>
A simple model was created to show the generation of sin samples at the designed 10 kHz sampling rate, as well as the 4096 sample FFT and complex magnitude computation that is used in the MCU.<br>
<img src="https://github.com/sral1993/ECEN-5803-Mastering-Embedded-Systems-Architecture/blob/master/Signal%20Analyzer/simulink.png" alt="BD">

<img src="https://github.com/sral1993/ECEN-5803-Mastering-Embedded-Systems-Architecture/blob/master/Signal%20Analyzer/Waveforms.png" alt="BD">


A more suitable component given the requirements from Keithley is the STM32F76x Cortex-M7 MCU family.<br>

Entire Analysis can be viewed in the Signal Analyzer directory.
<br>
<br>

<b> VOIP Gateway </b>
<br>
This project is intended to serve as a high level design and analysis document, pursuant to request for services issued by Patton Equipment,for the design evaluation of a IP-PBX based VoIP Gateway. Based on the design and performance requirements desired by the client, evaluation tests were carried out using the Beagle Bone Black platform, with the aid of external hardware and software components. Using these test results, which are listed as project deliverables, the suitability of the AM 3358 MPU for the IP-PBX based VoIP Gateway was evaluated, along with providing recommendations pertaining to full system design and performance. <br>
The main objective of this document is to analyze the suitability of the AM3358 MPU
for Pattons proposed e911 IP-PBX VoIP Gateway. This analysis has been performed in
accordance with the following objectives: <br>
• Verify the performance of the AM3358 MPU in terms of its hardware capabilities,
peripherals, and network interfaces so as to meet the requirements specified in the
Request for Services (RFS). <br>
• Evaluate the compatibility of Windows Compact Embedded and Linux operating
systems for the proposed VoIP Gateway.<br>
• Analyze the capabilities of the AM3358 MPU with respect to its signal processing
functionality for audio/speech encoding and decoding.<br>
• Evaluate the IP-PBX VoIP capabilities of AM3358 MPU. <br>
• Determine whether a AM3358 MPU based system can be realized within the provided
budget, schedule, and performance constraints, and provide Patton with a
recommendation accordingly. <br>
<img src="https://github.com/sral1993/ECEN-5803-Mastering-Embedded-Systems-Architecture/blob/master/VOIP%20Gateway/Project3_Blockdiagram.PNG" alt="BD">
A modularized approach was taken for evaluating the software capabilities of the
AM3358 MPU by executing and analyzing independent software tasks as follows: <br>
• Module 1: Using Platform Builder to create Windows Compact Embedded (WINCE)
Toolchain.<br>
• Module 2: Testing and comparing the compatibility of WINCE 2007 and WINCE
2013 with the AM3358 MPU. Implementing a G.711 decoder/encoder to process audio
files for PBX I/O functionality.<br>
• Module 3: Booting Linux on the AM3358 MPU and executing a custom diagnostic
shell script at startup.<br>
• Module 4: Building a custom PBX using Asterisk to test the VoIP Gateway.<br>
• Module 5: Deploying a custom telecom/IOT application using the AM3358 MPU.<br>
• Module 6: Creating a custom WINCE operating system using Platform Builder.<br>
• Module 7: Running a Dhyrstone Benchmark for AM3358 MPU.<br>

<img src="https://github.com/sral1993/ECEN-5803-Mastering-Embedded-Systems-Architecture/blob/master/VOIP%20Gateway/shiril_to_vishnu_call.jpg" alt="BD">
<img src="https://github.com/sral1993/ECEN-5803-Mastering-Embedded-Systems-Architecture/blob/master/VOIP%20Gateway/shiril_to_vishnu_reception.jpg" alt="BD">

Recommendations: <br>
The AM3358 MPU was evaluated qualitatively and quantitatively keeping in mind the
design and performance requirements listed by Patton Equipment in the RFS for their
e911 IP-PBX VoIP Gateway product. Based on the modular test results, we can affirm
that the AM3358 MPU performs satisfactorily from both, hardware and software
perspectives. The AM3358 MPU was observed to operate at well over 500 VAX DMIPS,
which exceeds the processing requirement listed in the RFS. Further, from a system
design standpoint, the development cost for a single prototype the was $120. Although
this exceeds the price limit in the RFS, we are confident that the system can be
developed at a much lower price if bulk production (to the order of 5000 units) is
undertaken, in which case the price would fall well within the budget limitation of $50.
Thus, development of the product is certainly feasible within the time and budget
constraints specified in the RFS, and hence, the evaluation team has given the AM3358
MPU a straight GO for Patton Equipment’s e911 IP-PBX VoIP Gateway product.
<br>
Entire Analysis can be viewed in VOIP Gateway directory

