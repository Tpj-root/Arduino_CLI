# Makefile for ESP32 (HelloESP32)
# Usage:
#   make            -> setup Arduino cores (installs arduino-cli if missing)
#   make build      -> compile sketch
#   make upload     -> flash with esptool.py
#   make free_setup -> manually reinstall ESP32 core
#   make help       -> show this help message
#   make build VERBOSE=1 -> enable verbose + warnings

# Paths
TOOLS_DIR=$(CURDIR)/tools
ARDUINO=$(TOOLS_DIR)/arduino-cli
DEB_URL=https://github.com/arduino/arduino-cli/releases/download/v1.3.1/arduino-cli_1.3.1-1_amd64.deb
DEB_FILE=$(TOOLS_DIR)/arduino-cli.deb

# Project
SKETCH=HelloESP32
FQBN=esp32:esp32:esp32
PORT=/dev/ttyUSB0
BAUD=115200
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
	$(ARDUINO) core update-index --additional-urls https://espressif.github.io/arduino-esp32/package_esp32_index.json
	$(ARDUINO) core install esp32:esp32 --additional-urls https://espressif.github.io/arduino-esp32/package_esp32_index.json
	
# make build VERBOSE=1
build: $(ARDUINO)
	$(ARDUINO) compile --fqbn $(FQBN) $(SKETCH) --output-dir $(BUILD_DIR) $(BUILD_FLAGS)

free_setup:
	$(ARDUINO) core update-index --additional-urls https://espressif.github.io/arduino-esp32/package_esp32_index.json
	$(ARDUINO) core install esp32:esp32 --additional-urls https://espressif.github.io/arduino-esp32/package_esp32_index.json

upload: build
	bash -c "source ~/miniconda3/bin/activate && esptool.py --chip esp32 --port $(PORT) --baud $(BAUD) write_flash \
	  0x1000 $(BUILD_DIR)/$(SKETCH).ino.bootloader.bin \
	  0x8000 $(BUILD_DIR)/$(SKETCH).ino.partitions.bin \
	  0x10000 $(BUILD_DIR)/$(SKETCH).ino.bin"

serial_monitor:
	bash -c "source ~/miniconda3/bin/activate && python serial_monitor.py"

help:
	@echo "ESP32 Makefile usage:"
	@echo "  make            -> setup Arduino cores (installs arduino-cli if missing)"
	@echo "  make build      -> compile sketch"
	@echo "  make build VERBOSE=1 -> compile with verbose logs and warnings"
	@echo "  make upload     -> flash to ESP32 using esptool.py"
	@echo "  make serial_monitor -> open serial monitor for ESP32"
	@echo "  make free_setup -> reinstall ESP32 core manually"
	@echo "  make help       -> show this help message"

