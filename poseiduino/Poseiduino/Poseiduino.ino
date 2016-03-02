/* Poseiduino v0.1
 * by poseiduino 
 * http://github.com/poseiduino/poseiduino
 * 
 */

#include "Poseiduino.h"
#include "Elevator.h"

unsigned long Timer;
Elevator elevator(5, 75);  
Poseiduino submarine;

void setup() {
  elevator.activate();
  submarine.setElevator(elevator);
}

void loop() {
  Timer = millis();
  
  if (Timer < 500UL & submarine.elevatorBlocked == true) {
    submarine.elevatorBlocked = false;
    submarine.elevatorDown();
  } 

  if (Timer > 10000UL) {
    submarine.elevatorUp();
  }

  
}

