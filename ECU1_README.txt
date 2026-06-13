==============================
ECU1 PROJECT DOCUMENTATION
==============================

Project Name : ECU1 ? CAN Based RPM and Indicator Control Unit
Student Name : B.JAYASURYA
Roll Number  : 25017B_167
Date         : 5/1/2026

--------------------------------------------------
1. PROJECT OVERVIEW
--------------------------------------------------
ECU1 is a part of a CAN-based automotive embedded system. This module is responsible
for monitoring RPM, Engine Temperature, and Indicator status. The collected data
is processed and transmitted to other ECUs through the CAN bus.

ECU1 acts as a sensing and control unit in the distributed vehicle system.

--------------------------------------------------
2. OBJECTIVES
--------------------------------------------------
- To read RPM using ADC
- To control and monitor indicators
- To implement CAN communication
- To understand real-time embedded systems

--------------------------------------------------
3. HARDWARE REQUIREMENTS
--------------------------------------------------
- PIC Microcontroller
- CAN Module
- Potentiometer (for RPM simulation)
- Push Buttons (for indicator control)
- LEDs
- Power Supply
- Connecting Wires

--------------------------------------------------
4. SOFTWARE REQUIREMENTS
--------------------------------------------------
- MPLAB X IDE
- XC8 Compiler
- Embedded C
- Proteus (Optional)

--------------------------------------------------
5. MODULES IMPLEMENTED
--------------------------------------------------
- RPM Sensing Module
- Engine Temperature Module
- Indicator Control Module
- CAN Transmission Module
- Input Processing Module

--------------------------------------------------
6. FUNCTIONAL DESCRIPTION
--------------------------------------------------
ECU1 reads RPM and engine temperature values using the ADC module. The indicator
status is controlled using push buttons. These values are converted into a suitable
format and transmitted over the CAN bus using unique message IDs.

The receiving ECU (ECU3) processes this data and displays it on the dashboard.

--------------------------------------------------
7. RESULT
--------------------------------------------------
The ECU1 module successfully reads RPM, engine temperature, and indicator status
and transmits the data reliably over the CAN bus.

--------------------------------------------------
8. LEARNING OUTCOMES
--------------------------------------------------
- Learned ADC interfacing
- Understood CAN protocol
- Learned indicator control logic
- Improved embedded C programming
- Gained real-time system experience

--------------------------------------------------
9. FUTURE ENHANCEMENTS
--------------------------------------------------
- Add real sensors
- Add warning system for high temperature
- Add automatic indicator turn-off
- Add mobile app monitoring

--------------------------------------------------
10. CONCLUSION
--------------------------------------------------
ECU1 plays a crucial role in the CAN-based automotive system by collecting and
transmitting essential vehicle parameters. This project demonstrates practical
implementation of embedded sensing and CAN communication.

-------------------------------------------------------------------------------