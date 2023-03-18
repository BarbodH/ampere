#include "L298N.h"

/**
 * Constructor for initializing instance variables and specifying pin modes
 * @param pinEnable - enable pin
 * @param pinIN1 - input pin 1
 * @param pinIN2 - input pin 2
 */
L298N::L298N(byte pinEnable, byte pinIN1, byte pinIN2)
{
  // initialize instance variables
  this->pinEnable = pinEnable;
  this->pinIN1 = pinIN1;
  this->pinIN2 = pinIN2;
  this->engaged = false;
  this->speed = 0;
  // initialize pins
  pinMode(this->pinEnable, OUTPUT);
  pinMode(this->pinIN1, OUTPUT);
  pinMode(this->pinIN2, OUTPUT);
}

/**
 * Destructor for freeing up memory upon deletion of an L298N class instance
 */
L298N::~L298N()
{
  ~this->pinEnable;
  ~this->pinIN1;
  ~this->pinIN2;
  ~this->engaged;
  ~this->speed;
}

/**
 * Function for starting motor rotation
 * 
 * @param direction - direction of motor rotation as a binary input
 *                  - value of true (ROTATE_CLOCKWISE) indicates clockwise rotation
 *                  - value of false (ROTATE_COUNTERCLOCKWISE) indicates counterclockwise rotation
 * @param speed - speed of motor rotation
 * 
 * @pre  speed range: [0, 255] to prevent integer overflow
 * @post motor starts rotating according to given direction and speed
 */
void L298N::run(bool direction, byte speed)
{
  digitalWrite(this->pinIN1, direction ? HIGH : LOW);
  digitalWrite(this->pinIN2, direction ? LOW : HIGH);
  analogWrite(this->pinEnable, speed);
  this->engaged = true;
  this->speed = speed;
}

/**
 * Function for stopping motor rotation
 * 
 * @pre  none
 * @post motor rotation is stopped and current status is updated
 */
void L298N::stop()
{
  digitalWrite(this->pinIN1, LOW);
  digitalWrite(this->pinIN2, LOW);
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
 * @return 1-byte integer, range: [0, 255]
 */
byte L298N::getSpeed()
{
  return this->speed;
}
