#include <MD_MAX72xx.h>
#include <SPI.h>

#define MAX_DEVICES 20
#define DIN_PIN 23
#define CLK_PIN 18
#define CS_PIN  5

// Use hardware SPI
MD_MAX72XX mx = MD_MAX72XX(MD_MAX72XX::FC16_HW, CS_PIN, MAX_DEVICES);

void setup() {
  mx.begin();
  mx.control(MD_MAX72XX::INTENSITY, 5); // brightness (0–15)
  mx.clear();

  // Light one pixel on each module
  for (uint8_t i = 0; i < MAX_DEVICES; i++) {
    mx.setPoint(3, 3 + (i * 8), true);  // one LED per module
    delay(100);
  }

  delay(1000);
  mx.clear();

  // Display numbers 0–19
  for (uint8_t i = 0; i < MAX_DEVICES; i++) {
    mx.setChar(i, '0' + (i % 10)); // shows 0–9 twice
    delay(100);
  }
}

void loop() {}

