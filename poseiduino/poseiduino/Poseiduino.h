class Poseiduino {
  public:
    Poseiduino(int motor);
    void startMotor();
    void turnMotorOff();
    void elevatorDown();
    void elevatorUp();
    void takeData();
    void writeDataToSerial();
  private:
    int _motor;
};
