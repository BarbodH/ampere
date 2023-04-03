#include "MotionControlSystem.h"

MotionControlSystem::~MotionControlSystem()
{
  this->_motorL.~L298N();
  this->_motorR.~L298N();
}

void MotionControlSystem::setupMotors(uint8_t pinEnableA, uint8_t pinEnableB,
  uint8_t pinInput1, uint8_t pinInput2, uint8_t pinInput3, uint8_t pinInput4)
{
  this->_motorL.init(pinEnableA, pinInput1, pinInput2);
  this->_motorR.init(pinEnableB, pinInput3, pinInput4);
}

void MotionControlSystem::moveForward(uint8_t speed)
{
  this->_motorL.run(ROTATE_COUNTERCLOCKWISE, speed);
  this->_motorR.run(ROTATE_CLOCKWISE, speed);
}

void MotionControlSystem::moveBackward(uint8_t speed)
{
  this->_motorL.run(ROTATE_CLOCKWISE, speed);
  this->_motorR.run(ROTATE_COUNTERCLOCKWISE, speed);
}

void MotionControlSystem::rotateClockwise(uint8_t speed)
{
  this->_motorL.run(ROTATE_COUNTERCLOCKWISE, speed);
  this->_motorR.run(ROTATE_COUNTERCLOCKWISE, speed);
}

void MotionControlSystem::rotateCounterclockwise(uint8_t speed)
{
  this->_motorL.run(ROTATE_CLOCKWISE, speed);
  this->_motorR.run(ROTATE_CLOCKWISE, speed);
}

void MotionControlSystem::dash()
{
  moveForward(ROTATE_MAX_SPEED);
}

void MotionControlSystem::scan()
{
  rotateClockwise(SCAN_ROTATION_SPEED);
}

void MotionControlSystem::stop() {
  this->_motorL.stop();
  this->_motorR.stop();
}