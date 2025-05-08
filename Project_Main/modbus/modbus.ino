#include <ModbusRTUSlave.h>

ModbusRTUSlave modbus(Serial);  // Use USB serial
uint16_t holdingRegs[10];       // 10 holding registers for string data

void setup() {
  Serial.begin(9600);           // Match master baud rate
  modbus.begin(1, 9600);        // Slave ID = 1, baud = 9600
  modbus.configureHoldingRegisters(holdingRegs, 10);

  // Encode "hello" into holding registers
  holdingRegs[0] = 'h';   // 'h' as 16-bit value
  holdingRegs[1] = 'e';   // 'e' as 16-bit value
  holdingRegs[2] = 'l';   // 'l' as 16-bit value
  holdingRegs[3] = 'l';   // 'l' as 16-bit value
  holdingRegs[4] = 'o';   // 'o' as 16-bit value
}

void loop() {
  modbus.poll();                // Handle Modbus requests

  // Print the string from the holding registers
  Serial.print("Received: ");
  for (int i = 0; i < 5; i++) {
    Serial.print((char)holdingRegs[i]);  // Convert the register values back to characters
  }
  Serial.println();
}
