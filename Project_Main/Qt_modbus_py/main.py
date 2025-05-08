from pymodbus.client import ModbusSerialClient as ModbusClient
import time

# Setup Modbus client (RS-485, Serial communication)
client = ModbusClient(
    port='/dev/ttyUSB1', 
    baudrate=9600, 
    stopbits=1, 
    bytesize=8, 
    parity='N',
    timeout=1
)

# Connect to the Arduino Modbus slave (ID = 1)
# Connect to the Arduino Modbus slave (ID = 1)
if client.connect():
    print("Connected to Modbus slave.")
else:
    print("Failed to connect to Modbus slave.")


# Read holding registers (from address 0, 5 registers)
while True:
    response = client.read_holding_registers(address=0, count=5, slave=1)  # Using keyword arguments
    if not response.isError():
        # Convert registers back to characters
        message = ''.join([chr(register) for register in response.registers])
        print(f"Received: {message}")
    else:
        print(f"Error: {response}")

    time.sleep(1)

# Close connection
client.close()
