#include <TFT_eSPI.h>
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();

#define SCREEN_W 240
#define SCREEN_H 320
#define CENTER_X (SCREEN_W/2)
#define CENTER_Y (SCREEN_H/2)
#define MAX_RADIUS 120  // Increase to fill screen
#define RING_COUNT 12   // More rings for full display

// Colors for rings
uint16_t ringColors[] = {TFT_RED, TFT_GREEN, TFT_WHITE, TFT_BLUE, TFT_YELLOW, TFT_ORANGE};

// Animation
int eyeBlink = 0;
bool blinkDirection = true;

void setup() {
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
}

void drawRings() {
  int radiusStep = MAX_RADIUS / RING_COUNT;
  for (int i = 0; i < RING_COUNT; i++) {
    tft.drawCircle(CENTER_X, CENTER_Y, radiusStep * (i + 1), ringColors[i % (sizeof(ringColors)/2)]);
  }
}

void drawFace() {
  // Eyes (polygon style)
  int eyeSize = 20;
  int eyeOffsetX = 40;
  int eyeOffsetY = 30;

  // Left eye
  tft.fillTriangle(CENTER_X - eyeOffsetX, CENTER_Y - eyeOffsetY,
                   CENTER_X - eyeOffsetX - 10, CENTER_Y - eyeOffsetY + 20 - eyeBlink,
                   CENTER_X - eyeOffsetX + 10, CENTER_Y - eyeOffsetY + 20 - eyeBlink,
                   TFT_BLACK);

  // Right eye
  tft.fillTriangle(CENTER_X + eyeOffsetX, CENTER_Y - eyeOffsetY,
                   CENTER_X + eyeOffsetX - 10, CENTER_Y - eyeOffsetY + 20 - eyeBlink,
                   CENTER_X + eyeOffsetX + 10, CENTER_Y - eyeOffsetY + 20 - eyeBlink,
                   TFT_BLACK);

  // Mouth (polygon smile/frown)
  tft.fillTriangle(CENTER_X - 40, CENTER_Y + 40,
                   CENTER_X + 40, CENTER_Y + 40,
                   CENTER_X, CENTER_Y + 60 + eyeBlink,
                   TFT_BLACK);
}

void loop() {
  tft.fillScreen(TFT_BLACK);
  drawRings();
  drawFace();

  // Blink animation
  if (blinkDirection) {
    eyeBlink++;
    if (eyeBlink > 10) blinkDirection = false;
  } else {
    eyeBlink--;
    if (eyeBlink < 0) blinkDirection = true;
  }

  delay(100);
}

