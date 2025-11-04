#include <LedControl.h>

LedControl lc(23, 18, 5, 4);  // DIN=23, CLK=18, CS=5, 4 modules

byte H[8] = {
  B10010010,
  B10010010,
  B10010010,
  B11111110,
  B10010010,
  B10010010,
  B10010010,
  B10010010
};

byte E[8] = {
  B11111110,
  B10000000,
  B10000000,
  B11111110,
  B10000000,
  B10000000,
  B10000000,
  B11111110
};

byte L[8] = {
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B10000000,
  B11111110
};

byte O[8] = {
  B01111100,
  B10000010,
  B10000010,
  B10000010,
  B10000010,
  B10000010,
  B10000010,
  B01111100
};

// flip each row to fix mirror issue
byte reverseBits(byte b) {
  b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
  b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
  b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
  return b;
}

void drawLetter(int dev, byte letter[8]) {
  for (int row = 0; row < 8; row++) {
    lc.setRow(dev, 7 - row, reverseBits(letter[row]));
  }
}

void setup() {
  for (int i = 0; i < 4; i++) {
    lc.shutdown(i, false);
    lc.setIntensity(i, 8);
    lc.clearDisplay(i);
  }

  // Draw "HELLO" in correct orientation (mirrored fix)
  drawLetter(3, H);
  drawLetter(2, E);
  drawLetter(1, L);
  drawLetter(0, O);
}

void loop() {}

