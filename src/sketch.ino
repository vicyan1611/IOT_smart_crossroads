#include <LiquidCrystal_I2C.h>
const int roadlightPin = 2;
const int photoresistorPin = 0;
const int buzzerPin = 12;
const int buttonRed = 26;
const int buttonGreen = 27;


LiquidCrystal_I2C lcd(0x27, 16,2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");

  mqttSetup();

  pinMode(roadlightPin, OUTPUT);
  pinMode(photoresistorPin, INPUT);

  pinMode(buzzerPin, OUTPUT);

  pinMode(buttonRed, INPUT);
  pinMode(buttonGreen, INPUT);
  
  carflowSetup();

  dhtSetup();

  pirSetup();
}

void roadlight() {
  int value = digitalRead(photoresistorPin);
  digitalWrite(roadlightPin, value);
}

void roadpassing() {
  // tone(buzzerPin,432);
  //notone(buzzerPin);
  int br = digitalRead(buttonRed);
  int bg = digitalRead(buttonGreen);
}

void lcddisplay() {
  lcd.init();
  lcd.backlight();

  // Print something
  lcd.setCursor(0, 0);
  lcd.print("Drive Safely");
}

void loop() {
  // put your main code here, to run repeatedly:
  roadlight();
  roadpassing();
  lcddisplay();
  carflowLoop();
  mqttLoop();
  dhtLoop();
  pirLoop();
  delay(10); // this speeds up the simulation
}
