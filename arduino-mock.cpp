#include <iostream>
#include <iomanip>
#include <ctime>

#include <stdint.h>

#include "arduino-mock.h"

static long double s_start_time;

_Serial Serial;
HardwareSerial Serial1;

size_t Stream::print(unsigned char to_print) { std::cout << std::setfill('0') << std::setw(2) << std::hex << (int)to_print; return 0;}
size_t Stream::print(const char * to_print) { std::cout << to_print; return 0;}

size_t Stream::write(unsigned char to_write) { std::cout << std::setfill('0') << std::setw(2) << std::hex << (int)to_write; return 0;}
size_t Stream::write(const char * to_write) { std::cout << to_write; return 0;}

size_t Stream::println(unsigned char to_print) { std::cout << std::setfill('0') << std::setw(2) << std::hex << (int)to_print << std::endl; return 0;}
size_t Stream::println(const char * to_print) { std::cout << to_print << std::endl; return 0;}

void digitalWrite(int pin, int value)
{
	std::cout << "Writing " << (value ? "HIGH" : "LOW") << " to pin " << pin <<std::endl; 
}

int analogRead(int pin)
{
	return pin * 16;
}

int digitalRead(int pin)
{
	(void)pin;
	return HIGH;
}

unsigned long millis()
{
	return (time(0) - s_start_time) * 1000;
}

void arduino_mock_init()
{
	s_start_time = time(0);
}

void pinMode(int pin, int mode) { (void)pin; (void)mode; }
