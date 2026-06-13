==============================
ECU2 PROJECT DOCUMENTATION
==============================

Project Name : ECU2 ? CAN Based Speed and Gear Control Unit
Student Name : B.JAYASURYA
Roll Number  : 25017B_167
Date         : 5/1/2026

--------------------------------------------------
1. PROJECT OVERVIEW
--------------------------------------------------
ECU2 is a part of a CAN-based automotive embedded system. This module is responsible
for reading vehicle Speed and Gear position and transmitting this data to other
ECUs over the CAN bus.

It acts as an input and control unit that continuously monitors driver actions
and sends real-time data to the dashboard ECU.

--------------------------------------------------
2. OBJECTIVES
--------------------------------------------------
- To implement Speed and Gear sensing
- To understand CAN communication
- To transmit real-time vehicle parameters
- To simulate automotive control behavior
- To ensure reliable data transmission

--------------------------------------------------
3. HARDWARE REQUIREMENTS
--------------------------------------------------
- PIC Microcontroller
- CAN Module
- Potentiometer (Speed simulation)
- Push Buttons / Switches (Gear control)
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
- Speed Sensing Module
- Gear Control Module
- CAN Transmission Module
- Collision Mode Module
- Input Processing Module

--------------------------------------------------
6. FUNCTIONAL DESCRIPTION
--------------------------------------------------
ECU2 reads the speed value using ADC and gear position using push buttons.
The speed value is converted into a suitable format and transmitted through
the CAN bus using a unique message ID.

Gear positions are changed using switches and are also sent through CAN.
If collision mode is triggered, the system changes its behavior accordingly.

The receiving ECU (ECU3) displays these values on the dashboard.

--------------------------------------------------
7. RESULT
--------------------------------------------------
The ECU2 module successfully transmits real-time speed and gear data over the CAN bus.
The system reacts correctly to gear changes and collision mode.

--------------------------------------------------
8. LEARNING OUTCOMES
--------------------------------------------------
- Learned ADC interfacing
- Understood gear logic
- Implemented CAN transmission
- Improved embedded C programming
- Learned real-time data handling

--------------------------------------------------
9. FUTURE ENHANCEMENTS
--------------------------------------------------
- Add cruise control
- Add automatic gear logic
- Add speed limiter
- Add wireless diagnostics

--------------------------------------------------
10. CONCLUSION
--------------------------------------------------
ECU2 plays a vital role in the CAN-based vehicle system by providing accurate
speed and gear information. This project demonstrates real-time embedded
control and communication between multiple ECUs.

------------------------------X----------------------------------