# Arduino_CLI

**Arduino CLI: Transforming Coders into Command Line Ninjas!**

Common Arduino Abbreviations

    FQBN - Fully Qualified Board Name
    IDE - Integrated Development Environment
    CLI - Command Line Interface
    MCU - Microcontroller Unit
    PWM - Pulse Width Modulation
    GPIO - General Purpose Input/Output
    UART - Universal Asynchronous Receiver-Transmitter
    I2C - Inter-Integrated Circuit (also known as TWI - Two Wire Interface)
    SPI - Serial Peripheral Interface
    ADC - Analog-to-Digital Converter
    DAC - Digital-to-Analog Converter
    ISP - In-System Programming
    BOM - Bill of Materials
    RFID - Radio-Frequency Identification
    NFC - Near Field Communication
    USB - Universal Serial Bus
    RTC - Real-Time Clock
    LED - Light Emitting Diode
    LCD - Liquid Crystal Display
    OLED - Organic Light Emitting Diode
    SD - Secure Digital (memory card)
    BLE - Bluetooth Low Energy
    WiFi - Wireless Fidelity
    MQTT - Message Queuing Telemetry Transport
    REST - Representational State Transfer



**1. Installation**

**Download and install Arduino CLI**

```
curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh
```

**Add to PATH for current session:**

```
export PATH="/home/cnc/Desktop/Arduino_cmd/test/bin:$PATH"
```

**Make it permanent (for future sessions):**

```
echo 'export PATH="/home/cnc/Desktop/Arduino_cmd/test/bin:$PATH"' >> ~/.bashrc
```

**Then, reload the .bashrc file with:**

```
source ~/.bashrc
```

**To verify if arduino-cli is installed correctly**

**Get Arduino CLI Version**

arduino-cli  Version: 1.0.4 Commit: a0d912da Date: 2024-08-12T13:42:36Z

```
arduino-cli version
```



**2. Configuration File**

**To create a new configuration file**

Note:

It stores settings such as board configurations and library paths.

The Arduino CLI stores its configuration file in the home directory

use:

```
arduino-cli config init
```


If you want to specify a custom location for the configuration file,
you can use the --config-file option when running arduino-cli. 

For example:

```
arduino-cli config init --config-file /path/to/custom/arduino-cli.yaml
```


To store the Arduino CLI configuration in the current directory
You can modify for custom settings.

```
arduino-cli config init --config-file ./arduino-cli.yaml
```


**3. List connected boards Ports**

```
arduino-cli board list
```

``` 
# arduino-cli.yaml
board:
  port: /dev/ttyUSB0                # Set the port for your board (if known)
  fqbn: arduino:avr:uno             # Change this to your actual board FQBN
```



**4. Search for Boards**

arduino-cli board search <search_term>

use:

```
arduino-cli board search esp32
arduino-cli board search nano
```

Get Board Info:

arduino-cli board info <board_fqbn>


use:

```
arduino-cli board info arduino:avr:uno
```

<manufacturer>:<architecture>:<board_type>

Arduino Uno: arduino:avr:uno
Arduino Mega: arduino:avr:mega
Arduino Nano: arduino:avr:nano
Arduino Due: arduino:sam:arduino_due_x
ESP8266: esp8266:esp8266:generic

**5. core**

arduino-cli core search

use:

```
arduino-cli core search esp32
```

**install**

arduino-cli core install <core_name>

use:

```
arduino-cli core install arduino:avr  # For Arduino AVR boards like Uno
arduino-cli core install esp32:esp32  # For ESP32 boards

```

**List Installed Cores**

use:

```
arduino-cli core list
```


```
sab@SH4D0W6:~/Desktop/GIT_MAIN/Arduino_CLI/src$ arduino-cli core list
ID              Installed Latest Name
arduino:avr     1.8.6     1.8.6  Arduino AVR Boards
esp32:esp32     3.0.2     3.0.5  esp32
esp8266:esp8266 3.1.2     3.1.2  ESP8266 Boards (3.1.2)


```


**5. Create a new sketch**

arduino-cli sketch new <sketch_name>


use:

```
arduino-cli sketch new led
```


```
.
├── arduino-cli.yaml
├── bin
│   └── arduino-cli
└── led
    └── led.ino

3 directories, 3 files

```



**6. Compile a sketch**

--verbose 

flag will provide detailed output, including information about the compilation process,
which can help you troubleshoot any issues.


arduino-cli compile --fqbn <board_fqbn> <sketch_path>

use: Compiling for an Arduino Uno.

```
arduino-cli compile --fqbn arduino:avr:uno ~/Arduino/MySketch/
```

**--output-dir: Specify an output directory for compiled files.**

```
~ # home dir 
arduino-cli compile --fqbn arduino:avr:uno --output-dir ~/Arduino/MySketch/build/ ~/Arduino/MySketch/

arduino-cli compile --fqbn arduino:avr:uno --output-dir led/ led/led.ino
```

**--warnings: Enable warnings, e.g., none, default, more, all.**

```
arduino-cli compile --fqbn arduino:avr:uno --warnings all ~/Arduino/MySketch/
```


**Export Compiled Binaries | Generate a Sketch Hex File**

arduino-cli compile --fqbn <board_fqbn> --export-binaries <sketch_path>

use: # Generate a HEX file for Arduino Uno and export to build folder

Build in the current directory of the .ino file

```
arduino-cli compile --fqbn arduino:avr:uno --export-binaries ~/Arduino/MySketch/
arduino-cli compile --fqbn arduino:avr:uno --export-binaries led/led.ino


```



```
cnc@debian:~/Desktop/Arduino_cmd/test$ tree
.
├── arduino-cli.yaml
├── bin
│   └── arduino-cli
└── led
    ├── build
    │   └── arduino.avr.uno
    │       ├── led.ino.eep
    │       ├── led.ino.elf
    │       ├── led.ino.hex
    │       ├── led.ino.with_bootloader.bin
    │       └── led.ino.with_bootloader.hex
    └── led.ino

5 directories, 8 files

```


**7. Upload a sketch**

arduino-cli upload -p <port> --fqbn <board_fqbn> <sketch_path>


use: 

```
arduino-cli upload -p /dev/ttyUSB0 --fqbn arduino:avr:uno /path/to/sketch
```


**Upload compiled sketch to Arduino Uno connected at /dev/ttyUSB0**

```
arduino-cli upload -p /dev/ttyUSB0 --fqbn arduino:avr:uno ~/Arduino/MySketch/
```

**--verify: Verifies the upload was successful.**

```
arduino-cli upload -p /dev/ttyUSB0 --fqbn arduino:avr:uno ~/Arduino/MySketch/ --verify
```

arduino-cli upload --fqbn arduino:avr:uno --port /dev/ttyUSB0 --verify ./led/




**8. Library Commands : Search for Libraries**

arduino-cli lib search <library_name>

use: 

```
arduino-cli lib search "ArduinoJson"
arduino-cli lib search "Adafruit ST7789"
arduino-cli lib search "Adafruit GFX Library"


```


**Install a Library**

arduino-cli lib install "<library_name>"

use:
 
```
arduino-cli lib install "ArduinoJson"
arduino-cli lib install "Adafruit ST7789"

```



Install a Specific Version of a Library

arduino-cli lib install <library-name>@<version>

use:
 
```
arduino-cli lib install Ethernet@2.0.1
```




**List Installed Libraries**

use:

```
arduino-cli lib list
```




```
sab@SH4D0W6:~/Desktop/GIT_MAIN/Arduino_CLI/src$ arduino-cli lib list
Name                                    Installed Available Location Description
Adafruit BusIO                          1.16.1    -         user     -
Adafruit GFX Library                    1.11.10   -         user     -
Adafruit ILI9341                        1.6.1     -         user     -
Adafruit PCD8544 Nokia 5110 LCD library 2.0.3     -         user     -
Adafruit seesaw Library                 1.7.8     -         user     -
Adafruit SH110X                         2.1.11    -         user     -
Adafruit ST7735 and ST7789 Library      1.10.4    -         user     -
Adafruit STMPE610                       1.1.6     -         user     -
Adafruit TouchScreen                    1.1.5     -         user     -
Adafruit TSC2007                        1.1.2     -         user     -
Adafruit_4_01_ColourEPaper              1.0.0     -         user     -
BlinkControl                            1.1.0     -         user     -
BTLE                                    1.0       -         user     -
Encoder                                 1.4.4     -         user     -
Ethernet                                2.0.2     -         user     -
Nokia 5110 LCD library                  2.7.1     -         user     -
nrf_to_nrf                              1.2.12    -         user     -
NRFLite                                 3.0.5     -         user     -
RF24                                    1.4.10    -         user     -
SD                                      1.3.0     -         user     -
Servo                                   1.2.2     -         user     -
Shifty                                  0.1.5     -         user     -
WiFiManager                             2.0.17    -         user     -

```












Update Libraries

```
arduino-cli lib update-index
```





**10. Serial Monitor**

arduino-cli monitor -p <port>  # Open Serial Monitor


use:

```
arduino-cli monitor -p /dev/ttyUSB0
```



**11. Show help**

use:

```
arduino-cli help
```


**Show help for a specific command (e.g., compile)**

use:

```
arduino-cli compile --help
```



**12. Burn a Bootloader**

arduino-cli burn-bootloader --fqbn <board_fqbn>


use:

```
arduino-cli burn-bootloader --fqbn arduino:avr:uno
```




**13. Update Arduino Core Index**

use:

```
arduino-cli core update-index
```





**14. Upgrade Arduino CLI**

use:

```
arduino-cli upgrade
```




**15. Uninstall a Core**

arduino-cli core uninstall <core_name>

Uninstall the AVR core for Arduino Uno, Mega, etc.

use:

```
arduino-cli core uninstall arduino:avr
```




**16. Update Libraries**

Update the library index to ensure all installed libraries are up to date

use:

```
arduino-cli lib update-index
```




**17. Install Third-Party Cores**

arduino-cli core update-index --additional-urls <url>

Add a core URL (e.g., ESP8266 core) and update index

use:

```
arduino-cli core update-index --additional-urls http://arduino.esp8266.com/stable/package_esp8266com_index.json
```










