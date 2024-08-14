
#include <ESP32Servo.h>

Servo servo;

int pirPin = 33;  
int pirState = LOW;  
void barrierSetup() {
  pinMode(pirPin, INPUT);
  servo.attach(15);
  servo.write(0);
}

void barrierLoop() {
  int val = digitalRead(pirPin);  
  if (val == HIGH) {           
    if (pirState == LOW) {
      // we have just turned on
      servo.write(90);
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    if (pirState == HIGH) {
      // we have just turned of
      servo.write(0);
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
}