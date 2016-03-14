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
    void start();
    void run();
    void stop();
  private:
   int  _pin; 
};

class MotorShieldEngine : public Engine {
}

class MosfetEngine : public Engine {

}

#endif
