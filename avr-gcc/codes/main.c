#include <avr/io.h>
#include <util/delay.h>

// Pin assignments
#define B_PIN PD3   // Input B (connected to pin 3)
#define LED_PIN PB5 // Output LED (connected to pin 13)

void pinMode(uint8_t pin, uint8_t mode) {
  if (mode == 1)
    DDRD &= ~(1 << pin); // Set pin as input
  else
    DDRB |= (1 << pin);  // Set pin as output
}

void digitalWrite(uint8_t pin, uint8_t value) {
  if (value == 1)
    PORTB |= (1 << pin);  // Set pin HIGH
  else
    PORTB &= ~(1 << pin); // Set pin LOW
}

void setup() {
  pinMode(LED_PIN, 0);     // Set LED_PIN as output
}

void loop() {
  // Read the input value
  int B = (PIND & (1 << B_PIN)) ? 1 : 0;
  
  // Calculate the output
  int F = !B;
  
  // Display the output using the LED
  digitalWrite(LED_PIN, F);
  
  _delay_ms(1000); // Delay for 1 second
}

int main(void) {
  setup();

  while (1) {
    loop();
  }

  return 0;
}
