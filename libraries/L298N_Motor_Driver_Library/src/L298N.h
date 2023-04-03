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
  void init(uint8_t pinEnable, uint8_t pinInput1, uint8_t pinInput2);
  L298N() = default;
  L298N(uint8_t pinEnable, uint8_t pinInput1, uint8_t pinInput2);
  ~L298N();
  // accessor functions for instance variables
  bool isEngaged();
  uint8_t getSpeed();
  // functions for movement control
  void run(bool direction, uint8_t speed);
  void stop();

private:
  // pin numbers
  uint8_t pinEnable;
  uint8_t pinInput1;
  uint8_t pinInput2;
  // instance variables
  bool engaged;
  uint8_t speed;
};
