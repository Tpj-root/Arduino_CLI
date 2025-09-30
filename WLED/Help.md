# Erase the flash first (recommended)
esptool --chip esp32 --port /dev/ttyUSB0 erase-flash

# Write the .bin file to flash
esptool --chip esp32 --port /dev/ttyUSB0 write-flash -z 0x0 WLED_0.16.0-alpha_ESP32_V4.bin 


# Reset the board (if needed)
esptool.py --chip esp32s2 --port /dev/ttyUSB0 reset






esptool --chip esp8266 --port /dev/ttyUSB0 write_flash -fm dout 0x0 WLED_0.15.0-b3_ESP8266.bin









https://github.com/wled/WLED/releases/tag/v0.15.1









https://github.com/G6EJD/ESP32-8266-File-Upload

https://github.com/G6EJD/ESP32-8266-Audio-Spectrum-Display?tab=readme-ov-file







(base) cnc@debian:~/Desktop/MY_GIT/Arduino_CLI/t$ esptool --chip esp8266 --port /dev/ttyUSB0 write_flash -fm dout 0x0 WLED_0.15.0-b3_ESP8266.bin
Warning: Deprecated: Command 'write_flash' is deprecated. Use 'write-flash' instead.
esptool v5.0.2
Connected to ESP8266 on /dev/ttyUSB0:
Chip type:          ESP8266EX
Features:           Wi-Fi, 160MHz
Crystal frequency:  26MHz
MAC:                48:e7:29:6d:33:ea

Stub flasher running.

Configuring flash size...
Flash will be erased from 0x00000000 to 0x000d9fff...
Compressed 890336 bytes to 641491...
Writing at 0x00005380 [                              ]   2.6% 16384/641491 
bytesWriting at 0x0000b1e7 [>                             ]   5.1% 32768/641491 
bytesWriting at 0x000114ee [=>                            ]   7.7% 49152/641491 
bytesWriting at 0x0001789b [==>                           ]  10.2% 65536/641491 
bytesWriting at 0x0001d3f2 [==>                           ]  12.8% 81920/641491 
bytesWriting at 0x00022fcc [===>                          ]  15.3% 98304/641491 
bytesWriting at 0x0002aa12 [====>                         ]  17.9% 114688/641491 
byteWriting at 0x00030574 [=====>                        ]  20.4% 131072/641491 
byteWriting at 0x000363e4 [=====>                        ]  23.0% 147456/641491 
byteWriting at 0x0003be48 [======>                       ]  25.5% 163840/641491 
byteWriting at 0x00041a53 [=======>                      ]  28.1% 180224/641491 
byteWriting at 0x00047bf3 [========>                     ]  30.6% 196608/641491 
byteWriting at 0x0004d349 [========>                     ]  33.2% 212992/641491 
byteWriting at 0x000535bd [=========>                    ]  35.8% 229376/641491 
byteWriting at 0x000590b3 [==========>                   ]  38.3% 245760/641491 
byteWriting at 0x0005ef93 [===========>                  ]  40.9% 262144/641491 
byteWriting at 0x000650e5 [============>                 ]  43.4% 278528/641491 
byteWriting at 0x0006aeb6 [============>                 ]  46.0% 294912/641491 
byteWriting at 0x00071b8e [=============>                ]  48.5% 311296/641491 
byteWriting at 0x0007733e [==============>               ]  51.1% 327680/641491 
byteWriting at 0x0007d260 [===============>              ]  53.6% 344064/641491 
byteWriting at 0x0008285f [===============>              ]  56.2% 360448/641491 
byteWriting at 0x000880f8 [================>             ]  58.7% 376832/641491 
byteWriting at 0x0008d0fd [=================>            ]  61.3% 393216/641491 
byteWriting at 0x000920f0 [==================>           ]  63.9% 409600/641491 
byteWriting at 0x0009726c [==================>           ]  66.4% 425984/641491 
byteWriting at 0x0009cb16 [===================>          ]  69.0% 442368/641491 
byteWriting at 0x000a2323 [====================>         ]  71.5% 458752/641491 
byteWriting at 0x000a774d [=====================>        ]  74.1% 475136/641491 
byteWriting at 0x000acd1d [=====================>        ]  76.6% 491520/641491 
byteWriting at 0x000b333a [======================>       ]  79.2% 507904/641491 
byteWriting at 0x000b73a4 [=======================>      ]  81.7% 524288/641491 
byteWriting at 0x000bb3c8 [========================>     ]  84.3% 540672/641491 
byteWriting at 0x000bf3d2 [=========================>    ]  86.8% 557056/641491 
byteWriting at 0x000c33cd [=========================>    ]  89.4% 573440/641491 
byteWriting at 0x000c7393 [==========================>   ]  91.9% 589824/641491 
byteWriting at 0x000cccce [===========================>  ]  94.5% 606208/641491 
byteWriting at 0x000d2d61 [============================> ]  97.1% 622592/641491 
byteWriting at 0x000d85b6 [============================> ]  99.6% 638976/641491 
byteWrote 890336 bytes (641491 compressed) at 0x00000000 in 58.7 seconds (121.3 
kbit/s).
Hash of data verified.

Hard resetting via RTS pin...
(base) cnc@debian:~/Desktop/MY_GIT/Arduino_CLI/t$ 



If you want to completely reset settings, then you have to erase NVS before flashing:

esptool --chip esp8266 --port /dev/ttyUSB0 erase_flash
