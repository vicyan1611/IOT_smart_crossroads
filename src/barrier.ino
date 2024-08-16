
#include <ESP32Servo.h>

Servo servo;

int pirPin = 33;  
int pirState = LOW;  
const int buzzerPin = 12;
void barrierSetup() {
  pinMode(pirPin, INPUT);
  servo.attach(15);
  pinMode(buzzerPin, OUTPUT);
}

void barrierLoop() {
  int val = digitalRead(pirPin);  
  if (val == HIGH) {           
    if (pirState == LOW) {
      // we have just turned on
      servo.write(90);
      tone(buzzerPin, 100, 5000);
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
    
  } else {
    if (pirState == HIGH) {
      servo.write(0);
      // we have just turned of
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
}