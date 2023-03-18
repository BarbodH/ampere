#pragma once
#include <Arduino.h>

class HCSR04 {

public:
	HCSR04(byte trig, byte echo); // constructor for one sensor
	HCSR04(byte trig, byte echo[], byte num); // constructor for multiple sensors
	~HCSR04(); // destructor
	float distance() const; // return curent distance of ultrasonic sensor at index 0
	float distance(byte index) const; // return curent distance of ultrasonic sensor at given index

private:
	void init(byte trig, byte echo[], byte num); // main initializer
	byte trig; // trigger pin
	byte *echo; // echo pin list
	byte num; // number of ultrasonic sensors in the circuit

};
