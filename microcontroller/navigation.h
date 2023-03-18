#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <HCSR04.h>
#include <QTRSensors.h>

#define ULTRASONIC_SENSOR_COUNT 1
#define REFLECTANCE_SENSOR_COUNT 2
#define CRITICAL_DISTANCE 40

class NavigationSystem
{
private:
  HCSR04 *sensorUltrasonic;
  // QTRSensors sensorReflectance();
  readUltrasonicSensor();

public:
  NavigationSystem(short int trigPin, short int echoPin);
  bool *getStatus();

};

#endif