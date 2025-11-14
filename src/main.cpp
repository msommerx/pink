#include <Arduino.h>

// Pin definitions for 6 DI readings — change these to match your wiring
const uint8_t DI_PINS[6] = {2, 4, 5, 12, 13, 14}; // example ESP32 GPIOs

// Optional: declare any custom functions here
int myFunction(int, int);

void setup() {
  Serial.begin(115200);


  // Configure DI pins. Using INPUT_PULLUP by default — switch to INPUT if using external pull-downs.
  for (uint8_t i = 0; i < 6; ++i) {
    pinMode(DI_PINS[i], INPUT_PULLUP);
  }

  int result = myFunction(2, 3); // example call
}


void loop() {
  // Read and print all 6 DI pins in a single line: "D2:1 D4:0 ..."
  String out;
  for (uint8_t i = 0; i < 6; ++i) {
    int val = digitalRead(DI_PINS[i]);
    out += "D";
    out += DI_PINS[i];
    out += ":";
    out += val;
    if (i < 5) out += " ";
  }
  Serial.println(out);
  delay(1000); // sample once per second
}

int myFunction(int x, int y) {
  return x + y;
}
