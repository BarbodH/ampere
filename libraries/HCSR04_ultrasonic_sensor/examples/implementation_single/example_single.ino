#include <HCSR04.h>

const byte TRIGGER_PIN = 8;
const byte ECHO_PIN = 9;
HCSR04 sensor(TRIGGER_PIN, ECHO_PIN);

void setup() {
    Serial.begin(9600);
}

void loop() {
    Serial.println(sensor.distance()); // display distance (cm) on serial
    delay(500);
}