/*
  Elevator.h - Header file for an Elevator 
  in a Poseiduino submarine.
  Created by poseiduino, February, 2016.
  Released into the public domain.
*/
#ifndef Elevator_h
#define Elevator_h

#include "Arduino.h"
#include <Servo.h>

class Elevator {
  public:
    Elevator();
    Elevator(int pin, int angle);
    void activate();
    boolean isDown();
    void setDown();
    void setUp();
    private: 
      int _pin;
      Servo _servo;
      int _angle;
      int _currPos = 0;    // variable to store the servo position
      bool _isDown = true;
};

#endif
