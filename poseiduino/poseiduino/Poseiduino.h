/*
  Poseiduino.h - Library for describing behaviour 
  and structure of a submarine.
  Created by poseiduino, February, 2016.
  Released into the public domain.
*/
#ifndef Poseiduino_h
#define Poseiduino_h

#include "Arduino.h"

class Poseiduino {
  public:
    Poseiduino(int motor);
    void startMotor();
    void turnMotorOff();
    void elevatorDown();
    void elevatorUp();
    void takeData();
    void writeDataToSerial();
  private:
    int _motor;
};

#endif
