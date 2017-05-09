/****************************************************************
 * DisplaySHT2x
 *  Reads the SHT2x sensor and prints the
 *  relative humidity and temperature to an lcd display 
 *  
 ***************************************************************/

#include <Wire.h>
#include <Sodaq_SHT2x.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  
   lcd.begin(16, 2);
}

void loop()
{
  String hum = "Hum: ";
  lcd.setCursor(0, 0);
  hum += SHT2x.GetHumidity();
  hum += " %";
  lcd.print(hum);
  String temp = "Temp: ";
  temp += SHT2x.GetTemperature();
  temp += " C";
  lcd.setCursor(0,1);
  lcd.print(temp);
  delay(1000);
}

