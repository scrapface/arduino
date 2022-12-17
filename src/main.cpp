#include <Arduino.h>
#include <Servo.h>
#include <SoftwareSerial.h>

#include "config.h"

// Setup devices.
SoftwareSerial bluetoothSerial(Config::BLUETOOTH_RX_PIN, Config::BLUETOOTH_TX_PIN);
Servo servo;

void setup() {
  // Initialize serial.
  Serial.begin(9600);
  bluetoothSerial.begin(9600);

  // Initialize servo.
  servo.attach(Config::SERVO_PIN);
}

void loop() {
  if (bluetoothSerial.available()) {
    Serial.println(bluetoothSerial.read());
  }
}
