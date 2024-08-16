#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16,2);

const int roadlightPin = 2;
const int photoresistorPin = 0;

const int buttonRed = 26;
const int buttonGreen = 27;
const int buzzerPin = 12;

void roadSetup() {
  pinMode(roadlightPin, OUTPUT);
  pinMode(photoresistorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonRed, INPUT);
  pinMode(buttonGreen, INPUT);
}
String lcdstr = "Drive Safely";
void handleLCD(String strmessage) {
  lcdstr = strmessage;
}
void roadLoop() {
  int value = digitalRead(photoresistorPin);
  digitalWrite(roadlightPin, value);

  lcd.init();
  lcd.backlight();

  // Print something
  lcd.setCursor(0, 0);
  lcd.print(lcdstr);

  int br = digitalRead(buttonRed);
  int bg = digitalRead(buttonGreen);
  if (bg == HIGH || br == HIGH) {
    Serial.println("walker: button is pressed");
    tone(buzzerPin, 100, 1000);
    publishData("/iot/walker", "1");
  }
}