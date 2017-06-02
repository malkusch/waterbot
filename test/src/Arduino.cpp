#include "Arduino.h"

unsigned long _millis = 0;

unsigned long millis() {
	return _millis;
}

void setMillis(unsigned long ms) {
	_millis = ms;
}

void delay(unsigned long ms) {
	_millis += ms;
}

void delayMicroseconds(unsigned int us) {

}

void pinMode(uint8_t pin, uint8_t mode) {

}

uint8_t _pins[16];
void digitalWrite(uint8_t pin, uint8_t val) {
	_pins[pin] = val;
}

uint8_t getPinState(uint8_t pin) {
	return _pins[pin];
}
