#include "MotionControlSystem.h"

MotionControlSystem::~MotionControlSystem()
{
  this->_motorL.~L298N();
  this->_motorR.~L298N();
  this->_triggered = false;
}

void MotionControlSystem::setupMotors(uint8_t pinEnableA, uint8_t pinEnableB,
  uint8_t pinInput1, uint8_t pinInput2, uint8_t pinInput3, uint8_t pinInput4)
{
  this->_motorL.init(pinEnableA, pinInput1, pinInput2);
  this->_motorR.init(pinEnableB, pinInput3, pinInput4);
}

void MotionControlSystem::moveCustom(bool directionL, bool directionR, uint8_t speedL, uint8_t speedR)
{
  this->_motorL.run(directionL, speedL);
  this->_motorR.run(directionR, speedR);
}

void MotionControlSystem::moveForwardCustom(uint8_t speedL, uint8_t speedR)
{
  this->moveCustom(ROTATE_COUNTERCLOCKWISE, ROTATE_CLOCKWISE, speedL, speedR);
}

void MotionControlSystem::moveBackwardCustom(uint8_t speedL, uint8_t speedR)
{
  this->moveCustom(ROTATE_CLOCKWISE, ROTATE_COUNTERCLOCKWISE, speedL, speedR);
}

void MotionControlSystem::moveForward(uint8_t speed)
{
  this->moveForwardCustom(speed, speed);
}

void MotionControlSystem::moveBackward(uint8_t speed)
{
  this->moveBackwardCustom(speed, speed);
}

void MotionControlSystem::rotateClockwise(uint8_t speed)
{
  this->moveCustom(ROTATE_COUNTERCLOCKWISE, ROTATE_COUNTERCLOCKWISE, speed, speed);
}

void MotionControlSystem::rotateCounterclockwise(uint8_t speed)
{
  this->moveCustom(ROTATE_CLOCKWISE, ROTATE_CLOCKWISE, speed, speed);
}

void MotionControlSystem::dash()
{
  this->moveForward(ROTATE_MAX_SPEED);
  this->_triggered = true;
}

void MotionControlSystem::scan(bool direction)
{
  if (direction) this->rotateClockwise(SCAN_ROTATION_SPEED);
  else this->rotateCounterclockwise(SCAN_ROTATION_SPEED);
  this->_triggered = false;
}

void MotionControlSystem::stop()
{
  this->_motorL.stop();
  this->_motorR.stop();
  this->_triggered = false;
}

bool MotionControlSystem::isTriggered()
{
  return this->_triggered;
}