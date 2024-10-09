// Pin where the LED is connected
int ledPin = 13;

void setup() {
  // Set the LED pin as output
  pinMode(ledPin, OUTPUT);
  
  // Initialize serial communication at 9600 baud
  Serial.begin(9600);
}

void loop() {
  // Turn the LED on
  digitalWrite(ledPin, HIGH);
  // Print a message to the Serial Monitor
  Serial.println("LED is ON");
  delay(1000); // Wait for 1 second

  // Turn the LED off
  digitalWrite(ledPin, LOW);
  // Print a message to the Serial Monitor
  Serial.println("LED is OFF");
  delay(1000); // Wait for 1 second
}

