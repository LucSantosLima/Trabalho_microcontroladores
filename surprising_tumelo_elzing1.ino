#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,8,7,6,5);

const int buzzerPin = 10;

int degree;
double realDegree;
int TempBase = 0;
int celsius = 0;
String ledBuffer;

void setup()
{
  lcd.begin(16, 2);
  degree = 0;
  realDegree = 0;
  lcd.print("Temperatura:");
  
  pinMode(A0, INPUT);
  Serial.begin(9600);
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
  lcd.print("                ");
  degree = analogRead(0);
  realDegree = (double)degree/1024;
  realDegree *= 5;
  realDegree -= 0.5;
  realDegree *= 100;
  lcd.setCursor(0,1);
  
  String output = String(realDegree) + String((char)178) + "C";
  lcd.print(output);
  
  TempBase = 1;
  
  celsius = map (((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  
  Serial.print(celsius);
  Serial. print(" C, ");
  
  if (celsius < TempBase) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
  }
  if (celsius >= TempBase && celsius <= TempBase + 10) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  if (celsius >= TempBase + 10 && celsius < TempBase + 30) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  if (celsius >= TempBase + 50) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
   if (celsius < -40.0 || celsius > -1.0){
    digitalWrite(buzzerPin, HIGH);
  } else{
    digitalWrite(buzzerPin, LOW);
  }
  delay(1000);
}