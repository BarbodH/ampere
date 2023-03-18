#include "movement.h"

MovementSystem::MovementSystem(short int pinEnableA, short int pinEnableB, short int pinInput1, short int pinInput2, short int pinInput3, short int pinInput4)
{
  motorL = new L298N(pinEnableA, pinInput1, pinInput2);
  motorR = new L298N(pinEnableB, pinInput3, pinInput4);
}

void MovementSystem::moveForward(byte speed)
{
  motorL->run(ROTATE_COUNTERCLOCKWISE, speed);
  motorR->run(ROTATE_CLOCKWISE, speed);
}

void MovementSystem::moveBackward(byte speed)
{
  motorL->run(ROTATE_CLOCKWISE, speed);
  motorR->run(ROTATE_COUNTERCLOCKWISE, speed);
}

void MovementSystem::rotateClockwise(byte speed)
{
  motorL->run(ROTATE_COUNTERCLOCKWISE, speed);
  motorR->run(ROTATE_COUNTERCLOCKWISE, speed);
}

void MovementSystem::rotateCounterclockwise(byte speed)
{
  motorL->run(ROTATE_CLOCKWISE, speed);
  motorR->run(ROTATE_CLOCKWISE, speed);
}

void MovementSystem::attack()
{
  moveForward(ROTATE_MAX_SPEED);
}

void MovementSystem::navigate()
{
  rotateClockwise(SEARCH_ROTATION_SPEED);
}

void MovementSystem::stop()
{
  motorL->stop();
  motorR->stop();
}