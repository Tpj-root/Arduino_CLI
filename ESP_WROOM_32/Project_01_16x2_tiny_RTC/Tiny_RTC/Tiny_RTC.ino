#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  if (!rtc.begin()) {
    Serial.println("RTC not found!");
    while (1);
  }

  // Example: set RTC from Unix timestamp
  uint32_t unixTime = 1757754000; // seconds since 1970-01-01 00:00:00
  rtc.adjust(DateTime(unixTime));
}

void loop() {
  DateTime now = rtc.now();
  
  // Convert back to Unix time
  uint32_t unixNow = now.unixtime();
  
  Serial.print("Unix: "); Serial.println(unixNow);
  Serial.print("Human: "); 
  Serial.print(now.year()); Serial.print("-");
  Serial.print(now.month()); Serial.print("-");
  Serial.print(now.day()); Serial.print(" ");
  Serial.print(now.hour()); Serial.print(":");
  Serial.print(now.minute()); Serial.print(":");
  Serial.println(now.second());

  delay(1000);
}
