/*
  Poseiduino.h - Library for describing behaviour 
  and structure of a submarine.
  Created by poseiduino, February, 2016.
  Released into the public domain.
*/
#ifndef Poseiduino_h
#define Poseiduino_h

#include "Arduino.h"
#include "Elevator.h"

class Poseiduino {
  public:
    Poseiduino();
    bool elevatorBlocked = true;
    void setElevator(Elevator elevator);
    void elevatorDown();
    void elevatorUp();
    void startMotor();
    void turnMotorOff();
    void takeData();
    void writeDataToSerial();
  private:
    Elevator _elevator;
};

#endif
