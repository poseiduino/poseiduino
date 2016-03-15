#include "Arduino.h"
#include "MotorShieldEngine.h"

void MotorShieldEngine::activate() {
  pinMode(12, OUTPUT); //Initiate Motor Channel A pin on motor shield
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin on motor shield
}

void MotorShieldEngine::start() {
  digitalWrite(12, HIGH); //Forward direction of Channel A
  digitalWrite(9, LOW);   //Disengage the Brake for Channel A
  analogWrite(3, 255);   //Motor on Channel A at full speed
}

void MotorShieldEngine::run() {
  analogWrite(3, 255);   //Motor on Channel A at full speed
}

void MotorShieldEngine::stop() {
  digitalWrite(9, HIGH);
}
