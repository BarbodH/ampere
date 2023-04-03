#include "L298N.h"

/**
 * Function allowing initialization after initial instantiation
 * @param pinEnable - enable pin
 * @param pinInput1 - input pin 1
 * @param pinInput2 - input pin 2
 */
void L298N::init(uint8_t pinEnable, uint8_t pinInput1, uint8_t pinInput2)
{
  // initialize instance variables
  this->pinEnable = pinEnable;
  this->pinInput1 = pinInput1;
  this->pinInput2 = pinInput2;
  this->engaged = false;
  this->speed = 0;
  // initialize pins
  pinMode(this->pinEnable, OUTPUT);
  pinMode(this->pinInput1, OUTPUT);
  pinMode(this->pinInput2, OUTPUT);
}

/**
 * Constructor for initializing instance variables and specifying pin modes
 * @param pinEnable - enable pin
 * @param pinInput1 - input pin 1
 * @param pinInput2 - input pin 2
 */
L298N::L298N(uint8_t pinEnable, uint8_t pinInput1, uint8_t pinInput2)
{
  this->init(pinEnable, pinInput1, pinInput2);
}

/**
 * Destructor for freeing up memory upon deletion of an L298N class instance
 */
L298N::~L298N()
{
  ~this->pinEnable;
  ~this->pinInput1;
  ~this->pinInput2;
  ~this->engaged;
  ~this->speed;
}

/**
 * Function for starting motor rotation
 * @param direction - direction of motor rotation as a binary input
 *                  - value of true (ROTATE_CLOCKWISE) indicates clockwise rotation
 *                  - value of false (ROTATE_COUNTERCLOCKWISE) indicates counterclockwise rotation
 * @param speed - speed of motor rotation
 */
void L298N::run(bool direction, uint8_t speed)
{
  digitalWrite(this->pinInput1, direction ? HIGH : LOW);
  digitalWrite(this->pinInput2, direction ? LOW : HIGH);
  analogWrite(this->pinEnable, speed);
  this->engaged = true;
  this->speed = speed;
}

/**
 * Function for stopping motor rotation
 */
void L298N::stop()
{
  digitalWrite(this->pinInput1, LOW);
  digitalWrite(this->pinInput2, LOW);
  analogWrite(this->pinEnable, ROTATE_MIN_SPEED);
  this->engaged = false;
  this->speed = ROTATE_MIN_SPEED;
}

/**
 * Accessor method for current activity status of the driver
 * @return boolean value: 1 indicates engaged and 0 indicates idle
 */
bool L298N::isEngaged()
{
  return this->engaged;
}

/**
 * Accessor method for current speed of motor rotation
 * @return 1-byte unsingned integer, range: [0, 255]
 */
uint8_t L298N::getSpeed()
{
  return this->speed;
}
