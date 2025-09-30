
https://randomnerdtutorials.com/esp32-esp8266-i2c-lcd-arduino-ide/

Ah, that error is because the **LiquidCrystal\_I2C library** isn’t installed for Arduino-CLI yet.

---

### ✅ Install it via Arduino-CLI




Then rebuild:

```bash
make build
```


arduino-cli lib install "TFT_eSPI"


Already installed TFT_eSPI@2.5.43
cnc@debian:~/Arduino$ 




---

💡 You can also check installed libraries:

```bash
/home/cnc/Desktop/MY_GIT/Arduino_CLI/bin/arduino-cli lib list
```







https://github.com/Bodmer/TFT_eSPI/issues/3554

🔌 Wiring

TFT_eSPI/User_Setup.h



```
#define TFT_MISO -1        // Not used
#define TFT_MOSI 23        // SPI MOSI
#define TFT_SCLK 18        // SPI Clock
#define TFT_CS   5         // Chip Select
#define TFT_DC   27        // Data/Command
#define TFT_RST  26        // Reset
#define TFT_BL   32        // Backlight (optional, connect to GPIO)


```

