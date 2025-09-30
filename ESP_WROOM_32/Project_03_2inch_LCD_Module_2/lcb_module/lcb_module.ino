#include <TFT_eSPI.h>  // TFT library

// Initialize TFT
TFT_eSPI tft = TFT_eSPI();  // Pins are configured in User_Setup.h or in your defines

void setup() {
  Serial.begin(115200);

  // Initialize display
  tft.init();
  tft.setRotation(1);           // Landscape orientation
  tft.fillScreen(TFT_BLACK);    // Clear screen

  // Draw text
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  tft.setCursor(20, 120);
  tft.print("Hello World!");

  Serial.println("Display Initialized!");
}

void loop() {
  // Nothing to animate for now
}

