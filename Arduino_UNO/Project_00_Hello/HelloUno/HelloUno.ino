void setup() {
  Serial.begin(115200);
  Serial.println("Hello, Arduino!");
}

void loop() {
  // keep printing every second
  Serial.println("Hello, sab!");
  delay(1000);
}
