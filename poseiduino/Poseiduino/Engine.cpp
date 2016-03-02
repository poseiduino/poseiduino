#include "Arduino.h"
#include "Engine.h"

void Engine::activate() {
  pinMode(12, OUTPUT); //Initiate Motor Channel A pin on motor shield
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin on motor shield
}

void Engine::start() {
  digitalWrite(12, HIGH); //Forward direction of Channel A
  digitalWrite(9, LOW);   //Disengage the Brake for Channel A
  analogWrite(3, 255);   //Motor on Channel A at full speed
}

void Engine::run() {
  analogWrite(3, 255);   //Motor on Channel A at full speed
}

void Engine::stop() {
  digitalWrite(9, HIGH);
}
