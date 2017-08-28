#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>  // F Malpartida's NewLiquidCrystal library


#define I2C_ADDR    0x3F  //Define I2C Address for the PCF8574AT use I2C scanner to determine

//These Pin connections can be different for your I2C board
#define BACKLIGHT_PIN  3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7


//init LCD OBJ
LiquidCrystal_I2C  lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

void setup()
{
  lcd.begin (16,2);  // init the lcd 
  // Switch IB the backlight
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
}

void loop()
{
  // Reset the display  
  lcd.clear();
  delay(1000);
  lcd.home();
  
  // Print our characters on the LCD
//  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0); //Start at character 0 on line 0
  lcd.print("Hello, world!");
  delay(1000);
  lcd.setCursor(0,1); //Start at character 0 on line 1
  lcd.print("Bye, World!!");
  delay(1000);
} 
