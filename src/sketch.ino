#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16,2);

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

void lcddisplay() {
  lcd.init();
  lcd.backlight();

  // Print something
  lcd.setCursor(0, 0);
  lcd.print("Drive Safely");
}

void loop() {
  // put your main code here, to run repeatedly:
  roadLoop();

  lcddisplay();

  carflowLoop();

  mqttLoop();

  cameraLoop();

  barrierLoop();
  
  delay(10); // this speeds up the simulation
}
