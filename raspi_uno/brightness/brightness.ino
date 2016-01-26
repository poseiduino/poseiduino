const int numReadings = 10;
unsigned int readings[numReadings];
int index = 0;
unsigned int total = 0;
int average = 0;  

int adc_AVG(byte channel)
{
    total= total - readings[index];        
    readings[index] = analogRead(channel);
    total= total + readings[index];      
    index = index + 1;                    

    if (index >= numReadings)index = 0;                          

    average = total / numReadings;        
    return average / 1024.0 * 100.0;
}

void setup()
{

    analogWrite(9,200); 
    Serial.begin(9600);
}

void loop()
{

    int raw_adc = adc_AVG(0);
    Serial.println(100 - raw_adc);  
    delay(20);
}
