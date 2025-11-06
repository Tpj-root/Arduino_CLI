Correct — ✅ the **Arduino Uno (ATmega328P + ATmega16U2)** is **not a native HID** device.

Here’s why:

* The **ATmega328P** (main MCU) only handles your sketch; it doesn’t have USB capability.
* The **ATmega16U2** acts as a **USB-to-Serial bridge** — it presents itself as a **CDC (serial) device**, not as HID (keyboard/mouse/joystick).

### 💡 Meaning

* You can upload sketches and use `Serial` communication — but **not act as a USB keyboard/mouse**.
* It appears as `/dev/ttyACM0` because it uses the **CDC ACM** driver.

### 🧩 To make a true HID board

Use one of:

* **Arduino Leonardo / Micro / Pro Micro** (ATmega32U4)
* **Arduino Due**, **Teensy**, or **ESP32-S2 / ESP32-S3** (they have native USB support)

Those can emulate HID devices (keyboard, mouse, etc.) directly via firmware.




Bus 005 Device 002: ID 2341:0043 Arduino SA Uno R3 (CDC ACM)
Bus 005 Device 003: ID 2341:8036 Arduino SA Leonardo (CDC ACM, HID)




Hello, world!
Hello, world!
Hello, world!
Hello, world!
Hello, world!
Hello, world!
Hello, world!
Hello, world!

