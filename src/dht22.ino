#include <DHTesp.h>

int dhtPin = 25;

DHTesp dhtSensor;

void dhtSetup() {
  dhtSensor.setup(25, DHTesp::DHT22);
}

unsigned long long dhtlastMillis = 0;
unsigned long long dhtinterval = 3000;

void dhtLoop() {
  unsigned long long currentMillis = millis();
  if (currentMillis - dhtlastMillis > dhtinterval) {
    TempAndHumidity data = dhtSensor.getTempAndHumidity();
    //Serial.println("Temp: " + String(data.temperature, 2) + "°C");
   // Serial.println("Humidity: " + String(data.humidity, 1) + "%");
    //Serial.println("---");
    dhtlastMillis = currentMillis;
  }
}