

# default dir
/home/cnc/.arduino15



Example Workflow

Initialize the CLI Configuration:

arduino-cli config init


Install the Required Core:

arduino-cli core install arduino:avr

Create a New Sketch:

arduino-cli sketch new led


Compile the Sketch:

arduino-cli compile --fqbn arduino:avr:uno --export-binaries led/led.ino


Upload the Sketch to the Board:

arduino-cli upload --fqbn arduino:avr:uno --port /dev/ttyUSB0 --verify ./led/


Open Serial Monitor:

arduino-cli monitor -p /dev/ttyUSB0

# Not work
# arduino-cli monitor -p /dev/ttyUSB0 --baud 9600 --data-bits 8 --parity none --stop-bits 1 --rts on --dtr on


arduino-cli monitor -p /dev/ttyUSB0 --config 9600

Monitor port settings:
  baudrate=9600
  bits=8
  dtr=on
  parity=none
  rts=on
  stop_bits=1






