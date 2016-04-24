#include <Arduino.h>
#include <MsTimer2.h>

#define LED_PIN 13

unsigned long hz2interval(unsigned long hz) {
  return 500 / hz;
}

void blink() {
  static boolean output = HIGH;
  digitalWrite(LED_PIN, output);
  output = !output;
}

void setup() {
  static unsigned long hz = 120;
  pinMode(LED_PIN, OUTPUT);
  MsTimer2::set(hz2interval(hz), blink);
  MsTimer2::start();
}

void loop() {
}
