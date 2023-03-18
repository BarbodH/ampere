#include "HCSR04.h"

/**
 * Class initializer to specify pin modes and initialize instance variables
 * @param trig - trigger pin
 * @param echo - array of echo pins
 * @param num - number of ultrasonic sensors in the circuit
 */
void HCSR04::init(byte trig, byte echo[], byte num) {
	this->trig = trig;
	this->echo = echo;
	this->num = num;
	pinMode(this->trig, OUTPUT);
	for (int i = 0; i < num; i++)
		pinMode(this->echo[i], INPUT);
}

/**
 * Constructor for an HCSR04 instance with only one ultrasonic sensor
 * @param trig - trigger pin
 * @param echo - echo pin
 */
HCSR04::HCSR04(byte trig, byte echo) {
	this->init(trig, new byte[1]{echo}, 1);
}

/**
 * Overloaded constructor for an HCSR04 instance with multiple ultrasonic sensors
 * @param trig - trigger pin
 * @param echo - array of echo pins
 * @param num - number of ultrasonic sensors in the circuit
 */
HCSR04::HCSR04(byte trig, byte echo[], byte num) {
	this->init(trig, echo, num);
}

/**
 * Destructor function to free the memory upon deletion of an HCSR04 class instancee
 */
HCSR04::~HCSR04() {
	~this->trig;
	delete[] this->echo;
	~this->num;
}

/**
 * Function for calculating distance for multiple ultrasonic sensors (num > 1)
 * @param index - index corresponding to the target ultrasonic sensor
 * @return measured distance in centimeters
 */
float HCSR04::distance(byte index) const {
	digitalWrite(this->trig, LOW);
	delayMicroseconds(2);
	digitalWrite(this->trig, HIGH);
	delayMicroseconds(10);
	digitalWrite(this->trig, LOW);
	noInterrupts();
	float duration = pulseIn(this->echo[index], HIGH, 23529.4); // returns duration in microseconds (max distance: ~4m)
	interrupts();
	return (duration * 0.0343) / 2; // speed of sound: 343 m/s = 0.0343 cm/Î¼s
}

/**
 * Default function for only one ultrasonic sensor in the circuit (num = 1)
 * @return measured distance in centimeters
 */
float HCSR04::distance() const {
	return this->distance(0);
}
