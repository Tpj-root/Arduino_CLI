#include <MD_MAX72xx.h>
#include <SPI.h>

#define MAX_DEVICES 20
#define CS_PIN 5

MD_MAX72XX mx = MD_MAX72XX(MD_MAX72XX::FC16_HW, CS_PIN, MAX_DEVICES);

void setup() {
  mx.begin();
  mx.control(MD_MAX72XX::INTENSITY, 5);
  mx.clear();

  // Turn ON all pixels (bottom-left origin)
  for (int x = 0; x < MAX_DEVICES * 8; x++) {   // total 160 columns
    for (int y = 0; y < 8; y++) {               // 8 rows
      mx.setPoint(7 - y, x, true);              // bottom → top
    }
  }
}

void loop() {}

