#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI(); // Invoke custom library

#define TEXT_HEIGHT 8       // Height of text to be printed and scrolled
#define BOT_FIXED_AREA 0    // Number of lines in bottom fixed area
#define TOP_FIXED_AREA 0    // Number of lines in top fixed area

uint16_t yStart = TOP_FIXED_AREA;
uint16_t yArea = 320 - TOP_FIXED_AREA - BOT_FIXED_AREA;
uint16_t yDraw = 320 - BOT_FIXED_AREA - TEXT_HEIGHT;
byte pos[42];
uint16_t xPos = 0;

void setup() {
  Serial.begin(115200);
  randomSeed(analogRead(0));

  tft.init();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);
  tft.setTextFont(1); // GLCD font
  setupScrollArea(TOP_FIXED_AREA, BOT_FIXED_AREA);
}

void loop() {
  // Fill screen with random streaks of characters
  for (int j = 0; j < 600; j += TEXT_HEIGHT) {
    for (int i = 0; i < 40; i++) {
      if (pos[i] > 20) pos[i] -= 3; // Rapid fade initially
      if (pos[i] > 0) pos[i] -= 1;  // Slow fade later
      if ((random(20) == 1) && (j < 400)) pos[i] = 63; // New char ~1/20

      // Green brightness effect
      uint16_t color = tft.color565(0, pos[i] << 2, 0);
      if (pos[i] == 63) color = TFT_WHITE; // Bright character
      tft.setTextColor(color, TFT_BLACK);

      xPos += tft.drawChar(random(32, 128), xPos, yDraw, 1); // Draw char
    }
    yDraw = scroll_slow(TEXT_HEIGHT, 14); // Scroll, 14ms per pixel
    xPos = 0;
  }

  // Scroll smoothly forever
  while (1) {
    yield();
    yDraw = scroll_slow(320, 5); // Scroll 320 lines, 5ms per line
  }
}

void setupScrollArea(uint16_t topFixed, uint16_t bottomFixed) {
  // ST7789 does not have setScroll(), reset scroll manually
  yStart = 0;
  tft.writecommand(0x37); // VSCSAD: Vertical Scroll Start Address
  tft.writedata(0);
  tft.writedata(0);
}

int scroll_slow(int lines, int wait) {
  int yTemp = yStart;
  for (int i = 0; i < lines; i++) {
    yStart++;
    if (yStart >= 320 - BOT_FIXED_AREA) yStart = TOP_FIXED_AREA;

    // Set vertical scroll start address
    tft.writecommand(0x37); // VSCSAD
    tft.writedata(yStart >> 8);
    tft.writedata(yStart & 0xFF);

    delay(wait);
  }
  return yTemp;
}

