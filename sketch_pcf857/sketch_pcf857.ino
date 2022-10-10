#include <Wire.h>
#include <Adafruit_PCF8574.h>
Adafruit_PCF8574 pcf;

const int LED_COUNT = 4;
int leds[LED_COUNT] = {D7,D8,D14,D15};

void setup() {

 for (int i=0; i<LED_COUNT; i++)
 {
  pinMode(leds[i], OUTPUT);
  digitalWrite(leds[i], HIGH);
 }
  delay(1000);   
  //while (!Serial) { delay(10); }
  //Serial.begin(115200);
  //Serial.println("Adafruit PCF8574 button read test");


  
  
  //setSDA(D0);
  //setSCL(D1); 

  if (!pcf.begin(0x20, &Wire)) {
    //Serial.println("Couldn't find PCF8574");
    while (1);
  }

    pcf.pinMode(0,  OUTPUT);
    pcf.pinMode(1,  INPUT_PULLUP);
    pcf.pinMode(2,  OUTPUT);
    pcf.pinMode(3,  INPUT_PULLUP);

  for (uint8_t p=4; p<8; p++) {
    pcf.pinMode(p, INPUT_PULLUP);
  }
}

void loop() {
  //for (uint8_t p=0; p<8; p++) {
    if (!pcf.digitalRead(0)) {
      //Serial.print("Button on GPIO #");
      //Serial.print(p);
      //Serial.println(" pressed!");
      // put your main code here, to run repeatedly:
      // digitalWrite(D14, HIGH);   // turn the LED on (HIGH is the voltage level)
    }
    else
    {
      //digitalWrite(D14, LOW);      
    }
  //} 
  delay(10); // a short debounce delay
}
