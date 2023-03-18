#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <L298N.h>

#define SEARCH_ROTATION_SPEED 10

class MovementSystem
{
public:
  // motor instantiation
  L298N *motorL;
  L298N *motorR;

  MovementSystem(short int pinEnableA, short int pinEnableB, short int pinInput1, short int pinInput2, short int pinInput3, short int pinInput4);

  // fundamental movement functions
  void moveForward(byte speed);
  void moveBackward(byte speed);
  void rotateClockwise(byte speed);
  void rotateCounterclockwise(byte speed);

  // sumobot movement functions
  void attack();
  void navigate();
  void stop();
};

#endif