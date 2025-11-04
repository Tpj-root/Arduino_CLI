#include <LedControl.h>  // local or installed library

// Pins: DIN, CLK, CS, number of devices
LedControl lc = LedControl(23, 18, 5, 4);

void setup() {
  for (int i = 0; i < 4; i++) {
    lc.shutdown(i, false);   // Wake up each display
    lc.setIntensity(i, 8);   // Brightness (0–15)
    lc.clearDisplay(i);      // Clear all
  }

  // Simple smiley face pattern (8x8)
  byte smiley[8] = {
    B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100
  };

  // Draw smiley on all 4 displays
  for (int dev = 0; dev < 4; dev++) {
    for (int row = 0; row < 8; row++) {
      lc.setRow(dev, row, smiley[row]);
    }
  }
}

void loop() {
}

