#include <Arduino.h>
#include <Adafruit_I2CDevice.h>

Adafruit_I2CDevice *i2c_dev;

const int LED_COUNT = 4;
int leds[LED_COUNT] = {D7,D8,D15,D14};
bool led_status[LED_COUNT] = {true,true,true,true};

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
    toggle_leds();
    delay(2000);

  // set pin 0 and 2 to output, rest to input
  // 11111010
  //_writebuf = ^0 ~1 ~(1<<2);
  //_writebuf = 0b11111010;

  //i2c_dev->write(&_writebuf, 1);
}

void loop() {
    // Set col0 pin high
    write_byte(0b11111110);
    // Read if row 0 or row 1 are high
    i2c_dev->read(&_readbuf, 1);
    led_status[0] = ! (_readbuf & 0b00000010);
    led_status[1] = ! (_readbuf & 0b00001000);
    
    // Set col1 pin high
    write_byte(0b11111011);
    // Read if row 0 or row 1 are high
    i2c_dev->read(&_readbuf, 1);
    led_status[2] = ! (_readbuf & 0b00000010);
    led_status[3] = ! (_readbuf & 0b00001000);

    // update leds
    toggle_leds();
    delay(10); // a short debounce delay
}

void write_byte(const uint8_t value) {
    _writebuf = value;
    i2c_dev->write(&_writebuf, 1);
}

void toggle_leds(uint8_t leds_status) {
  for (int i = 0; i < LED_COUNT; i++)
  {
    digitalWrite(leds[i], ((1<<i) & leds_status) ? HIGH : LOW);
  }
}

void toggle_leds() {
    for (int i = 0; i < LED_COUNT; i++)
    {
        digitalWrite(leds[i], led_status[i] ? HIGH : LOW);
    }
}