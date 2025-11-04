#include <MD_MAX72xx.h>
#include <SPI.h>

#define MAX_DEVICES 1
#define CS_PIN 5

MD_MAX72XX mx = MD_MAX72XX(MD_MAX72XX::FC16_HW, CS_PIN, MAX_DEVICES);

void setup() {
  mx.begin();
  mx.control(MD_MAX72XX::INTENSITY, 5);
  mx.clear();

  // Turn ON one pixel at (row 3, col 3)
  mx.setPoint(3, 3, true);
}

void loop() {}

