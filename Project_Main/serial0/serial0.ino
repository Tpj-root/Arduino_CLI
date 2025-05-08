void setup() {
  Serial.begin(115200);  // Start serial at 115200 baud
  Serial.println("Ready");  // Optional welcome message
}

void loop() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');  // Read until newline
    command.trim();  // Remove whitespace

    Serial.print("Received: ");
    Serial.println(command);

    if (command == "G0 X10 Y10") {
      Serial.println("Moving to X10 Y10...");
    } else if (command == "$$") {
      Serial.println("Settings:\n$0=10\n$1=25");
    } else if (command == "whoru") {
      Serial.println("Serial No: ARDUINO-UNO-123456");  // Simulated serial number
    } else if (command == "version") {
      Serial.println("0.1");  // Simulated serial number
    } else if (command.equalsIgnoreCase("author")) {
      Serial.println("shadow");  // Simulated serial number
    } else {
      Serial.println("Unknown command");
    }
  }
}

