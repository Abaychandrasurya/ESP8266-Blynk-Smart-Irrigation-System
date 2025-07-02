#define BLYNK_TEMPLATE_ID "TMPLxxxxx"
#define BLYNK_TEMPLATE_NAME "Soil Moisture"
#define BLYNK_AUTH_TOKEN "YourAuthToken"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = " name ";        //name 
char pass[] = " password ";     //password

#define DHTPIN 4        // GPIO4 = D2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

#define MOISTURE_SENSOR A0
#define RELAY_PIN 5     // GPIO5 = D1 

int moistureThreshold = 700;
bool manualPumpControl = false;
bool pumpState = false;

BlynkTimer timer;

BLYNK_WRITE(V4) {
  int value = param.asInt();
  manualPumpControl = (value == 1);
  pumpState = manualPumpControl;

  digitalWrite(RELAY_PIN, manualPumpControl ? LOW : HIGH);

  Serial.print("Manual Control - Pump ");
  Serial.println(manualPumpControl ? "ON" : "OFF");
}

void autoWatering() {
  int moisture = analogRead(MOISTURE_SENSOR);
  float humidity = dht.readHumidity();
  float temp = dht.readTemperature();

  Serial.print("Moisture: ");
  Serial.println(moisture);
  Serial.print("Temp: ");
  Serial.println(temp);
  Serial.print("Humidity: ");
  Serial.println(humidity);

  if (!isnan(temp) && !isnan(humidity)) {
    Blynk.virtualWrite(V0, moisture);
    Blynk.virtualWrite(V2, temp);
    Blynk.virtualWrite(V3, humidity);
  }

  if (!manualPumpControl) {
    if (moisture > moistureThreshold) {
      digitalWrite(RELAY_PIN, LOW);
      if (!pumpState) {
        pumpState = true;
        Blynk.virtualWrite(V4, 1);
        Serial.println("Auto Mode - Pump ON");
      }
    } else {
      digitalWrite(RELAY_PIN, HIGH);
      if (pumpState) {
        pumpState = false;
        Blynk.virtualWrite(V4, 0);
        Serial.println("Auto Mode - Pump OFF");
      }
    }
  }
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  dht.begin();

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);

  timer.setInterval(3000L, autoWatering);
}

void loop() {
  Blynk.run();
  timer.run();
}
