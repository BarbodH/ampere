#include <L298N.h>

// global constants
const uint8_t PIN_ENABLE = 9;
const uint8_t PIN_INPUT1 = 7;
const uint8_t PIN_INPUT2 = 8;
L298N driver(PIN_ENABLE, PIN_INPUT1, PIN_INPUT2);

void setup()
{
  // L298N class instantiation fully handles the motor driver setup
  Serial.begin(9600);
}

/**
 * Main program for triggering a DC motor using the L298N module.
 * The following movement sequence is initiated continuously:
 * - Motor rotates clockwise for 3 seconds at max speed (255)
 * - Motor stops and stays idle for 2 seconds
 * - Motor rotates counterclockwise for 3 seconds at max speed (255)
 * - Motor stops and stays idle for 2 seconds
 */
void loop()
{
  driver.run(ROTATE_CLOCKWISE, ROTATE_MAX_SPEED);
  delay(3000);

  driver.stop();
  delay(2000);

  driver.run(ROTATE_COUNTERCLOCKWISE, ROTATE_MAX_SPEED);
  delay(3000);

  driver.stop();
  delay(2000);
}
