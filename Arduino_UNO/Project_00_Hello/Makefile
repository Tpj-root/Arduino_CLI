# Makefile for Arduino Uno (HelloUno)
# Usage:
#   make        -> setup Arduino cores (installs arduino-cli if missing)
#   make build  -> compile sketch
#   make upload -> flash using arduino-cli
#   make help   -> show this help message

# Paths
TOOLS_DIR=$(CURDIR)/tools
ARDUINO=$(TOOLS_DIR)/arduino-cli
DEB_URL=https://github.com/arduino/arduino-cli/releases/download/v1.3.1/arduino-cli_1.3.1-1_amd64.deb
DEB_FILE=$(TOOLS_DIR)/arduino-cli.deb

# Project
SKETCH=HelloUno
FQBN=arduino:avr:uno
BAUD=115200
BUILD_DIR=./build

# Auto-detect port
PORT := $(shell arduino-cli board list | grep "Arduino Uno" | awk '{print $$1}')
ifeq ($(PORT),)
PORT := $(shell ls /dev/ttyACM* 2>/dev/null | head -n 1)
endif
ifeq ($(PORT),)
PORT := $(shell ls /dev/ttyUSB* 2>/dev/null | head -n 1)
endif

# Ensure arduino-cli is available
$(ARDUINO):
	@echo ">>> arduino-cli not found, downloading..."
	mkdir -p $(TOOLS_DIR)
	cd $(TOOLS_DIR) && wget -q $(DEB_URL) -O arduino-cli.deb
	cd $(TOOLS_DIR) && ar x arduino-cli.deb
	cd $(TOOLS_DIR) && tar -xf data.tar.xz
	ln -sf $(TOOLS_DIR)/usr/bin/arduino-cli $(ARDUINO)
	@echo ">>> arduino-cli installed at $(ARDUINO)"

all: $(ARDUINO)
	$(ARDUINO) core update-index
	$(ARDUINO) core install arduino:avr

build: $(ARDUINO)
	$(ARDUINO) compile --fqbn $(FQBN) $(SKETCH) --output-dir $(BUILD_DIR)

upload: build
ifeq ($(PORT),)
	@echo ">>> No Arduino Uno detected! Please check your USB connection."
else
	@echo ">>> Uploading to $(PORT)..."
	$(ARDUINO) upload -p $(PORT) --fqbn $(FQBN) $(SKETCH)
endif

serial_monitor:
ifeq ($(PORT),)
	@echo ">>> No serial port found!"
else
	screen $(PORT) $(BAUD)
endif

help:
	@echo "Arduino Uno Makefile usage:"
	@echo "  make        -> setup Arduino core (installs arduino-cli if missing)"
	@echo "  make build  -> compile sketch"
	@echo "  make upload -> auto-detect port and upload to Arduino Uno"
	@echo "  make serial_monitor -> open serial monitor (auto-detect port)"
	@echo "  make help   -> show this help message"

