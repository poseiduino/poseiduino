#ifndef MotorShieldEngine_h
#define MotorShieldEngine_h

#include "Arduino.h"
#include "Engine.h"

class MotorShieldEngine : public Engine {
  public:
    void activate();
    void start();
    void run();
    void stop();
};

#endif
