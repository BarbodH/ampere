#include "navigation.h"

NavigationSystem::NavigationSystem(short int trigPin, short int echoPin)
{
  sensorUltrasonic = new HCSR04(trigPin, echoPin);
  // sensorReflectance.setTypeAnalog();
  // sensorReflectance.setSensorPins((const uint8_t[]){A1, A2}, QTR_SENSOR_COUNT);
  // sensorReflectance.setEmitterPin(2);
}

bool *NavigationSystem::getStatus()
{
  bool signal[ULTRASONIC_SENSOR_COUNT + REFLECTANCE_SENSOR_COUNT];
  
  // gather data from the sensors
  int distance = this->readUltrasonicSensor();
  // bool edge -> read reflectance sensor

  // update signal
  if (distance < CRITICAL_DISTANCE) signal[0] = true;

  return signal;
}

int NavigationSystem::readUltrasonicSensor()
{
  return this->sensorUltrasonic->distance();
}