#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD settings
LiquidCrystal_I2C lcd(0x27, 2,1,0,4,5,6,7,3, POSITIVE);

signed short minutes, seconds;
bool runstatus;
char timeline[16];

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Countdown");
  lcd.setCursor(0,1);
  pinMode(4, OUTPUT);  
  minutes = 0;
  seconds = 10;
  runstatus = true;
}

void loop()
{
  
  lcd.setCursor(0, 1);
  sprintf(timeline,"%0.2d:%0.2d", minutes, seconds);
  lcd.print(timeline);

  if (runstatus == true)
  {
    if (seconds == 0)
    {
      seconds = 60;
      minutes --;
    }
    else
    {
      digitalWrite(4,HIGH);
      delay(1000);
      digitalWrite(4,LOW);
      seconds -= 1;
    }

    if (seconds == 0 && minutes == 0)
    {
      seconds = 0;
      minutes = 0;
      runstatus = false;
    }
  }
}
