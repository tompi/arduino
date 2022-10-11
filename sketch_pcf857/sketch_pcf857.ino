#include <Adafruit_BusIO_Register.h>
#include <Adafruit_I2CDevice.h>


Adafruit_I2CDevice *i2c_dev;

const int LED_COUNT = 4;
int leds[LED_COUNT] = {D7,D8,D15,D14};
bool led_status[LED_COUNT] = {0,0,0,0};

uint8_t _readbuf = 0, _writebuf = 0;

void setup() {

  delay(100);   

  i2c_dev = new Adafruit_I2CDevice(0x20, &Wire);
  i2c_dev->begin();
  for (int i=0; i<LED_COUNT; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
  
  // turn leds on and off to see they are working
  toggle_leds(0b00001111);
  delay(2000);
  toggle_leds(0);


  // set pin 0 and 2 to output, rest to input
  // 11111010
  //_writebuf = ^0 ~1 ~(1<<2);
  _writebuf = 0b11111010;

  i2c_dev->write(&_writebuf, 1);
}

void loop() {
  i2c_dev->read(&_readbuf, 1);

  toggle_leds(_readbuf);

  delay(10); // a short debounce delay
}

void toggle_leds(uint8_t leds_status) {
  for (int i = 0; i < LED_COUNT; i++)
  {
    digitalWrite(leds[i], ((1<<i) & leds_status) ? HIGH : LOW);
  }
}