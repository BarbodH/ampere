#pragma once
#include <Arduino.h>

// motor driver library
#include <L298N.h>

// macro-defined constant(s)
#define SCAN_ROTATION_SPEED 30

class MotionControlSystem
{
public:
  // constructor, initializer, and destructor
  MotionControlSystem() = default;
  ~MotionControlSystem();
  void setupMotors(uint8_t pinEnableA, uint8_t pinEnableB,
    uint8_t pinInput1, uint8_t pinInput2, uint8_t pinInput3, uint8_t pinInput4);
  // utility functions
  void moveCustom(bool directionL, bool directionR, uint8_t speedL, uint8_t speedR);
  void moveForwardCustom(uint8_t speedL, uint8_t speedR);
  void moveBackwardCustom(uint8_t speedL, uint8_t speedR);
  void moveForward(uint8_t speed);
  void moveBackward(uint8_t speed);
  void rotateClockwise(uint8_t speed);
  void rotateCounterclockwise(uint8_t speed);
  void dash();
  void scan(bool direction);
  void stop();
  bool isTriggered();

private:
  // DC motors
  L298N _motorL;
  L298N _motorR;
  // instance variable for activity status
  bool _triggered;
};
