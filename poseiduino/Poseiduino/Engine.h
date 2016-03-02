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
    void activate();
    void start();
    void run();
    void stop();
  private:
   int  _pin; 
};

#endif
