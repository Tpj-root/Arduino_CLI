#include <MD_MAX72xx.h>
#include <SPI.h>

#define MAX_DEVICES 20
#define CS_PIN 5

MD_MAX72XX mx = MD_MAX72XX(MD_MAX72XX::FC16_HW, CS_PIN, MAX_DEVICES);

void setup() {
  mx.begin();
  mx.control(MD_MAX72XX::INTENSITY, 5);
  mx.clear();

  // Turn ON all pixels correctly on all 20 modules
  for (int d = 0; d < MAX_DEVICES; d++) {
    for (int row = 0; row < 8; row++) {
      for (int col = 0; col < 8; col++) {
        mx.setPoint(row, d * 8 + col, true);  // handles chaining
      }
    }
  }
}

void loop() {}

