#include <L298N.h> // remove later

#include "NavigationSystem.h"
#include "MotionControlSystem.h"

//////////////////// Initialization ////////////////////

// macro-defined constants for pin values
#define PIN_ENABLE_A 2
#define PIN_ENABLE_B 3
#define PIN_INPUT_1 4
#define PIN_INPUT_2 5
#define PIN_INPUT_3 6
#define PIN_INPUT_4 7
#define TRIG_PIN 9
#define ECHO_PIN 10

// macro-defined constant for delay time (milliseconds) when changing movement mode
#define PING 250

// system instances
NavigationSystem navigationSystem;
MotionControlSystem motionControlSystem;

// initialization
void setup() {
  // navigation system initialization
  navigationSystem.setupSensorDist(TRIG_PIN, ECHO_PIN);
  navigationSystem.setupSensorRefl((const uint8_t[]){A0, A1});

  // motion control system initialization
  motionControlSystem.setupMotors(PIN_ENABLE_A, PIN_ENABLE_B,
    PIN_INPUT_1, PIN_INPUT_2, PIN_INPUT_3, PIN_INPUT_4);

  motionControlSystem.scan(ROTATE_CLOCKWISE);

  Serial.begin(9600);
}

//////////////////// Main Program ////////////////////
void loop()
{
  bool opponentDetected = navigationSystem.getStatusDist();
  bool *edgeExceeded = navigationSystem.getStatusRefl();

  // both edges exceeding the ring
  if (!edgeExceeded[0] && !edgeExceeded[1])
  {
    if (!opponentDetected)
    {
      motionControlSystem.stop();
      delay(PING);
      motionControlSystem.scan(ROTATE_CLOCKWISE);
    }
  }
  // left edge exceeding the ring
  else if (!edgeExceeded[0] && edgeExceeded[1])
  {
    if (!opponentDetected)
    {
      motionControlSystem.stop();
      delay(PING);
      motionControlSystem.scan(ROTATE_CLOCKWISE);
    }
    else
    {
      delay(PING / 2);
      motionControlSystem.moveForwardCustom(ROTATE_MAX_SPEED, ROTATE_MAX_SPEED * 0.75);
    }
  }
  // right edge exceeding the ring
  else if (edgeExceeded[0] && !edgeExceeded[1])
  {
    if (!opponentDetected)
    {
      motionControlSystem.stop();
      delay(PING);
      motionControlSystem.scan(ROTATE_COUNTERCLOCKWISE);
    }
    else
    {
      delay(PING / 2);
      motionControlSystem.moveForwardCustom(ROTATE_MAX_SPEED * 0.75, ROTATE_MAX_SPEED);
    }
  }
}
