
int analogPin = 0;
int raw = 0;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    raw = analogRead(0);
    Serial.println(raw);
}
