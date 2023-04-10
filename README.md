# Ampere

[<img src="/images/v1.3-assembled.png" align="center" height="400" hspace="2" vspace="2">](/images/v1.3-assembled.png)

Ampere is a self-driving 10×10 cm robot designed for [robot-sumo competitions](https://www.sumobot.ca/competition), analogous to the sport of sumo.

## Components

The robot utilizies the following pieces of electronic hardware:

  - [Arduino Nano](components/arduino-nano-v3.stl) (1×): main control unit using an ATmega328 microcontroller
  - [HC-SR04 ultrasonic sensor](components/hcsr04-ultrasonic-sensor.stl) (1×): utilized for detecting the opponent and initiating an attack
  - [QTR-1A reflectance sensor](components/qtr1a-reflectance-sensor.stl) (2×): utilized for keeping the robot inside the field using the floor color
  - [L298N motor driver](components/l298n-motor-driver.stl) (1×): utilized for controlling the movement of the 6V DC motors
  - [JSumo 6V DC motor](components/jsumo-dc-motor.stl) (2×): connect to the motor driver and handle mobility
  - 9V battery (2×): provide power for the robot
  

## Functionality

The functionality of the robot is divided into 3 layers of abstraction (ordered from lowest to highest):

  1. Libraries dealing with digital/analog input/output to the electronic hardware
      - [HC-SR04 ultrasonic sensor library](libraries/HCSR04_ultrasonic_sensor); developed by [gamegine](https://github.com/gamegine)
      - [QTR-1A reflectance sensor library](libraries/QTR1A_Reflectance_Sensor_Library); developed by me
      - [L298N motor driver library](libraries/L298N_Motor_Driver_Library); developed by me
  
  2. System classes providing a liaison between the microcontroller and hardware libraries through signals:
      - [Navigation system](microcontroller/NavigationSystem.h): utilizes the sensors to handle edge/opponent detection and produces boolean signals
      - [Motion control system](microcontroller/MotionControlSystem.h): utilizes the motor driver to handle various movement types

3. [Microcontroller](microcontroller/microcontroller.ino) Arduino file controlling the behaviour

Writing the entire program in the **microcontroller.ino** is also feasible.
However, dividing the program into multiple abstraction layers allows for better readability and debugging.
