import serial
import time

# Connect to Arduino (adjust the port if needed)
ser = serial.Serial('/dev/ttyUSB0', 115200, timeout=1)
time.sleep(2)  # Wait for Arduino to initialize

# Send a command (e.g., move command for GRBL)
ser.write(b'G0 X10 Y10\n')  # Move to X10 Y10
time.sleep(0.1)

# Read response
response = ser.readline().decode().strip()
print("Response:", response)

# Close connection
ser.close()
