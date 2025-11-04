#include <MD_MAX72xx.h>
#include <SPI.h>

#define MAX_DEVICES 20
#define CS_PIN 5

MD_MAX72XX mx = MD_MAX72XX(MD_MAX72XX::FC16_HW, CS_PIN, MAX_DEVICES);

// convert your (x, y) (bottom-left origin) to matrix coords (top-left origin)
void setPixelXY(int x, int y, bool state) {
  int row = 7 - y;      // flip vertically (bottom → top)
  int col = x;          // left → right stays same
  mx.setPoint(row, col, state);
}

void setup() {
  mx.begin();
  mx.control(MD_MAX72XX::INTENSITY, 5);
  mx.clear();

  // Example points:
  setPixelXY(0, 0, true);    // bottom-left
  setPixelXY(0, 7, true);    // top-left
  setPixelXY(7, 0, true);    // bottom of first module
  setPixelXY(39, 0, true);   // bottom-right of 5th module (8×5−1)
  setPixelXY(159, 0, true);  // top-right (last module)
}

void loop() {}

