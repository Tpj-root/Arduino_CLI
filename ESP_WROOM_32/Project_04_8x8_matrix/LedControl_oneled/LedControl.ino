#include <LedControl.h>

LedControl lc = LedControl(23, 18, 5, 4);

void setup() {
  Serial.begin(115200);
  Serial.println("Init 8x8 modules...");

  for (int i = 0; i < 4; i++) {
    lc.shutdown(i, false);
    lc.setIntensity(i, 8);
    lc.clearDisplay(i);
    Serial.printf("Module %d ready\n", i);
  }

  // Test single pixel on module 0
  lc.setLed(0, 3, 3, true);
  Serial.println("Pixel ON at (3,3) on module 0");
}

void loop() {}

