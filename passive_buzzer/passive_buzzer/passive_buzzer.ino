//PWM Library used from
//https://code.google.com/archive/p/arduino-pwm-frequency-library/downloads

#include <PWM.h>

int incomingByte = 0;
int outputPin = 9;

int dutyCycle = 127;
int32_t frequency = 500; //frequency (in Hz)

void setup() {

  //initialize all timers except for 0, to save time keeping functions
  InitTimersSafe();


  //sets the frequency for the specified pin
  bool success = SetPinFrequencySafe(outputPin, frequency);
  if(success) {
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);    
  }

  
  Serial.begin(9600);
}

void loop() {
   if (Serial.available() > 0) {
      // read the incoming byte:
      incomingByte = Serial.read();


       if(incomingByte == 117) {
         dutyCycle = dutyCycle + 10;
       }
       else if(incomingByte == 100) {
         dutyCycle = dutyCycle - 10;        
       }

       //increase frequency
       else if(incomingByte == 104) {
         frequency = frequency + 100;    
         bool success = SetPinFrequencySafe(outputPin, frequency);    
       }

       //Decrease Frequency
       else if(incomingByte == 108) {
         frequency = frequency - 100;    
         bool success = SetPinFrequencySafe(outputPin, frequency);    
       }

       Serial.println((String)"Freq: "+ frequency + "Hz - DutyCycle: "+ dutyCycle + " - inp: " + incomingByte);
       

    }

     pwmWrite(outputPin, dutyCycle);
     
     delay(300); 
}
