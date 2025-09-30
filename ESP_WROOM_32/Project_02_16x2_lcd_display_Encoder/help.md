
https://randomnerdtutorials.com/esp32-esp8266-i2c-lcd-arduino-ide/


Ah, that error is because the **LiquidCrystal\_I2C library** isn’t installed for Arduino-CLI yet.

---

### ✅ Install it via Arduino-CLI

```bash
/home/cnc/Desktop/MY_GIT/Arduino_CLI/bin/arduino-cli lib install "LiquidCrystal I2C"
```

Or you can specify a version:

```bash
/home/cnc/Desktop/MY_GIT/Arduino_CLI/bin/arduino-cli lib install "LiquidCrystal I2C@1.1.2"
```

Then rebuild:

```bash
make build
```

---

💡 You can also check installed libraries:

```bash
/home/cnc/Desktop/MY_GIT/Arduino_CLI/bin/arduino-cli lib list
```






🔌 Wiring

LCD I2C backpack:

VCC → 3.3V or 5V (ESP32 is 3.3V logic but I2C is 5V tolerant)

GND → GND

SDA → GPIO21 (default ESP32 SDA)

SCL → GPIO22 (default ESP32 SCL)

Rotary encoder:

CLK → GPIO32

DT → GPIO33

SW → GPIO25

VCC → 3.3V

GND → GND