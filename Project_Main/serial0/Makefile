# Makefile for Arduino CLI

# Define the path for arduino-cli
ARDUINO_CLI = /home/cnc/Desktop/MY_GIT/Arduino_CLI/bin/arduino-cli

# Check if the file exists, raise an error if not
ifeq ($(shell test -e $(ARDUINO_CLI) && echo -n yes),yes)
    # File exists
else
    $(error arduino-cli not found at $(ARDUINO_CLI). Please ensure it is installed correctly.)
endif

FQBN = arduino:avr:uno
SKETCH = serial0.ino
BUILD_DIR = build
PORT = /dev/ttyUSB0

all:  compile

compile:
	$(ARDUINO_CLI) compile --fqbn $(FQBN) --export-binaries --build-path $(BUILD_DIR) $(SKETCH) --verbose

upload:
	$(ARDUINO_CLI) upload --fqbn $(FQBN) --port $(PORT) --verify --verbose ./ --input-dir ./build
                   

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all compile clean
