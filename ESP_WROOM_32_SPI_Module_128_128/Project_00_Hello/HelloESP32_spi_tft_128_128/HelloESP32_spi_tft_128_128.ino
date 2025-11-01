#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#define ST77XX_PINK 0xFC9F

#define TFT_CS   5
#define TFT_DC   2
#define TFT_RST  4

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("Init TFT...");

  SPI.begin(18, -1, 23);  // SCK=18, MOSI=23

  tft.initR(INITR_144GREENTAB); // for most 128x128 modules
  // Try other tabs if still blank:
  // tft.initR(INITR_BLACKTAB);
  // tft.initR(INITR_REDTAB);

  tft.setSPISpeed(8000000); // 8 MHz
  tft.fillScreen(ST77XX_BLACK);
  
  tft.setTextColor(ST77XX_PINK);
  tft.setTextSize(2);
  tft.setCursor(10, 10);
  tft.println("Helloo");

  Serial.println("TFT ready.");
}

void loop() {
  delay(1000);
}

