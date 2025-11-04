# Makefile for ESP32 (HelloESP32)
# Usage:
#   make build   -> compile sketch
#   make upload  -> flash with Arduino CLI
#   make help    -> show help

TOOLS_DIR=$(CURDIR)/tools
ARDUINO=$(TOOLS_DIR)/arduino-cli
DEB_URL=https://github.com/arduino/arduino-cli/releases/download/v1.3.1/arduino-cli_1.3.1-1_amd64.deb
SKETCH=HelloESP32_spi_tft_128_128
FQBN=esp32:esp32:esp32
PORT=/dev/ttyUSB0
BAUD=115200
BUILD_DIR=./build

$(ARDUINO):
	@echo ">>> Installing arduino-cli..."
	mkdir -p $(TOOLS_DIR)
	cd $(TOOLS_DIR) && wget -q $(DEB_URL) -O arduino-cli.deb
	cd $(TOOLS_DIR) && ar x arduino-cli.deb
	cd $(TOOLS_DIR) && tar -xf data.tar.xz
	ln -sf $(TOOLS_DIR)/usr/bin/arduino-cli $(ARDUINO)
	@echo ">>> arduino-cli installed."

all: $(ARDUINO)
	$(ARDUINO) core update-index --additional-urls https://espressif.github.io/arduino-esp32/package_esp32_index.json
	$(ARDUINO) core install esp32:esp32 --additional-urls https://espressif.github.io/arduino-esp32/package_esp32_index.json
	$(ARDUINO) lib install "Adafruit GFX Library"
	$(ARDUINO) lib install "Adafruit ST7735 and ST7789 Library"

build: $(ARDUINO)
	$(ARDUINO) compile --fqbn $(FQBN) $(SKETCH) --output-dir $(BUILD_DIR) --verbose --warnings all

upload:
	$(ARDUINO) upload -p $(PORT) --fqbn $(FQBN) $(SKETCH)

serial_monitor:
	screen $(PORT) $(BAUD)

help:
	@echo "ESP32 Makefile usage:"
	@echo "  make all      -> install core + libs"
	@echo "  make build    -> compile"
	@echo "  make upload   -> flash"
	@echo "  make help     -> show help"

