

# default dir
/home/sab/.arduino15


```
arduino-cli config init
```

Install the Required Core:
esp32:esp32     3.0.5     3.0.5  esp32


```
arduino-cli core install esp32:esp32
```





Create a New Sketch:

arduino-cli sketch new esp32_w5500


Compile the Sketch:

arduino-cli compile --fqbn arduino:avr:uno --export-binaries led/led.ino


Upload the Sketch to the Board:

arduino-cli upload --fqbn arduino:avr:uno --port /dev/ttyUSB0 --verify ./led/


Open Serial Monitor:

arduino-cli monitor -p /dev/ttyUSB0

# Not work
# arduino-cli monitor -p /dev/ttyUSB0 --baud 9600 --data-bits 8 --parity none --stop-bits 1 --rts on --dtr on


arduino-cli monitor -p /dev/ttyUSB0 --config 9600

Monitor port settings:
  baudrate=9600
  bits=8
  dtr=on
  parity=none
  rts=on
  stop_bits=1








Board pinout


W5500 Pinout
W5500 Pin	Function	Description
1	VCC	Power Supply (+3.3V)
2	GND	Ground
3	SCS	Chip Select (Active Low)
4	SCK	Serial Clock (SPI)
5	SI	Serial Data In (MOSI)
6	SO	Serial Data Out (MISO)
7	RESET	Reset (Active Low)
8	INT	Interrupt
9	VREF	Reference Voltage
10	RXD	RXD for serial communication (if applicable)





W5500 Pin	ESP32 Pin
1	3.3V (VCC)
2	GND
3	GPIO 5 (SCS)
4	GPIO 18 (SCK)
5	GPIO 23 (SI)
6	GPIO 19 (SO)
7	GPIO 22 (RESET)
8	GPIO 21 (INT)
9	Not connected
10	Not connected







Ref:

https://www.upesy.com/blogs/tutorials/esp32-pinout-reference-gpio-pins-ultimate-guide#







run time 


sab@SH4D0W6:~/Desktop/GIT_MAIN/Arduino_CLI/src$ arduino-cli compile --fqbn arduino:avr:uno --export-binaries esp32_w5500/esp32_w5500.ino




/tmp/ccQGgLnJ.ltrans0.ltrans.o: In function `main':
/home/sab/.arduino15/packages/arduino/hardware/avr/1.8.6/cores/arduino/main.cpp:46: undefined reference to `loop'
collect2: error: ld returned 1 exit status


Used library Version Path
SPI          1.0     /home/sab/.arduino15/packages/arduino/hardware/avr/1.8.6/libraries/SPI
Ethernet     2.0.2   /home/sab/Arduino/libraries/Ethernet

Used platform Version Path
arduino:avr   1.8.6   /home/sab/.arduino15/packages/arduino/hardware/avr/1.8.6






