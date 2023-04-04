#include "QTR1A.h"

void QTR1A::init(uint8_t pin)
{
  this->pin = pin;
  pinMode(this->pin, OUTPUT);
}

QTR1A::QTR1A(uint8_t pin)
{
  this->init(pin);
}

QTR1A::~QTR1A()
{
  ~this->pin;
}

int QTR1A::refl() const
{
  return analogRead(this->pin);
}
