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

int motor = 8;
int sensorPin = A0;

// EEPROM
int address = 0;
byte readValue;

void setup() {
  elevator.attach(9);
  pinMode(motor, OUTPUT);
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

/*
 * Start the Motor
 */
void startMotor () {
  Serial.println("Running motor ...");
  digitalWrite(motor, HIGH); 
}

/*
 * Turn motor off
 */

void turnMotorOff() {
    Serial.println("Turning motor off ...");
    digitalWrite(motor, LOW);
}

/*
 * Set elevator to go down
 */
void elevatorDown() {
  Serial.println("Set elevator to go down ...");
  for (pos = 0; pos <= 180; pos += 1) { 
    elevator.write(pos);              
    delay(15);                       
  }
  isDown = true;
}

/*
 * Set elevator to go up
 */
void elevatorUp () {
  Serial.println("Set elevator to return to surface ...");
  for (pos = 180; pos >= 0; pos -= 1) { 
    elevator.write(pos);              
    delay(15);                       
  }
  isUp = true;
}

/*
 * Take some data
 */

void takeData () {
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
void writeDataToSerial () {
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

