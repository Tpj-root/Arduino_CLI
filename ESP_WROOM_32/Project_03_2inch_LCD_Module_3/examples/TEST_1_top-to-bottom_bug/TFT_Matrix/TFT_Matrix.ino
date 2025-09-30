#include <TFT_eSPI.h>
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();

#define TEXT_HEIGHT 8
#define BOT_FIXED_AREA 0
#define TOP_FIXED_AREA 0

uint16_t yStart = TOP_FIXED_AREA;
uint16_t yDraw = TOP_FIXED_AREA; // Start drawing from top
byte pos[42];
uint16_t xPos = 0;

void setup() {
  Serial.begin(115200);
  randomSeed(analogRead(0));

  tft.init();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);
  tft.setTextFont(1);
}

void loop() {
  // Fill screen from top to bottom
  for (int j = 0; j < 600; j += TEXT_HEIGHT) {
    for (int i = 0; i < 40; i++) {
      if (pos[i] > 20) pos[i] -= 3;
      if (pos[i] > 0) pos[i] -= 1;
      if ((random(20) == 1) && (j < 400)) pos[i] = 63;

      uint16_t color = tft.color565(0, pos[i] << 2, 0);
      if (pos[i] == 63) color = TFT_WHITE;
      tft.setTextColor(color, TFT_BLACK);

      xPos += tft.drawChar(random(32, 128), xPos, yDraw, 1);
    }

    // Move drawing cursor downward
    yDraw += TEXT_HEIGHT;
    if (yDraw >= tft.height() - BOT_FIXED_AREA) {
      yDraw = TOP_FIXED_AREA; // Reset to top
    }
    xPos = 0;
  }
}

