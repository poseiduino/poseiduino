#include "Arduino.h"
#include "MosfetEngine.h"

void MosfetEngine::activate() {
  pinMode(3, OUTPUT); //Activate PWM-PIN ~3
}

void MosfetEngine::start() {
  analogWrite(3, 50);   
}

void MosfetEngine::run() {
  analogWrite(3, 50);  
}

void MosfetEngine::stop() {
  digitalWrite(3, 0);
}
