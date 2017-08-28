Adafruit 128x64 OLED interfacting with Arduino

install Adafruit 1306 Library
https://github.com/adafruit/Adafruit_SSD1306

install Adafruit gfx Library
https://github.com/adafruit/Adafruit-GFX-Library

Edit Adafruit_SSD1306.h in text editor
Find and comment out the line: #define SSD1306_128_32 Uncomment the line: #define SSD1306_128_64

Open the ssd1306_128x64_i2c example in Arduino:
Change address from 0x3D to 0x3C in void setup()