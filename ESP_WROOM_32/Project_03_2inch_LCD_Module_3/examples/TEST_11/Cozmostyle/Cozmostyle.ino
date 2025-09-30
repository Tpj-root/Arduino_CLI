#include <TFT_eSPI.h>
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();  // Initialize your display

// Face coordinates
#define FACE_X 0
#define FACE_Y 0
#define FACE_W 128
#define FACE_H 64

// Eye positions
#define EYE_RADIUS 8
#define LEFT_EYE_X 40
#define RIGHT_EYE_X 88
#define EYE_Y 30

// Mouth positions
#define MOUTH_W 40
#define MOUTH_H 8
#define MOUTH_X 44
#define MOUTH_Y 50

// Animation state
bool eyeOpen = true;
int pupilOffset = 0;
int pupilDir = 1;

void setup() {
  Serial.begin(115200);
  tft.init();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);
}

void loop() {
  drawFace();
  eyeAnimation();
  mouthAnimation();
  delay(100);  // Control animation speed
}

// Draw static face (head outline optional)
void drawFace() {
  // Clear face area
  tft.fillRect(FACE_X, FACE_Y, FACE_W, FACE_H, TFT_BLACK);

  // Draw eyes
  if (eyeOpen) {
    tft.fillCircle(LEFT_EYE_X, EYE_Y, EYE_RADIUS, TFT_WHITE);
    tft.fillCircle(RIGHT_EYE_X, EYE_Y, EYE_RADIUS, TFT_WHITE);

    // Pupils
    tft.fillCircle(LEFT_EYE_X + pupilOffset, EYE_Y, 4, TFT_BLACK);
    tft.fillCircle(RIGHT_EYE_X + pupilOffset, EYE_Y, 4, TFT_BLACK);
  } else {
    // Draw closed eyes
    tft.drawLine(LEFT_EYE_X - EYE_RADIUS, EYE_Y, LEFT_EYE_X + EYE_RADIUS, EYE_Y, TFT_WHITE);
    tft.drawLine(RIGHT_EYE_X - EYE_RADIUS, EYE_Y, RIGHT_EYE_X + EYE_RADIUS, EYE_Y, TFT_WHITE);
  }
}

// Simple eye animation
void eyeAnimation() {
  // Move pupils left/right
  pupilOffset += pupilDir;
  if (pupilOffset > 4 || pupilOffset < -4) pupilDir = -pupilDir;

  // Blink every few seconds
  static int blinkCounter = 0;
  blinkCounter++;
  if (blinkCounter > 20) { // adjust for blink speed
    eyeOpen = !eyeOpen;
    blinkCounter = 0;
  }
}

// Mouth animation (simple reactions)
void mouthAnimation() {
  // Example: mouth opens/closes every cycle
  static bool mouthOpen = false;
  mouthOpen = !mouthOpen;

  if (mouthOpen) {
    tft.fillRect(MOUTH_X, MOUTH_Y, MOUTH_W, MOUTH_H, TFT_WHITE);
  } else {
    tft.fillRect(MOUTH_X, MOUTH_Y, MOUTH_W, MOUTH_H, TFT_BLACK);
  }
}

