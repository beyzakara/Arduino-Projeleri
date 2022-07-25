#include <LiquidCrystal.h>
#include <LCDKeypad.h>


#define DAYS 0
#define HOURS 1
#define MINUTES 2
#define SECONDS 3


LCDKeypad lcd;

// The time model
unsigned int days = 0;
unsigned int hours = 0;
unsigned int minutes = 0;
unsigned int seconds = 0;
unsigned int setting = 0;

void setup() {

lcd.begin(16,2);


lcd.setCursor(0,0);


lcd.print(” Digital Boy”);
delay(2000);
lcd.clear();
lcd.print(“Ayarlar: Gun “);
}

void loop() {

incTime();


printTime();


buttonListen();
}

void buttonListen() {

for (int i = 0; i < 5; i++) {

int button = lcd.button();

switch (button) {


case KEYPAD_RIGHT:
setting++;
break;

case KEYPAD_LEFT:
setting–;
break;

case KEYPAD_UP:
switch (setting) {
case DAYS:
days++;
break;
case HOURS:
hours++;
break;
case MINUTES:
minutes++;
break;
case SECONDS:
seconds++;
}
break;


case KEYPAD_DOWN:
switch (setting) {
case DAYS:
days–;
if (days == -1) days = 99;
break;
case HOURS:
hours–;
if (hours == -1) hours = 23;
break;
case MINUTES:
minutes–;
if (minutes == -1) minutes = 59;
break;
case SECONDS:
seconds–;
if (seconds == -1) seconds = 59;
}
}

setting %= 4;
printSetting();

days %= 100;
hours %= 24;
minutes %= 60;
seconds %= 60;
printTime();


while(millis() % 200 != 0);
}
}


void printSetting() {
lcd.setCursor(9,0);

switch (setting) {
case DAYS:
lcd.print("Gun ");
break;
case HOURS:
lcd.print("Saat ");
break;
case MINUTES:
lcd.print("Dakika");
break;
case SECONDS:
lcd.print("Saniye");
}
}


void incTime() {

seconds++;

if (seconds == 60) {

seconds = 0;

minutes++;

if (minutes == 60) {

minutes = 0;


hours++;

if (hours == 24) {

hours = 0;

days++;
}
}
}
}

void printTime() {

lcd.setCursor(0,1);
char time[17];
sprintf(time, "%02i Gun %02i:%02i:%02i", days, hours, minutes, seconds);
lcd.print(time);
}
