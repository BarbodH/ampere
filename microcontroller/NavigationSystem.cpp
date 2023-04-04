#include "NavigationSystem.h"

NavigationSystem::~NavigationSystem()
{
  this->_distSensor.~HCSR04();
  for (int i = 0; i < REFL_SENSOR_COUNT; i++)
    this->_reflSensors[i].~QTR1A();
  delete [] this->_reflSensors;
}

void NavigationSystem::setupSensorDist(uint8_t pinTrig, uint8_t pinEcho)
{
  _distSensor.init(pinTrig, pinEcho, DIST_SENSOR_COUNT);
}

void NavigationSystem::setupSensorRefl(const uint8_t * pins)
{
  for (int i = 0; i < REFL_SENSOR_COUNT; i++)
    this->_reflSensors[i].init(pins[i]);
}

bool NavigationSystem::getStatusDist()
{
  return _distSensor.dist() > CRITICAL_DIST;
}

bool * NavigationSystem::getStatusRefl()
{
  bool status[REFL_SENSOR_COUNT];
  for (int i = 0; i < REFL_SENSOR_COUNT; i++)
    status[i] = this->_reflSensors[i].refl() > CRITICAL_REFL;
  return status;
}
