#!/bin/bash

# Serial port
PORT=/dev/ttyUSB0
BAUD=115200

# Get current Unix timestamp
UNIX_TIME=$(date +%s)
echo "Current Unix time: $UNIX_TIME"

# Send Unix timestamp to ESP32
stty -F $PORT $BAUD raw -echo
echo -n "$UNIX_TIME" > $PORT
stty -F $PORT sane

echo "Unix time sent successfully!"
