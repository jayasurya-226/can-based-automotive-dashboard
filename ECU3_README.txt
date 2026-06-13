==============================
ECU3 PROJECT DOCUMENTATION
==============================

Project Name : CAN Based Automatic CAR Dashboard Control System
Student Name : B.JAYASURYA
Roll Number  : 25017B_167
Date         : 05/1/2026

--------------------------------------------------
1. PROJECT OVERVIEW
--------------------------------------------------
This project implements a CAN-based vehicle dashboard system using microcontrollers.
The ECU3 module is responsible for receiving data from other ECUs over the CAN bus
and displaying real-time vehicle parameters such as Speed, Gear, RPM, and Indicators
on a Character LCD (CLCD).

--------------------------------------------------
2. OBJECTIVES
--------------------------------------------------
- To understand CAN communication protocol
- To implement real-time embedded systems
- To display vehicle parameters on LCD
- To handle collision mode and safety indicators
- To simulate an automotive dashboard

--------------------------------------------------
3. HARDWARE REQUIREMENTS
--------------------------------------------------
- PIC Microcontroller
- CAN Module
- Character LCD (CLCD)
- Push Buttons / Switches
- LEDs for indicators
- Power Supply
- Connecting Wires

--------------------------------------------------
4. SOFTWARE REQUIREMENTS
--------------------------------------------------
- MPLAB X IDE
- XC8 Compiler
- Embedded C
- Proteus (for simulation, optional)

--------------------------------------------------
5. MODULES IMPLEMENTED
--------------------------------------------------
- Speed Display Module
- Gear Display Module
- RPM Display Module
- Indicator Control Module
- Collision Detection Module
- CAN Communication Module

--------------------------------------------------
6. FUNCTIONAL DESCRIPTION
--------------------------------------------------
The ECU3 receives CAN messages from other ECUs. Each message contains a specific
parameter such as speed, gear, RPM, or indicator status. Based on the received
message ID, the corresponding handler function is called and the value is
displayed on the LCD.

If collision mode is detected, all other data is blocked and only the collision
warning is displayed.

--------------------------------------------------
7. RESULT
--------------------------------------------------
The system successfully displays real-time vehicle data on the LCD using CAN
communication. Collision detection mode works correctly and blocks other updates.

--------------------------------------------------
8. LEARNING OUTCOMES
--------------------------------------------------
- Learned CAN protocol basics
- Understood embedded system design
- Gained experience with LCD interfacing
- Improved debugging skills
- Learned ISR and timer handling

--------------------------------------------------
9. FUTURE ENHANCEMENTS
--------------------------------------------------
- Add GPS module
- Add mobile app connectivity
- Add data logging
- Add graphical display

--------------------------------------------------
10. CONCLUSION
--------------------------------------------------
The ECU3 CAN-based dashboard system demonstrates a practical implementation of
automotive embedded systems. It provides reliable real-time monitoring of vehicle
parameters and enhances safety with collision detection.

----------------------------------------------------------------------------