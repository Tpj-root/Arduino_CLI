
LIB


That error happens because **RTClib** is not installed for Arduino-CLI yet.

---

### ✅ Install it

```bash
/home/cnc/Desktop/MY_GIT/Arduino_CLI/bin/arduino-cli lib install "RTClib"
```

Or with version:

```bash
/home/cnc/Desktop/MY_GIT/Arduino_CLI/bin/arduino-cli lib install "RTClib@1.14.1"
```

---

### 🔹 Verify installation

```bash
/home/cnc/Desktop/MY_GIT/Arduino_CLI/bin/arduino-cli lib list
```

You should see **RTClib** in the list.

---

After installing, run:

```bash
make build
```

Your TinyRTC sketch should compile successfully.

Do you want me to **update your Makefile to auto-install RTClib** like you did for LiquidCrystal I2C?






🔌 Wiring

RTC

VCC → 3.3V or 5V (ESP32 is 3.3V logic but I2C is 5V tolerant)

GND → GND

SDA → GPIO21 (default ESP32 SDA)

SCL → GPIO22 (default ESP32 SCL)

