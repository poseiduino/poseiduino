#include "Arduino.h"
#include "Elevator.h"
#include <Servo.h>

Elevator::Elevator() {
  _pin = 5;
  _angle = 0;
}

Elevator::Elevator(int pin, int angle) {
  _pin = pin;
  _angle = angle;
}

void Elevator::activate () {
  _servo.attach(_pin);
}

boolean Elevator::isDown() {
  return _isDown;
}

void Elevator::setDown() {
  _isDown = true;
  for (int pos = _currPos; pos <= _angle; pos += 1) { 
    _servo.write(pos);              
    delay(15);                       
  }
}

void Elevator::setUp() {
  _isDown = false;
  for (int pos = _currPos; pos >= 0; pos -= 1) { 
    _servo.write(pos);              
    delay(15);                       
  }
}
