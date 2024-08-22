void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");

  mqttSetup();

  roadSetup();
  
  carflowSetup();

  cameraSetup();

  barrierSetup();

}

void loop() {
  // put your main code here, to run repeatedly:
  barrierLoop();

  carflowLoop();

  mqttLoop();

  cameraLoop();

  roadLoop();

  delay(10); // this speeds up the simulation
}
