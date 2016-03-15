/*
  Engine.h - Header file for an Engine 
  in a Poseiduino submarine.
  Created by poseiduino, February, 2016.
  Released into the public domain.
*/
#ifndef Engine_h
#define Engine_h

#include "Arduino.h"

class Engine {
  public:
    virtual void activate() = 0;
    virtual void start() = 0;
    virtual void run() = 0;
    virtual void stop() = 0;
  private:
   int  _pin; 
};

#endif
