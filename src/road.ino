const int roadlightPin = 2;
const int photoresistorPin = 0;

const int buzzerPin = 12;
const int buttonRed = 26;
const int buttonGreen = 27;

void roadSetup() {
  pinMode(roadlightPin, OUTPUT);
  pinMode(photoresistorPin, INPUT);

  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonRed, INPUT);
  pinMode(buttonGreen, INPUT);
}

void roadLoop() {
  int value = digitalRead(photoresistorPin);
  digitalWrite(roadlightPin, value);
  
  int br = digitalRead(buttonRed);
  int bg = digitalRead(buttonGreen);
}