#include "Arduino.h"
#include "Poseiduino.h"
#include "Elevator.h"
#include "Engine.h"

Poseiduino::Poseiduino() {
}

/*
 * Set engine
 */

void Poseiduino::setEngine(Engine &engine) {
  _engine = &engine;  
}

/*
 * Start the Motor
 */
void Poseiduino::startMotor () {
  engineRuns = true;
  _engine->start();
}

/*
 * Run Motor
 */
void Poseiduino::runMotor () {
  engineRuns = true;
  _engine->run();
}

/*
 * Turn motor off
 */
void Poseiduino::turnMotorOff() {
  engineRuns = false;
  _engine->stop();
}

/*
 * Set elevator
 */
void Poseiduino::setElevator(Elevator elevator) {
  _elevator = elevator;
}

/*
 * Set elevator to go down
 */
void Poseiduino::elevatorDown() {
  
  _elevator.setDown();
}

/*
 * Set elevator to go up
 */
void Poseiduino::elevatorUp () {
  _elevator.setUp();
}

/*
 * Take some data
 */
void Poseiduino::takeData () {
  //Serial.println("Reading data ...");
  //int sensorValue = analogRead(sensorPin) / 4;
  //Serial.println(sensorValue);
  //EEPROM.update(address, sensorValue);
  //address = address + 1;
  //if (address == EEPROM.length()) {
  //  address = 0;
  //}
}

/*
 * Send data to serial
 */
void Poseiduino::writeDataToSerial () {
  //readValue = EEPROM.read(address);
  //Serial.print(address);
  //Serial.print("\t");
  //Serial.print(readValue, DEC);
  //Serial.println();
  //address = address + 1;
  //if (address == EEPROM.length()) {
  //  address = 0;
  //}
  //delay(500);
}

