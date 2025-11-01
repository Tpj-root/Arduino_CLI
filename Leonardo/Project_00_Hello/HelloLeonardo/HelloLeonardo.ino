#include "Keyboard.h"

void setup() {
  Keyboard.begin();
  delay(1000); // wait for connection

  for (int i = 0; i < 10; i++) {
    Keyboard.print("Hello, world!");
    Keyboard.write(KEY_RETURN); // press Enter
    delay(500); // small delay between prints
  }

  Keyboard.end();
}

void loop() {
}

