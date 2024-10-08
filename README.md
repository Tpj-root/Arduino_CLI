# Arduino_CLI
**Arduino CLI: Transforming Coders into Command Line Ninjas!**

**1. Installation**

**Download and install Arduino CLI**

```
curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh
```

**2. Configuration File**

**The configuration file arduino-cli.yaml is located in the user's home directory (~/.arduino-cli.yaml).**
**It stores settings such as board configurations and library paths.**
**To create a new configuration file**

use:

```
arduino-cli config init
```


**3. List available boards**

```
arduino-cli board list
```


**4. Search for Boards**

arduino-cli board search <search_term>

Example:

```
arduino-cli board search esp32
```

Get Board Info

arduino-cli board info <board_fqbn>


Example:

```
arduino-cli board info arduino:avr:uno
```



2. Compile a sketch

```
arduino-cli compile --fqbn <board_fqbn> <sketch_path>
```

```
arduino-cli compile --fqbn arduino:avr:uno /path/to/sketch
```


Example: Compiling for an Arduino Uno.

```
arduino-cli compile --fqbn arduino:avr:uno ~/Arduino/MySketch/
```


--output-dir: Specify an output directory for compiled files.
```
arduino-cli compile --fqbn arduino:avr:uno --output-dir ~/Arduino/MySketch/build/ ~/Arduino/MySketch/
```
--warnings: Enable warnings, e.g., none, default, more, all.
```
arduino-cli compile --fqbn arduino:avr:uno --warnings all ~/Arduino/MySketch/
```

Export Compiled Binaries

```
arduino-cli compile --fqbn <board_fqbn> --export-binaries <sketch_path>
```

```
arduino-cli compile --fqbn arduino:avr:uno --export-binaries ~/Arduino/MySketch/
```


3. Upload a sketch

```
arduino-cli upload -p <port> --fqbn <board_fqbn> <sketch_path>

```


```
arduino-cli upload -p /dev/ttyUSB0 --fqbn arduino:avr:uno /path/to/sketch
```


# Upload compiled sketch to Arduino Uno connected at /dev/ttyUSB0

```
arduino-cli upload -p /dev/ttyUSB0 --fqbn arduino:avr:uno ~/Arduino/MySketch/
```

--verify: Verifies the upload was successful.

```
arduino-cli upload -p /dev/ttyUSB0 --fqbn arduino:avr:uno ~/Arduino/MySketch/ --verify
```


4. Library Commands
Search for Libraries

arduino-cli lib search <library_name>

arduino-cli lib search "ArduinoJson"



Install a Library
arduino-cli lib install "<library_name>"
arduino-cli lib install "ArduinoJson"


List Installed Libraries

arduino-cli lib list

Update Libraries
arduino-cli lib update-index



4. Install a core
arduino-cli core install <core_name>

arduino-cli core install arduino:avr
arduino-cli core search

5. List Installed Cores
arduino-cli core list


5. Search for libraries
arduino-cli lib search <library_name>
arduino-cli lib search "Adafruit ST7789"



6. Install a library
arduino-cli lib install "<library_name>"

arduino-cli lib install "Adafruit ST7789"



List Installed Libraries
arduino-cli lib list
7. List connected boards

arduino-cli board list

8. Create a new sketch
arduino-cli sketch new <sketch_name>
arduino-cli sketch new MySketch


6. Serial Monitor
Open Serial Monitor

arduino-cli monitor -p <port>

Example:
arduino-cli monitor -p /dev/ttyUSB0


9. Show help

arduino-cli help


# Show help for a specific command (e.g., compile)
arduino-cli compile --help




11. Burn a Bootloader

arduino-cli burn-bootloader --fqbn <board_fqbn>

arduino-cli burn-bootloader --fqbn arduino:avr:uno




12. Update Arduino Core Index
arduino-cli core update-index



13. List Available Ports
arduino-cli board list







14. Search for Boards

arduino-cli board search <search_term>


arduino-cli board search nano



15. Upgrade Arduino CLI

arduino-cli upgrade



16. Uninstall a Core

arduino-cli core uninstall <core_name>

# Uninstall the AVR core for Arduino Uno, Mega, etc.
arduino-cli core uninstall arduino:avr



17. Generate a Sketch Hex File


arduino-cli compile --fqbn <board_fqbn> --output-dir <output_directory> --export-binaries <sketch_path>


# Generate a HEX file for Arduino Uno and export to build folder
arduino-cli compile --fqbn arduino:avr:uno --export-binaries ~/Arduino/MySketch/


18. Update Libraries

arduino-cli lib update-index

# Update the library index to ensure all installed libraries are up to date
arduino-cli lib update-index


19. Install Third-Party Cores

arduino-cli core update-index --additional-urls <url>


# Add a core URL (e.g., ESP8266 core) and update index
arduino-cli core update-index --additional-urls http://arduino.esp8266.com/stable/package_esp8266com_index.json




20. Get Arduino CLI Version

arduino-cli version


21. Initialize a CLI Configuration File

Generate a new arduino-cli.yaml configuration file:


arduino-cli config init

This generates a configuration file that you can modify for custom settings.








