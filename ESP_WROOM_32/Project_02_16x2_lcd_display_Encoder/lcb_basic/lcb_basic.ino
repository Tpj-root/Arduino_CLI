#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD setup (PCF8574 usually at 0x27, sometimes 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Rotary encoder pins
const int pinCLK = 32;  // ESP32 GPIO
const int pinDT  = 33;
const int pinSW  = 25;

int counter = 0;
int lastCLKState;
bool buttonPressed = false;

void setup() {
  // LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello World");

  // Encoder
  pinMode(pinCLK, INPUT_PULLUP);
  pinMode(pinDT, INPUT_PULLUP);
  pinMode(pinSW, INPUT_PULLUP);

  lastCLKState = digitalRead(pinCLK);

  // Serial debug
  Serial.begin(115200);
}

void loop() {
  // Rotary encoder
  int currentCLKState = digitalRead(pinCLK);

  if (currentCLKState != lastCLKState) {
    // CW if DT == CLK state, CCW if DT != CLK
    if (digitalRead(pinDT) == currentCLKState) {
      counter++;  // CW
    } else {
      counter--;  // CCW
    }

    lcd.setCursor(0, 1);
    lcd.print("Count: ");
    lcd.print(counter);
    lcd.print("    ");  // clear trailing digits

    Serial.println(counter);
  }

  lastCLKState = currentCLKState;

  // Button (reset counter)
  if (digitalRead(pinSW) == LOW && !buttonPressed) {
    counter = 0;
    lcd.setCursor(0, 1);
    lcd.print("Count: 0     ");
    buttonPressed = true;
    delay(200); // debounce
  }

  if (digitalRead(pinSW) == HIGH) {
    buttonPressed = false;
  }
}
