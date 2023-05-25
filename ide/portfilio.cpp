#include <Arduino.h>

const int clockPin = 2;         // Connect this to the clock input of both flip-flops
const int resetPin = 1;         // Connect this to the reset input (R) of FF1

const int firstLEDPin = 5;      // Connect this to the anode of the first LED
const int secondLEDPin = 6;     // Connect this to the anode of the second LED
const int thirdLEDPin = 7;      // Connect this to the anode of the third LED

const int Q1Pin = 3;            // Connect this to the Q output of FF2
const int Q2Pin = 4;            // Connect this to the Q̅ output of FF1

void setup() {
  pinMode(clockPin, OUTPUT);
  pinMode(resetPin, OUTPUT);
  
  pinMode(firstLEDPin, OUTPUT);
  pinMode(secondLEDPin, OUTPUT);
  pinMode(thirdLEDPin, OUTPUT);
  
  digitalWrite(resetPin, HIGH);  // Set the reset pin high to disable the reset initially
}

void loop() {
  digitalWrite(clockPin, HIGH);  // Apply a clock pulse
  delay(100);                    // Adjust the delay according to your desired frequency
  
  digitalWrite(clockPin, LOW);
  delay(100);
  
  if (digitalRead(resetPin) == LOW) {
    // Reset condition detected (binary count 010)
    digitalWrite(resetPin, HIGH);   // Enable the reset
    delay(10);                      // Keep reset active for a short duration
    digitalWrite(resetPin, LOW);    // Disable the reset
  }
  
  // Display the binary count on LEDs
  int count = (digitalRead(Q2Pin) << 2) | (digitalRead(Q1Pin) << 1) | digitalRead(Q2Pin);
  digitalWrite(firstLEDPin, (count & 0b001) ? HIGH : LOW);
  digitalWrite(secondLEDPin, (count & 0b010) ? HIGH : LOW);
  digitalWrite(thirdLEDPin, (count & 0b100) ? HIGH : LOW);
}
