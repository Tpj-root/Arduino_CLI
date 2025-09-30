#include <TFT_eSPI.h>
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI(); // TFT instance

// Colors
uint16_t colorModes[] = {TFT_RED, TFT_GREEN, TFT_WHITE, TFT_BLUE, TFT_YELLOW};
int currentColor = 0;

// Face position and size
int faceX = 120;
int faceY = 160;
int faceRadius = 100;

// Animation parameters
int eyeBlink = 0;
bool blinkDirection = true;

void setup() {
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
}

void drawFace() {
  // Face
  tft.fillCircle(faceX, faceY, faceRadius, colorModes[currentColor]);

  // Eyes (polygon style)
  int eyeSize = 20;
  int eyeOffsetX = 40;
  int eyeOffsetY = 30;

  // Left eye
  tft.fillTriangle(faceX - eyeOffsetX, faceY - eyeOffsetY,
                   faceX - eyeOffsetX - 10, faceY - eyeOffsetY + 20 - eyeBlink,
                   faceX - eyeOffsetX + 10, faceY - eyeOffsetY + 20 - eyeBlink,
                   TFT_BLACK);

  // Right eye
  tft.fillTriangle(faceX + eyeOffsetX, faceY - eyeOffsetY,
                   faceX + eyeOffsetX - 10, faceY - eyeOffsetY + 20 - eyeBlink,
                   faceX + eyeOffsetX + 10, faceY - eyeOffsetY + 20 - eyeBlink,
                   TFT_BLACK);

  // Mouth (polygon smile/frown)
  tft.fillTriangle(faceX - 40, faceY + 40,
                   faceX + 40, faceY + 40,
                   faceX, faceY + 60 + eyeBlink,
                   TFT_BLACK);
}

void loop() {
  tft.fillScreen(TFT_BLACK); // Clear screen
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

  // Change color every 20 loops
  static int loopCount = 0;
  loopCount++;
  if (loopCount > 20) {
    currentColor = (currentColor + 1) % (sizeof(colorModes)/2);
    loopCount = 0;
  }
}

