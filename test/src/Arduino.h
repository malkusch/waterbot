#pragma once

#include <stdio.h>

#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define lowByte(w) ((unsigned char) ((w) & 0xff))
#define highByte(w) ((unsigned char) ((w) >> 8))
#define HIGH 0x1
#define LOW  0x0
#define INPUT 0x0
#define OUTPUT 0x1

typedef unsigned char byte;
typedef unsigned short int word;
typedef signed int int8_t __attribute__((__mode__(__QI__)));
typedef unsigned int uint8_t __attribute__((__mode__(__QI__)));
#ifndef __SIZE_TYPE__
#define __SIZE_TYPE__ long unsigned int
#endif
typedef __SIZE_TYPE__ size_t;

void delay(unsigned long ms);
unsigned long millis();
void setMillis(unsigned long millis);
void pinMode(uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t pin, uint8_t val);
int analogRead(uint8_t pin);

class String {
public:
	String(const char *cstr = "");
	String(const String &str);
	explicit String(char c);
	explicit String(unsigned char, unsigned char base = 10);
	explicit String(int, unsigned char base = 10);
	explicit String(unsigned int, unsigned char base = 10);
	explicit String(long, unsigned char base = 10);
	explicit String(unsigned long, unsigned char base = 10);
	explicit String(float, unsigned char decimalPlaces = 2);
	explicit String(double, unsigned char decimalPlaces = 2);

	String & operator +=(const String &rhs);
	String & operator +=(const char *cstr);
	String & operator +=(char c);
	String & operator +=(unsigned char num);
	String & operator +=(int num);
	String & operator +=(unsigned int num);
	String & operator +=(long num);
	String & operator +=(unsigned long num);
	String & operator +=(float num);
	String & operator +=(double num);

	friend String & operator +(const String &lhs, const String &rhs);
	friend String & operator +(const String &lhs, const char *cstr);
	friend String & operator +(const String &lhs, char c);
	friend String & operator +(const String &lhs, unsigned char num);
	friend String & operator +(const String &lhs, int num);
	friend String & operator +(const String &lhs, unsigned int num);
	friend String & operator +(const String &lhs, long num);
	friend String & operator +(const String &lhs, unsigned long num);
	friend String & operator +(const String &lhs, float num);
	friend String & operator +(const String &lhs, double num);

};

class Serial {
public:
	void begin(unsigned long);
	size_t println(const String &s);
};
extern Serial Serial;

