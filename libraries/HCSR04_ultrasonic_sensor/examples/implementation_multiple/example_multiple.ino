#include <HCSR04.h>

const byte TRIGGER_PIN = 2;
const byte ECHO_PINS [6] = {5, 6, 7, 8, 9, 10};
const byte NUM_SENSORS = 6;
HCSR04 sensors(TRIGGER_PIN, ECHO_PINS, NUM_SENSORS);

void setup() {
    Serial.begin(9600);
}

void loop() {
    for (int i = 0; i < 6; i++)
        Serial.println(sensors.distance(i)); // display distance (cm) on serial for sensors 1 to 6
    delay(500);
}