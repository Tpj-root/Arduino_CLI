#include <SPI.h>
#include <Ethernet.h>

// MAC Address for the W5500 module
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// IP address for the ESP32 (make sure it's in the same subnet as your network)
IPAddress ip(192, 168, 1, 177);

// Create an instance of the Ethernet server on port 80 (HTTP)
EthernetServer server(80);

void setup() {
    // Initialize Serial Monitor
    Serial.begin(115200);
    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB port only
    }
    Serial.println("W5500 Ethernet Test");

    // Start the Ethernet connection
    if (Ethernet.begin(mac) == 0) {
        Serial.println("Failed to configure Ethernet using DHCP");
        // Configuring with a static IP
        Ethernet.begin(mac, ip);
    }

    // Start the server
    server.begin();
    Serial.print("Server is at http://");
    Serial.println(Ethernet.localIP());
}

void loop() {
    // Check for incoming clients
    EthernetClient client = server.available();
    if (client) {
        Serial.println("New client connected!");
        String currentLine = "";
        
        // Loop while the client's connected
        while (client.connected()) {
            // If there's bytes to read
            if (client.available()) {
                char c = client.read();
                Serial.write(c); // Echo back to Serial Monitor
                // Add to current line
                currentLine += c;

                // If the line is complete
                if (c == '\n') {
                    // Send a simple response
                    client.println("HTTP/1.1 200 OK");
                    client.println("Content-Type: text/html");
                    client.println("Connection: close");
                    client.println();
                    client.println("<!DOCTYPE HTML>");
                    client.println("<html><body>");
                    client.println("<h1>Hello from ESP32 with W5500!</h1>");
                    client.println("</body></html>");
                    break;
                }
            }
        }
        // Give the client time to receive the data
        delay(1);
        // Close the connection
        client.stop();
        Serial.println("Client disconnected.");
    }
}

