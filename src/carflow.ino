int trig0 =  4; int echo0 = 16;

long calDis0() {
  digitalWrite(trig0, LOW);
  delayMicroseconds(2);
  digitalWrite(trig0, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig0, LOW);

  long duration = pulseIn(echo0, HIGH);
  long distanceCm = duration * 0.034 / 2;
  return distanceCm;
}

long long lastMillis = 0;
int countcar = 0;

void carflowLoop() {
  int dis0 = calDis0();
  long long curMillis = millis();
  if (curMillis - lastMillis > 10000) { // Đếm số lượng xe trong mỗi 10s
    Serial.print("Total cars");
    Serial.println(countcar);
    countcar = 0;
    lastMillis = curMillis;
  }
  if (dis0 < 200) {
    countcar += 1;
  }
}

void carflowSetup() {
  pinMode(4, OUTPUT); pinMode(16, INPUT); //ultrasonic0 pin
}