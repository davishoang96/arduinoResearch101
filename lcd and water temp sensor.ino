#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 5

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

LiquidCrystal_I2C lcd(0x27, 2,1,0,4,5,6,7,3, POSITIVE);


// Variables
float Celcius=0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  
  lcd.begin(16,2);
  lcd.clear();
  lcd.print("TEMP TANK 1: ");
  lcd.setCursor(0,1);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  sensors.requestTemperatures(); 
  Celcius=sensors.getTempCByIndex(0);
  Serial.println(Celcius);
  delay(1000);


  lcd.setCursor(0,1);
  lcd.print(Celcius);
  lcd.print(" \337C");
  
}
