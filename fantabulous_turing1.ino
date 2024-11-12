#include <LiquidCrystal.h>

LiquidCrystal lcd (12,11,7,6,5,4);

const int buzzerPin = 8;

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
  float tensao = analogRead(A0)*5.0/1023;
  int temp = round ((tensao-.5)*100);
  Serial.println (tensao);
  lcd.clear();
  lcd.print("Temperatura:");
  lcd.setCursor (0,1);
  lcd.print(temp);
  lcd.write(B10110010);
  lcd.write("C");
  if (temp < -20.0 || temp > -5.0){
    digitalWrite(buzzerPin, HIGH);
  } else{
    digitalWrite(buzzerPin, LOW);
  }
  delay(500);
}