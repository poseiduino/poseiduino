#include "Arduino.h"
#include "Poseiduino.h"

Poseiduino::Poseiduino(int pin) {
}

  /*
 * Start the Motor
 */
void Poseiduino::startMotor () {
  Serial.println("Running motor ...");
  digitalWrite(12, HIGH); //Forward direction of Channel A
  digitalWrite(motor, LOW);   //Disengage the Brake for Channel A
  analogWrite(3, 255);   //Motor on Channel A at full speed
  delay(3000);
  
  digitalWrite(9, HIGH);
}

/*
 * Turn motor off
 */

void Poseiduino::turnMotorOff() {
    Serial.println("Turning motor off ...");
    digitalWrite(9, HIGH);
}

/*
 * Set elevator to go down
 */
void Poseiduino::elevatorDown() {
  Serial.println("Set elevator to go down ...");
  for (pos = 0; pos <= 75; pos += 1) { 
    elevator.write(pos);              
    delay(15);                       
  }
  isDown = true;
}

/*
 * Set elevator to go up
 */
void Poseiduino::elevatorUp () {
  Serial.println("Set elevator to return to surface ...");
  for (pos = 75; pos >= 0; pos -= 1) { 
    elevator.write(pos);              
    delay(15);                       
  }
  isUp = true;
}

/*
 * Take some data
 */
void Poseiduino::takeData () {
  Serial.println("Reading data ...");
  int sensorValue = analogRead(sensorPin) / 4;
  Serial.println(sensorValue);
  EEPROM.update(address, sensorValue);
  address = address + 1;
  if (address == EEPROM.length()) {
    address = 0;
  }
}

/*
 * Send data to serial
 */
void Poseiduino::writeDataToSerial () {
  readValue = EEPROM.read(address);

  Serial.print(address);
  Serial.print("\t");
  Serial.print(readValue, DEC);
  Serial.println();
  address = address + 1;
  if (address == EEPROM.length()) {
    address = 0;
  }
  delay(500);
}

