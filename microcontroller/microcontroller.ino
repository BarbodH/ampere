#include <L298N.h>
#include <HCSR04.h>

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
// QTRSensors sensorQTR;

// qtr.setSensorPins((const uint8_t[]){A0, A1, A2, A3, A4, A5}, SensorCount);

// initialization
void setup() {
  // QTRSensors.setTypeAnalog();
  // QTRSensors.setSensorPins((const uint8_t[]){A0, A1, A2, A3, A4, A5}, SensorCount);
  // QTRSensors.setEmitterPin(2);
  Serial.begin(9600);
}

//////////////////// Main Program ////////////////////
void loop() {
  motorR.run(ROTATE_CLOCKWISE, 50);
  motorL.run(ROTATE_CLOCKWISE, 50);
  // sumo();
}

void sumo() {
  while (true) {
    rotateClockwise(10);

    // retrieve sensor values
    int distance = sensorUltrasonic.distance();
    // unit16_t sensorValues[QTR_SENSOR_COUNT];

    // opponent detected
    if (distance < 20) {
      attack();
      // delay(100000); DEBUGGING
    }

    // edge of ring is reached

    delay(100);
  }
}

//////////////////// Movement Control ////////////////////

void attack() {
  moveForward(ROTATE_MAX_SPEED);
}

void search() {
  rotateClockwise(10);
}

void stop() {
  motorL.stop();
  motorR.stop();
}

void moveForward(byte speed) {
  motorL.run(ROTATE_COUNTERCLOCKWISE, speed);
  motorR.run(ROTATE_CLOCKWISE, speed);
}

void moveBackward(byte speed) {
  motorL.run(ROTATE_CLOCKWISE, speed);
  motorR.run(ROTATE_COUNTERCLOCKWISE, speed);
}

void rotateClockwise(byte speed) {
  motorL.run(ROTATE_COUNTERCLOCKWISE, speed);
  motorR.run(ROTATE_COUNTERCLOCKWISE, speed);
}

void rotateCounterclockwise(byte speed) {
  motorL.run(ROTATE_CLOCKWISE, speed);
  motorR.run(ROTATE_CLOCKWISE, speed);
}
