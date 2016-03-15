#ifndef MosfetEngine_h
#define MosfetEngine_h

#include "Arduino.h"
#include "Engine.h"

class MosfetEngine : public Engine {
  public:
    void activate();
    void start();
    void run();
    void stop();
};

#endif
