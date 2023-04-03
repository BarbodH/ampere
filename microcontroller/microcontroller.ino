#include <L298N.h> // remove later

#include "NavigationSystem.h"

//////////////////// Declarations ////////////////////

// constants for pin values
#define PIN_ENABLE_A 2
#define PIN_ENABLE_B 3
#define PIN_INPUT_1 4
#define PIN_INPUT_2 5
#define PIN_INPUT_3 6
#define PIN_INPUT_4 7
#define TRIG_PIN 9
#define ECHO_PIN 10

#define QTR_SENSOR_COUNT 2

// class instantiation for motors & sensors
L298N motorL(PIN_ENABLE_A, PIN_INPUT_1, PIN_INPUT_2);
L298N motorR(PIN_ENABLE_B, PIN_INPUT_3, PIN_INPUT_4);
HCSR04 sensorUltrasonic(TRIG_PIN, ECHO_PIN);

// initialization
void setup() {
  Serial.begin(9600);
}

//////////////////// Main Program ////////////////////
void loop() {
  motorR.run(ROTATE_CLOCKWISE, 50);
  motorL.run(ROTATE_CLOCKWISE, 50);
  // sumo();
}

void sumo() {

}

//////////////////// Movement Control ////////////////////


