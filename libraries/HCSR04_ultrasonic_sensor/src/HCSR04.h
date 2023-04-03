#pragma once
#include <Arduino.h>

class HCSR04
{
public:
	// overloaded constructors & destructor
	void init(int out, int echo[], int n);
	HCSR04() = default;
	HCSR04(int out, int echo);
	HCSR04(int out, int echo[], int n);
	~HCSR04();
	// utility functions
	float dist() const;
	float dist(int n) const;

private:
	int out;	// ouput (trigger) pin
	int *echo;	// echo pin(s)
	int n;	// number of sensors, i.e., echo pins
};
