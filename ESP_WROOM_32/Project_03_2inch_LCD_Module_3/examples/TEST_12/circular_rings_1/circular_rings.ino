#include <TFT_eSPI.h>
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();  // Initialize display

#define SCREEN_W 240
#define SCREEN_H 320
#define CENTER_X (SCREEN_W/2)
#define CENTER_Y (SCREEN_H/2)
#define MAX_RADIUS 60
#define RING_COUNT 6

void setup() {
  tft.init();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);
}

void loop() {
  tft.fillScreen(TFT_BLACK);

  unsigned long t = millis();
  
  for (int r = 1; r <= RING_COUNT; r++) {
    // Calculate dynamic radius and brightness
    float angle = t * 0.002 + r; // rotation effect
    int radius = (MAX_RADIUS / RING_COUNT) * r + (sin(angle) * 5);
    uint8_t brightness = 128 + 127 * sin(angle * 1.5); // pulsating

    // Draw ring with brightness gradient
    drawRing(CENTER_X, CENTER_Y, radius, brightness);
  }

  delay(30); // animation speed
}

// Draw a circular ring
void drawRing(int x0, int y0, int radius, uint8_t brightness) {
  for (int i = 0; i < 360; i += 5) {
    float rad = i * 3.14159 / 180.0;
    int x = x0 + radius * cos(rad);
    int y = y0 + radius * sin(rad);

    uint16_t color = tft.color565(brightness, brightness/4, 0); // orange glow
    tft.drawPixel(x, y, color);
  }
}

