
### ESP_WROOM_32


Py_env


```
pip install pyserial
pip install ttkthemes
sudo apt install python3-tk
pip install pyserial ttkthemes
pip install esptool
```








PinOut

```
https://lastminuteengineers.com/esp32-pinout-reference/
```





# minimal Arduino-CLI + ESP32 Hello World on your Debian system.

---

### 1. Install ESP32 core (if not done yet)

```bash
arduino-cli core update-index
arduino-cli core update-index --additional-urls https://espressif.github.io/arduino-esp32/package_esp32_index.json
arduino-cli core install esp32:esp32 --additional-urls https://espressif.github.io/arduino-esp32/package_esp32_index.json

arduino-cli core install esp32:esp32
```

---


### 2. Create a new sketch

```bash
arduino-cli sketch new HelloESP32
cd HelloESP32
```

---

### 3. Replace `HelloESP32.ino` with this code:

```cpp
void setup() {
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
}

void loop() {
  // keep printing every second
  Serial.println("Hello, world!");
  delay(1000);
}
```

---

### 4. Compile for ESP32-WROOM-32

```bash
arduino-cli compile --fqbn esp32:esp32:esp32 HelloESP32
```


To keep the compiled files (like .elf, .bin, .hex) in a location you choose, use the --output-dir option:


```
arduino-cli compile --fqbn esp32:esp32:esp32 HelloESP32 --output-dir ./build


```

Now you’ll find files in ./build/, e.g.:

HelloESP32.ino.bin → the binary you can flash

HelloESP32.ino.elf → ELF debug file

HelloESP32.ino.map → memory map





---

### 5. Upload to board

First, find your port:

```bash
arduino-cli board list
```

(It should show something like `/dev/ttyUSB0` with CP210x driver.)

To upload a specific .bin file manually with esptool.py::

```bash
pip install esptool

esptool.py --chip esp32 --port /dev/ttyUSB0 erase_flash

esptool.py --chip esp32 --port /dev/ttyUSB0 --baud 460800 write_flash -z 0x1000 HelloESP32.ino.bin

```





Try_this


flash all 3 images (bootloader, partitions, app). They are generated during compile. You should find them in your ./build/ folder:

bootloader.bin

partitions.bin

HelloESP32.ino.bin

Then upload with esptool:


```
esptool.py --chip esp32 --port /dev/ttyUSB0 --baud 460800 write_flash \
  0x1000 bootloader.bin \
  0x8000 partitions.bin \
  0x10000 HelloESP32.ino.bin

```


HelloESP32.ino.bootloader.bin → bootloader (goes at 0x1000)

HelloESP32.ino.partitions.bin → partition table (goes at 0x8000)

HelloESP32.ino.bin → your app (goes at 0x10000)

HelloESP32.ino.merged.bin → one big image with everything (bootloader + partitions + app) combined, can be flashed at 0x0


---


Perfect 👍 you have everything you need. Let me explain those files:

* **HelloESP32.ino.bootloader.bin** → bootloader (goes at `0x1000`)
* **HelloESP32.ino.partitions.bin** → partition table (goes at `0x8000`)
* **HelloESP32.ino.bin** → your app (goes at `0x10000`)
* **HelloESP32.ino.merged.bin** → one big image with everything (bootloader + partitions + app) combined, can be flashed at `0x0`

---

### Two ways to flash

**Option 1: Flash individual parts**

```bash
esptool.py --chip esp32 --port /dev/ttyUSB0 --baud 460800 write_flash \
  0x1000 HelloESP32.ino.bootloader.bin \
  0x8000 HelloESP32.ino.partitions.bin \
  0x10000 HelloESP32.ino.bin
```

**Option 2: Use merged image (simpler)**

```bash
esptool.py --chip esp32 --port /dev/ttyUSB0 --baud 460800 write_flash 0x0 HelloESP32.ino.merged.bin
```

---

👉 I’d recommend **Option 2** (merged). After flashing, press **EN/RESET** on your ESP32 and then run:

```bash
arduino-cli monitor -p /dev/ttyUSB0 --config baudrate=115200
```

You should finally see:

```
Hello, ESP32!
Hello, world!
Hello, world!
...
```

Do you want me to also give you a **Makefile / script** so you can compile + flash + monitor in one command?




