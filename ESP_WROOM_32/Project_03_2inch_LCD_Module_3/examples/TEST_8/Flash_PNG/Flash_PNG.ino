#include <PNGdec.h>
#include "panda.h" // Your PNG array

#include <SPI.h>
#include <TFT_eSPI.h>  // TFT library

#define MAX_IMAGE_WIDTH 240 // Max image width for line buffer

TFT_eSPI tft = TFT_eSPI();
PNG png; // PNG decoder instance

int16_t xpos = 0;
int16_t ypos = 0;

//====================================================================================
// Setup
//====================================================================================
void setup() {
  Serial.begin(115200);
  Serial.println("\n\nUsing the PNGdec library");

  tft.init();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);

  Serial.println("Initialisation done.");
}

//====================================================================================
// Loop
//====================================================================================
void loop() {
  int16_t rc = png.openFLASH((uint8_t *)panda, sizeof(panda), pngDraw);
  if (rc == PNG_SUCCESS) {
    Serial.println("Successfully opened PNG file");
    Serial.printf("Image specs: (%d x %d), %d bpp, pixel type: %d\n",
                  png.getWidth(), png.getHeight(), png.getBpp(), png.getPixelType());

    tft.startWrite();
    uint32_t dt = millis();
    rc = png.decode(NULL, 0); // Decode entire PNG
    Serial.print(millis() - dt); Serial.println(" ms");
    tft.endWrite();
  } else {
    Serial.printf("Failed to open PNG: %d\n", rc);
  }

  delay(3000);
  tft.fillScreen(random(0x10000));
}

//====================================================================================
// PNG draw callback
//====================================================================================
int pngDraw(PNGDRAW *pDraw) {
  uint16_t lineBuffer[MAX_IMAGE_WIDTH];
  png.getLineAsRGB565(pDraw, lineBuffer, PNG_RGB565_BIG_ENDIAN, 0xFFFF); // White default
  tft.pushImage(xpos, ypos + pDraw->y, pDraw->iWidth, 1, lineBuffer);
  return 1; // Must return int
}

