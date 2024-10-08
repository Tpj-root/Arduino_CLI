# Arduino_CLI
**Arduino CLI: Transforming Coders into Command Line Ninjas!**

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
you can use the --config-file option when running arduino-cli. For example:


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

arduino-cli compile --fqbn <board_fqbn> <sketch_path>

use: Compiling for an Arduino Uno.

```
arduino-cli compile --fqbn arduino:avr:uno ~/Arduino/MySketch/
```

**--output-dir: Specify an output directory for compiled files.**

```
arduino-cli compile --fqbn arduino:avr:uno --output-dir ~/Arduino/MySketch/build/ ~/Arduino/MySketch/
```

**--warnings: Enable warnings, e.g., none, default, more, all.**

```
arduino-cli compile --fqbn arduino:avr:uno --warnings all ~/Arduino/MySketch/
```


**Export Compiled Binaries | Generate a Sketch Hex File**

arduino-cli compile --fqbn <board_fqbn> --export-binaries <sketch_path>
arduino-cli compile --fqbn <board_fqbn> --output-dir <output_directory> --export-binaries <sketch_path>

use: # Generate a HEX file for Arduino Uno and export to build folder

```
arduino-cli compile --fqbn arduino:avr:uno --export-binaries ~/Arduino/MySketch/

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

**List Installed Libraries**

use:

```
arduino-cli lib list
```


Update Libraries

```
arduino-cli lib update-index
```


**9. core**

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










