Displaying Temperature and Humidity Values on 128x64 OLED Display

DHT22 data pin attached to Digital Pin4

--------------------------------------------------------------------

Adafruit 128x64 OLED interfacting with Arduino

VDD = +5V
GND = GND
SCK = A5
SDA = A4

install Adafruit 1306 Library
https://github.com/adafruit/Adafruit_SSD1306

install Adafruit gfx Library
https://github.com/adafruit/Adafruit-GFX-Library

Edit Adafruit_SSD1306.h in text editor
Find and comment out the line: #define SSD1306_128_32 Uncomment the line: #define SSD1306_128_64

Open the ssd1306_128x64_i2c example in Arduino:
Change address from 0x3D to 0x3C in void setup()