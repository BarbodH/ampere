#pragma once
#include <Arduino.h>

// sensor libraries
#include <HCSR04.h>
#include <QTR1A.h>

// macro-defined constants
#define CRITICAL_DIST 30
#define CRITICAL_REFL 400
#define DIST_SENSOR_COUNT 1
#define REFL_SENSOR_COUNT 2

class NavigationSystem
{
public:
  // constructor, initializers, and destructor
  NavigationSystem() = default;
  ~NavigationSystem();
  void setupSensorDist(uint8_t pinTrig, uint8_t pinEcho);
  void setupSensorRefl(uint8_t pins[]);
  // utility functions
  bool getStatusDist();
  bool * getStatusRefl();

private:
  // sensor instances
  HCSR04 _distSensor;
  QTR1A _reflSensors[REFL_SENSOR_COUNT];
};
