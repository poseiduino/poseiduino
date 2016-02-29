/* Poseiduino v0.1
 * by poseiduino 
 * http://github.com/poseiduino/poseiduino
 * 
 */

#include <Servo.h>
#include <EEPROM.h>

Servo elevator;  
int pos = 0;    // variable to store the servo position
bool isDown = true;
bool isUp = false;

Poseiduino submarine(9);
//Lab
int sensorPin = A0;

// EEPROM
int address = 0;
byte readValue;

void setup() {
  //elevator
  elevator.attach(5);
  //motor
  pinMode(12, OUTPUT); //Initiate Motor Channel A pin on motor shield
  pinMode(motor, OUTPUT); //Initiates Brake Channel A pin on motor shield
  //eeprom
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {
  int state = millis();
  
  if (state < 500 & isDown == false) {
    submarine.elevatorDown();
  } 
  
  if (state > 500 & state < 10500 & isDown) {
    submarine.startMotor();
  }

  if (state > 11000 & state < 20000) {
    submarine.turnMotorOff();
    delay(1000);
    submarine.takeData();
  }

  if (state > 21000) {
    submarine.elevatorUp();
  }

  if (state > 22000 & isUp) {
    submarine.startMotor();
  }
  
  if (state > 35000) {
    submarine.turnMotorOff();
    submarine.writeDataToSerial();
  }
  
}

