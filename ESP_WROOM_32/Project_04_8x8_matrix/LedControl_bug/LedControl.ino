#include <MD_MAX72xx.h>
#include <SPI.h>

#define MAX_DEVICES 2
#define CS_PIN 5

MD_MAX72XX mx = MD_MAX72XX(MD_MAX72XX::FC16_HW, CS_PIN, MAX_DEVICES);

void setup() {
  mx.begin();
  mx.control(MD_MAX72XX::INTENSITY, 5); // brightness 0–15
  mx.clear();

  // Turn on all LEDs on module 0
  for (uint8_t row = 0; row < 8; row++) {
    for (uint8_t col = 0; col < 8; col++) {
      mx.setPoint(row, col, true);
    }
  }
  delay(1000);

  // Clear module 0 and light up module 1
  mx.clear();
  for (uint8_t row = 0; row < 8; row++) {
    for (uint8_t col = 8; col < 16; col++) {
      mx.setPoint(row, col, true);
    }
  }
  delay(1000);

  mx.clear();
}

void loop() {}

