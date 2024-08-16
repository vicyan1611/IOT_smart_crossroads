
#include <ESP32Servo.h>

Servo servo;

const int pirPin = 33;  
int pirState = LOW;  
int isControlBarrier = 0;

void barrierSetup() {
  pinMode(pirPin, INPUT);
  servo.attach(17);
  servo.write(0);
}

void handleBarrier(String strStatus) {
  int status = strStatus.toInt();
  if (status == 1) {
    isControlBarrier = 1;
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
    isControlBarrier = 0;
  }
}


void barrierLoop() {
  if (isControlBarrier == 1) return;
  int val = digitalRead(pirPin);  
  if (val == HIGH) {           
    if (pirState == LOW) {
      // we have just turned on
      servo.write(90);
      Serial.println("motion begin");
      pirState = HIGH;
    }
    
  } else {
    if (pirState == HIGH) {
      // we have just turned off
      servo.write(0);
      Serial.println("motion end");
      pirState = LOW;
    }
  }
}