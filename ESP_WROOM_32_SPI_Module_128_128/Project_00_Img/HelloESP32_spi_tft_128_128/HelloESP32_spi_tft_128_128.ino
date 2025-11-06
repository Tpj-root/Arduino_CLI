#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include "myImage.h"

#define TFT_CS   5
#define TFT_DC   2
#define TFT_RST  4

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  tft.initR(INITR_144GREENTAB);  // 128x128
  tft.setRotation(0);
  tft.fillScreen(ST77XX_BLACK);
  tft.drawRGBBitmap(0, 0, myImage, 128, 128);
}

void loop() {}

