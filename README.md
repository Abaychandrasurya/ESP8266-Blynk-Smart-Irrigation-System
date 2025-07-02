# 💧 ESP8266 Blynk Smart Irrigation System

This project uses an **ESP8266**, a **soil moisture sensor**, a **DHT22** sensor, and a **relay module** to create a **smart irrigation system**. It connects to **Blynk IoT** for remote monitoring and manual control of the water pump via a mobile app.

---

## 🚀 Features

- 🌡️ Read and display:
  - Soil Moisture
  - Temperature
  - Humidity
- 💧 Control water pump:
  - Automatically (based on soil moisture)
  - Manually (via Blynk app switch)
- 🌐 Wi-Fi connected and IoT-enabled via Blynk

---

## 🧰 Hardware Required

| Component               | Quantity |
|-------------------------|----------|
| ESP8266 (e.g., NodeMCU) | 1        |
| DHT22 Sensor            | 1        |
| Soil Moisture Sensor    | 1        |
| Relay Module (5V)       | 1        |
| Water Pump              | 1        |
| Jumper Wires            | As needed |
| External Power (for pump) | 1      |

---

## 🔌 Connection Diagram

![Smart Irrigation System](./image1.png)

---

## 🔌 Wiring Connections

### ESP8266 (NodeMCU)

| Pin       | Connected To             |
|-----------|--------------------------|
| A0        | Soil Moisture Sensor OUT |
| D2 (GPIO4)| DHT22 Data               |
| D1 (GPIO5)| Relay IN                 |
| 3.3V      | DHT22 VCC, Sensor VCC    |
| GND       | Common Ground            |

- ⚠️ Ensure your relay is compatible with 3.3V logic (or use a transistor circuit or 5V relay with external power).

---

## 📱 Blynk Configuration

| Virtual Pin | Purpose               |
|-------------|------------------------|
| V0          | Soil Moisture Reading  |
| V2          | Temperature Reading    |
| V3          | Humidity Reading       |
| V4          | Manual Pump Control (Switch) |

## ✅ Setup Instructions
- Install required libraries:
  - Blynk
  - DHT sensor library
  - Adafruit Unified Sensor
- Replace Blynk credentials and Wi-Fi SSID/PASS in code.
- Upload the sketch to ESP8266 via Arduino IDE.
- Open Serial Monitor at 115200 baud.
- Control and monitor system using Blynk app.

---

## 📈 Future Enhancements
- Add notification when soil is dry
- Integrate water level sensor for safety
- Use deep sleep for power saving in battery-operated systems
- Display status on OLED or LCD

---

## 🙌 About
- This is a beginner-friendly smart farming project designed to help automate plant watering while giving you remote insight and control through the Blynk IoT platform. Perfect for smart gardens, potted plants, or greenhouse automation.

---

### Blynk Auth

Replace these in your code with your own:

```cpp
#define BLYNK_TEMPLATE_ID "TMPLxxxxx"
#define BLYNK_TEMPLATE_NAME "Soil Moisture"
#define BLYNK_AUTH_TOKEN "YourAuthToken"
```

---

## 🔍 Sample Serial Monitor Output

```cpp
Moisture: 723
Temp: 27.4
Humidity: 56.1
Auto Mode - Pump ON
