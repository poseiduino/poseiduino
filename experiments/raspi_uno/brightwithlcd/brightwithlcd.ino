#include <LiquidCrystal.h>

// Define LCD Pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(11, 10, 2, 3, 4, 5);

#define LCD_LENGHT 16.0

const int numReadings = 10;
unsigned int readings[numReadings];
int index = 0;
unsigned int total = 0;
int average = 0;  
 
byte MyChar0[8] = {
B00000,
B00000,
B00000,
B00000,
B00000,
B00000,
B00000,
B00000,
};

byte MyChar1[8] = {
B10000,
B10000,
B10000,
B10000,
B10000,
B10000,
B10000,
B10000,
};

byte MyChar2[8] = {
B11000,
B11000,
B11000,
B11000,
B11000,
B11000,
B11000,
B11000,
};

byte MyChar3[8] = {
B11100,
B11100,
B11100,
B11100,
B11100,
B11100,
B11100,
B11100,
};

byte MyChar4[8] = {
B11110,
B11110,
B11110,
B11110,
B11110,
B11110,
B11110,
B11110,
};

byte MyChar5[8] = {
B11111,
B11111,
B11111,
B11111,
B11111,
B11111,
B11111,
B11111,
};

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

void draw_bargraph(byte percent) 
{
    byte i, c1, c2;
 
    lcd.setCursor(0, 0);
    lcd.print("Brightness: ");
    lcd.print(percent);
    lcd.print("%  ");
 
    lcd.setCursor(0, 1);
 
    percent = map(percent, 0, 100, 0, 80);
 
    c1 = percent / 5;
    c2 = percent % 5;
 
    for(i = 0; i < c1; ++i)
    lcd.write(byte(5));
 
    lcd.write(c2);
 
    for(i = 0; i < 16 - (c1 + (c2 ? 1 : 0)); ++i)
    lcd.write(byte(0));
    
}

void setup()
{

    analogWrite(9,200); 
    Serial.begin(9600);
    
    lcd.createChar(0, MyChar0);
    lcd.createChar(1, MyChar1);
    lcd.createChar(2, MyChar2);
    lcd.createChar(3, MyChar3);
    lcd.createChar(4, MyChar4);
    lcd.createChar(5, MyChar5);

    lcd.begin(16, 2);

}

void loop()
{

    int raw_adc = adc_AVG(0);
    Serial.println(100 - raw_adc);       // prints a label
    draw_bargraph(100 - raw_adc);
    delay(20);
    
}
