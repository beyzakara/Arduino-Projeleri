#include <LiquidCrystal.h>
 #define buzzer 9
int lm35Pin = A0;
float sicaklik = 0;
int okunan_deger = 0;
float sicaklik_gerilim = 0;
int led = 8;
int zaman = 50;

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
 
void setup() 
{
  Serial.begin(9600);
   pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);
  lcd.begin(16, 2);
  analogReference(INTERNAL);
  lcd.print("Sicaklik Olcumu:");
}
 
void loop()
{
  okunan_deger = analogRead(lm35Pin);
  sicaklik_gerilim = (okunan_deger / 1023.0)*5000;
  sicaklik = sicaklik_gerilim /10.0; 
  Serial.println(sicaklik);
  int sicaklikVolt = analogRead(lm35Pin);
  float sicaklikC = sicaklikC = sicaklikVolt / 9.31; 
  lcd.setCursor(0, 1);
  lcd.print(sicaklikC);
  lcd.setCursor(6,1);
  lcd.print("derece");
  delay(100);
  if(sicaklik >= 130){
    digitalWrite(led,HIGH);
    digitalWrite(buzzer,HIGH);
    delay(zaman);
    digitalWrite(led,LOW);
    digitalWrite(buzzer,LOW);
    delay(zaman);
  }
  else{

    digitalWrite(led,LOW);
    digitalWrite(buzzer,LOW);
    
    
  }
}
