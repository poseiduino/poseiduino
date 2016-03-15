/* Poseiduino v0.1
 * by poseiduino 
 * http://github.com/poseiduino/poseiduino
 * 
 */

#include "Elevator.h"
#include "MosfetEngine.h"
#include "Poseiduino.h"


unsigned long Timer;
Elevator elevator(5, 75);  
MosfetEngine engine;

Poseiduino submarine;

void setup() {
  Serial.begin(9600);
  elevator.activate();
  engine.activate();
  submarine.setElevator(elevator);
  submarine.setEngine(engine);
}

void loop() {
  Timer = millis();
  
  if (Timer < 500UL & submarine.elevatorBlocked == false) {
    submarine.elevatorBlocked = true;
    submarine.elevatorDown();
  } 

  if (Timer > 2000UL & submarine.engineRuns == false) {
    submarine.startMotor();
  }

  if (Timer > 2500UL & Timer < 10000UL) {
    submarine.runMotor();
  }

  if (Timer > 10000UL & submarine.engineRuns == true) {
    submarine.turnMotorOff();
  }

  if (Timer > 12000UL) {
    submarine.elevatorUp();
  }

  
}

