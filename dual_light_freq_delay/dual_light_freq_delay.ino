// Pin definitions for Arduino Uno
const int inputPin = 2;   // Pin for receiving the TTL signal (digital pin 2)
const int outputPin1 = 3; // First output line (digital pin 3)
const int outputPin2 = 4; // Second output line (digital pin 4)

// Constants for 40 Hz pulse
const int pulseFrequency = 40;           // 40 Hz
const int pulsePeriod = 1000 / pulseFrequency;  // Period in milliseconds (25 ms)

void setup() {
  // Set pin modes
  pinMode(inputPin, INPUT);       // Input from the TTL signal
  pinMode(outputPin1, OUTPUT);    // First output
  pinMode(outputPin2, OUTPUT);    // Second output
}

void loop() {
  // Read the state of the input pin
  int inputState = digitalRead(inputPin);
  
  if (inputState == HIGH) {
    // Output 1: Immediately pulse at 40 Hz for 500 ms
    unsigned long startTime = millis();  // Record the start time
    while (millis() - startTime < 500) { // Keep pulsing for 500 ms
      digitalWrite(outputPin1, HIGH);    // LED on
      delay(pulsePeriod / 2);            // On for half the period (12.5 ms)
      digitalWrite(outputPin1, LOW);     // LED off
      delay(pulsePeriod / 2);            // Off for half the period (12.5 ms)
    }

    // Output 2: Delay for 500 ms, then pulse at 40 Hz for 500 ms
    delay(500);                          // Wait for 500 ms before turning on Output 2
    startTime = millis();                // Record the new start time for Output 2
    while (millis() - startTime < 500) { // Pulse at 40 Hz for 500 ms
      digitalWrite(outputPin2, HIGH);    // LED on
      delay(pulsePeriod / 2);            // On for half the period (12.5 ms)
      digitalWrite(outputPin2, LOW);     // LED off
      delay(pulsePeriod / 2);            // Off for half the period (12.5 ms)
    }
  }
}
