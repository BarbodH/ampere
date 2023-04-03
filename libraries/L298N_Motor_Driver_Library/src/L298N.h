#pragma once
#include <Arduino.h>

// macro-defined constants
#define ROTATE_CLOCKWISE true
#define ROTATE_COUNTERCLOCKWISE false
#define ROTATE_MAX_SPEED 255
#define ROTATE_MIN_SPEED 0

class L298N
{
public:
  // constructor & destructor
  L298N(short int pinEnable, short int pinInput1, short int pinInput2);
  ~L298N();
  // accessor functions for instance variables
  bool isEngaged();
  short int getSpeed();
  // functions for movement control
  void run(bool direction, short int speed);
  void stop();

private:
  // pin numbers
  short int pinEnable;
  short int pinInput1;
  short int pinInput2;
  // instance variables
  bool engaged;
  short int speed;
};
