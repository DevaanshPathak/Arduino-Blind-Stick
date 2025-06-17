# 👨‍🦯 Arduino-Based Blind Stick with HC-SR04, Buzzer, and LED

This project is a low-cost, Arduino-powered smart stick designed to assist visually impaired individuals by detecting nearby obstacles using an ultrasonic sensor. Alerts are provided through a buzzer and an LED based on object distance.

---

## 📌 Features

- Ultrasonic distance measurement using HC-SR04
- Audible alerts using a buzzer
- Visual alerts using an LED
- Compact design with custom PCB
- Powered by Arduino Uno

---

## 🧩 Components Used

| Component        | Quantity |
|------------------|----------|
| Arduino Uno     | 1        |
| HC-SR04 Sensor   | 1        |
| Buzzer           | 1        |
| LED (5mm)        | 1        |
| 220Ω Resistor    | 1        |
| Jumper Cables(Male to Female)  | As needed |
| Power source (e.g., 9V battery) | 1 |
| Breadboard      | 1        |
| Battery Connector| 1|
---

## 🔌 Circuit Schematic

![Schematic](https://hc-cdn.hel1.your-objectstorage.com/s/v3/72ea7c5601b53c8f34744635d3f1fde162040aef_schematic.png)

---

## 🖼️ PCB Layout (2D)

![2D PCB Layout](https://hc-cdn.hel1.your-objectstorage.com/s/v3/0bcd6bad357ee9e74c2580f9f83d5783ea8617b4_2d_pcb.png)

---

## 📷 3D PCB View

![3D PCB](https://hc-cdn.hel1.your-objectstorage.com/s/v3/9d9b3e1e0630cd1b4838143f17b7eff5894ab892_3d_pcb.png)

---

## ⚙️ Arduino Code

The firmware reads distance from the ultrasonic sensor and triggers alerts if an object is within a safe range (e.g., 25 cm).

```cpp
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledPin = 13;

// defines variables
long duration;
int distance;
int safetyDistance;


void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}


void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

safetyDistance = distance;
if (safetyDistance <= 25){
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
}

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}