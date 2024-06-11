#include <Arduino.h>

// Set the GPIO pins for the ultrasonic sensor and LED
const int ultrasonicTrigPin = 14;
const int ultrasonicEchoPin = 15;
const int ledPin = 16;

void setup() {
  // Set the GPIO modes for the ultrasonic sensor and LED
  pinMode(ultrasonicTrigPin, OUTPUT);
  pinMode(ultrasonicEchoPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // Initialize the serial communication
  Serial.begin(115200);
}

void loop() {
  // Send a short pulse to trigger the ultrasonic sensor
  digitalWrite(ultrasonicTrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(ultrasonicTrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultrasonicTrigPin, LOW);

  // Measure the duration of the pulse from the ultrasonic sensor
  long duration = pulseIn(ultrasonicEchoPin, HIGH);

  // Calculate the distance in cm
  int distance = duration * 0.034 / 2;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Blink the LED based on the distance
  if (distance < 10) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  // Wait for a short period before the next measurement
  delay(100);
}