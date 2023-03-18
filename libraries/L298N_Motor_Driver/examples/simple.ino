#include <L298N.h>

// global variables
const byte PIN_ENABLE = 9;
const byte PIN_INPUT1 = 7;
const byte PIN_INPUT2 = 8;
L298N driver(PIN_ENABLE, PIN_INPUT1, PIN_INPUT2);

void setup()
{
  // L298N class instantiation fully handles the motor driver setup
  Serial.begin(9600);
}

/**
 * Main program for triggering a DC motor using the motor driver instance
 * 
 * @pre  - 'driver' is an instance of the L298N class
 *       - 'ROTATE_CLOCKWISE' is a boolean set to true
 *       - 'ROTATE_COUNTERCLOCKWISE' is a boolean set to false
 *       - 'ROTATE_MAX_SPEED' is an integer set to 255
 *       - 'ROTATE_MIN_SPEED' is an integer set to 0
 * @post 1) motor rotates clockwise for 3 seconds
 *       2) motor stops and stays idle for 2 seconds
 *       3) motor rotates counterclockwise for 3 seconds
 *       4) motor stops and stays idle for 2 seconds
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
