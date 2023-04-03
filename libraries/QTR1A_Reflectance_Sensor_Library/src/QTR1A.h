#pragma once
#include <Arduino.h>

class QTR1A
{
public:
  // overloaded constructors & destructor
  void init(uint8_t pin);
  QTR1A() = default;
  QTR1A(uint8_t pin);
  ~QTR1A();
  // utility function
  int refl() const;

private:
  uint8_t pin;
};
