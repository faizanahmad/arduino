// https://learn.adafruit.com/adafruit-ds3231-precision-rtc-breakout/wiring-and-test
// Using RTCLib from https://github.com/adafruit/RTClib

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "RTClib.h"

RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

//OLED interfacing
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);


void setup() {

  #ifndef ESP8266
    while (!Serial); // for Leonardo/Micro/Zero
  #endif


  // put your setup code here, to run once:
  Serial.begin(9600);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay(); 


  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
  
}

void loop() {
  DateTime now = rtc.now();
  
  display.clearDisplay(); 
  
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);

  String rtc_date = String(now.day(),DEC) + '-' + String(now.month(),DEC) + '-' + String(now.year(),DEC);
  String rtc_time = String(now.hour(),DEC) + ':' + String(now.minute(),DEC) + ':' + String(now.second(),DEC);

  display.println(rtc_date);
  display.print(rtc_time);
  display.display();

  delay(1000);
  
  
}
