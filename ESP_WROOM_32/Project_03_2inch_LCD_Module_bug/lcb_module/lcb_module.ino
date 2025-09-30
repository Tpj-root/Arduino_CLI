#include <SPI.h>
#include <TFT_eSPI.h>  // Install TFT_eSPI library

TFT_eSPI tft = TFT_eSPI();  // Default pins from User_Setup.h

// Rectangle variables
int x = 0, y = 30;
int rectSize = 20;
int xStep = 5;

void setup() {
  Serial.begin(115200);

  // Initialize display
  tft.init();
  tft.setRotation(1);           // Landscape
  tft.fillScreen(TFT_BLACK);    // Clear screen

  // Text setup
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  tft.drawString("ESP32 ST7789 Test", 10, 10);

  Serial.println("LCD Initialized!");
}

void loop() {
  // Erase previous rectangle (background color)
  tft.fillRect(x, y, rectSize, rectSize, TFT_BLACK);

  // Move rectangle
  x += xStep;
  if (x > tft.width() - rectSize) {
    x = 0;
    y += rectSize + 5;
    if (y > tft.height() - rectSize) y = 30; // Reset vertical
  }

  // Draw rectangle (foreground color)
  tft.fillRect(x, y, rectSize, rectSize, TFT_RED);

  // Draw additional color samples for testing
  tft.fillRect(10, 60, 30, 30, TFT_BLUE);
  tft.fillRect(50, 60, 30, 30, TFT_GREEN);
  tft.fillRect(90, 60, 30, 30, TFT_YELLOW);
  tft.fillRect(130, 60, 30, 30, TFT_ORANGE);
  tft.fillRect(170, 60, 30, 30, TFT_WHITE);

  // Debug output
  Serial.printf("Rectangle position x=%d y=%d\n", x, y);

  delay(50);  // Smooth animation
}
