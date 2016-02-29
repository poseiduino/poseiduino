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

int motor = 9;
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
    elevatorDown();
  } 
  
  if (state > 500 & state < 10500 & isDown) {
    startMotor();
  }

  if (state > 11000 & state < 20000) {
    turnMotorOff();
    delay(1000);
    takeData();
  }

  if (state > 21000) {
    elevatorUp();
  }

  if (state > 22000 & isUp) {
    startMotor();
  }
  
  if (state > 35000) {
    turnMotorOff();
    writeDataToSerial();
  }
  
}

