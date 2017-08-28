#include "DHT.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//DHT22 interfacing
#define DHT2PIN 4
#define DHT2TYPE DHT22   // DHT 22  (AM2302), AM2321

DHT dht2(DHT2PIN, DHT2TYPE);

//OLED interfacing
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif


void setup() {
  Serial.begin(9600);

  //start DHT sensor
  dht2.begin();
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x64)

  // Display Adafruit splash screen which is loaded by default for 2 seconds
  //  display.display();
  //  delay(2000);

  display.clearDisplay(); 
}

void loop() {  
  display.clearDisplay();  

  float h2 = dht2.readHumidity();
  float t2 = dht2.readTemperature();
  float hic = dht2.computeHeatIndex(t2, h2, false);


  
  if (isnan(h2) || isnan(t2)) {
    display.print("Error");
    Serial.println("Failed to read from DHT11 sensor!");
    return;
  }
  else {
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.print("Temp: ");
    display.print(t2);      
    display.print(" ");
    display.write(247); //ASCII for degree char
    display.print("C");

    
    display.setCursor(0,22);
    display.print("Hmdy: ");
    display.print(h2);
    display.print(" %");

    
    display.setCursor(0,44);
    display.print("Hidx: ");
    display.print(hic);
    display.print(" ");
    display.write(247); //ASCII for degree char
    display.print("C");
    
    display.display();

    
    Serial.print("H2: ");
    Serial.print(h2);
    Serial.print(" %\t");
    Serial.print("T2: ");
    Serial.print(t2);
    Serial.print(" *C\t");

    Serial.print("I: ");
    Serial.print(hic);
    Serial.println(" %");
  }
  delay(2000);

}

void testdrawchar(void) {
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);

  for (uint8_t i=168; i < 250; i++) {
    if (i == '\n') continue;
    display.write(i);
    if ((i > 0) && (i % 21 == 0))
      display.println();
  }    
  display.display();
  delay(1);
}
