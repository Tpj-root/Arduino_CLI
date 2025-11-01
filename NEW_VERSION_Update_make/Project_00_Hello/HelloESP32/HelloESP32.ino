void setup() {
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
}

void loop() {
  // keep printing every second
  Serial.println("Hello, sab!");
  delay(1000);
}
