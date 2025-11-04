#include <LedControl.h>

// DIN, CLK, CS, number of devices
LedControl lc(23, 18, 5, 4);

void setup() {
  for (int i = 0; i < 4; i++) {
    lc.shutdown(i, false);
    lc.setIntensity(i, 8);
    lc.clearDisplay(i);
  }

  // Simple font for letters (8x8 bitmaps)
  byte H[8] = {B10000001, B10000001, B10000001, B11111111, B10000001, B10000001, B10000001, B00000000};
  byte E[8] = {B11111111, B10000000, B10000000, B11111110, B10000000, B10000000, B11111111, B00000000};
  byte L[8] = {B10000000, B10000000, B10000000, B10000000, B10000000, B10000000, B11111111, B00000000};
  byte O[8] = {B01111110, B10000001, B10000001, B10000001, B10000001, B10000001, B01111110, B00000000};

  // Show each letter on each module (H E L L O)
  drawLetter(0, H);
  drawLetter(1, E);
  drawLetter(2, L);
  drawLetter(3, O);
}

void drawLetter(int dev, byte letter[8]) {
  for (int row = 0; row < 8; row++) {
    lc.setRow(dev, row, letter[row]);
  }
}

void loop() {}

