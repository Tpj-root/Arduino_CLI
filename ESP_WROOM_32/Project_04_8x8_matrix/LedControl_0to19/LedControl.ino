#include <LedControl.h>

#define DIN 23
#define CLK 18
#define CS 5
#define NUM_DEVICES 20

LedControl lc(DIN, CLK, CS, NUM_DEVICES);

// Simple number patterns 0–9
byte digits[10][8] = {
  {B01111100,B10000010,B10000110,B10001010,B10010010,B10100010,B11000010,B01111100}, //0
  {B00010000,B00110000,B01010000,B00010000,B00010000,B00010000,B00010000,B01111110}, //1
  {B01111100,B10000010,B00000010,B00001100,B00010000,B00100000,B01000000,B11111110}, //2
  {B11111100,B00000010,B00000100,B00111000,B00000100,B00000010,B00000010,B11111100}, //3
  {B00001100,B00010100,B00100100,B01000100,B11111110,B00000100,B00000100,B00000100}, //4
  {B11111110,B10000000,B11111100,B00000010,B00000010,B00000010,B10000010,B01111100}, //5
  {B00111100,B01000000,B10000000,B11111100,B10000010,B10000010,B01000010,B00111100}, //6
  {B11111110,B00000010,B00000100,B00001000,B00010000,B00100000,B01000000,B10000000}, //7
  {B01111100,B10000010,B10000010,B01111100,B10000010,B10000010,B10000010,B01111100}, //8
  {B01111100,B10000010,B10000010,B01111110,B00000010,B00000010,B00000100,B01111000}  //9
};

// Flip bits for correct orientation
byte reverseBits(byte b) {
  b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
  b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
  b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
  return b;
}

void drawNumber(int dev, int num) {
  int d = num % 10;
  for (int row = 0; row < 8; row++)
    lc.setRow(dev, 7 - row, reverseBits(digits[d][row]));
}

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < NUM_DEVICES; i++) {
    lc.shutdown(i, false);
    lc.setIntensity(i, 8);
    lc.clearDisplay(i);
  }

  Serial.println("Testing 0–19");
  for (int i = 0; i < NUM_DEVICES; i++) {
    Serial.printf("Displaying %d\n", i);
    lc.clearDisplay(i);
    drawNumber(i, i);
    delay(800);
    lc.clearDisplay(i);
  }

  Serial.println("Done!");
}

void loop() {}

