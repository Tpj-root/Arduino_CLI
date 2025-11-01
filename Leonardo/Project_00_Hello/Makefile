# Makefile for Arduino Leonardo (HelloLeonardo)
# Usage:
#   make                -> setup Arduino cores (installs arduino-cli if missing)
#   make build          -> compile sketch
#   make upload         -> flash to Leonardo
#   make free_setup     -> manually reinstall AVR core
#   make help           -> show help
#   make build VERBOSE=1 -> enable verbose + warnings

# Paths
TOOLS_DIR=$(CURDIR)/tools
ARDUINO=$(TOOLS_DIR)/arduino-cli
DEB_URL=https://github.com/arduino/arduino-cli/releases/download/v1.3.1/arduino-cli_1.3.1-1_amd64.deb
DEB_FILE=$(TOOLS_DIR)/arduino-cli.deb

# Project
SKETCH=HelloLeonardo
FQBN=arduino:avr:leonardo
PORT=/dev/ttyACM0
BAUD=57600
BUILD_DIR=./build

# Verbose / Warnings toggle
ifeq ($(VERBOSE),1)
  BUILD_FLAGS=--verbose --warnings all
else
  BUILD_FLAGS=
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

# make build VERBOSE=1
build: $(ARDUINO)
#	$(ARDUINO) compile --fqbn $(FQBN) $(SKETCH) --output-dir $(BUILD_DIR) $(BUILD_FLAGS)
# add --libraries path in Makefile
	$(ARDUINO) compile --fqbn $(FQBN) $(SKETCH) --output-dir $(BUILD_DIR) --libraries ./libraries $(BUILD_FLAGS)


free_setup:
	$(ARDUINO) core update-index
	$(ARDUINO) core install arduino:avr

upload: build
	$(ARDUINO) upload -p $(PORT) --fqbn $(FQBN) $(SKETCH)

serial_monitor:
	screen $(PORT) $(BAUD)

help:
	@echo "Arduino Leonardo Makefile usage:"
	@echo "  make                -> setup Arduino cores (installs arduino-cli if missing)"
	@echo "  make build          -> compile sketch"
	@echo "  make build VERBOSE=1 -> compile with verbose logs and warnings"
	@echo "  make upload         -> upload sketch to Leonardo"
	@echo "  make serial_monitor -> open serial monitor (using screen)"
	@echo "  make free_setup     -> reinstall AVR core manually"
	@echo "  make help           -> show this help message"

