
#include <Adafruit_PCF8574.h>

Adafruit_PCF8574 pcf;

void setup() {
  delay(1000);
  pinMode(D14, OUTPUT);
  digitalWrite(D14, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);   
  while (!Serial) { delay(10); }
  Serial.begin(115200);
  Serial.println("Adafruit PCF8574 button read test");
  digitalWrite(D14, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);   

  if (!pcf.begin(0x20, &Wire)) {
    //Serial.println("Couldn't find PCF8574");
    while (1);
  }
  for (uint8_t p=0; p<8; p++) {
    pcf.pinMode(p, INPUT_PULLUP);
  }
}

void loop() {
  /*
    for (uint8_t p=0; p<8; p++) {
    if (! pcf.digitalRead(p)) {
      Serial.print("Button on GPIO #");
      Serial.print(p);
      Serial.println(" pressed!");
       // put your main code here, to run repeatedly:
  digitalWrite(D14, LOWz);   // turn the LED on (HIGH is the voltage level)
    }
    } 
  delay(10); // a short debounce delay
  */
  // put your main code here, to run repeatedly:
                      // wait for a second
  digitalWrite(D14, LOW);    // turn the LED off by making the voltage LOW
  delay(1000); 
}
