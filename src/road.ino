const int roadlightPin = 2;
const int photoresistorPin = 0;

const int buttonRed = 26;
const int buttonGreen = 27;

void roadSetup() {
  pinMode(roadlightPin, OUTPUT);
  pinMode(photoresistorPin, INPUT);

  pinMode(buttonRed, INPUT);
  pinMode(buttonGreen, INPUT);
}

void roadLoop() {
  int value = digitalRead(photoresistorPin);
  digitalWrite(roadlightPin, value);
  
  int br = digitalRead(buttonRed);
  int bg = digitalRead(buttonGreen);
  if (bg == HIGH || br == HIGH) {
    Serial.println("walker: button is pressed");
    publishData("/iot/walker", "1");
  }
}