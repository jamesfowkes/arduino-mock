#include <iostream>
#include <iomanip>
#include <ctime>
#include <map>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <stdint.h>
#include <string.h>

#include "Arduino.h"

#include "ipc.h"

using boost::property_tree::ptree;
using boost::property_tree::read_json;

static long double s_start_time;
static bool s_quit = false;

static ptree s_mock_properties;

extern void setup();
extern void loop();

static std::map<int, int> s_pin_mode_map;
static std::map<int, int> s_digital_write_map;

static bool s_quit_mock = false;

_Serial Serial;
HardwareSerial Serial1;

extern void setup();
extern void loop();

size_t Stream::print(unsigned char to_print) { std::cout << std::setfill('0') << std::setw(2) << std::hex << (int)to_print; return 0;}
size_t Stream::print(const char * to_print) { std::cout << to_print; return 0;}

size_t Stream::write(unsigned char to_write) { std::cout << (char)to_write << std::flush; return 1; }
size_t Stream::write(const char * to_write) { std::cout << to_write << std::flush; return strlen(to_write); }

size_t Stream::println(unsigned char to_print) { std::cout << (char)to_print << std::endl; return 2; }
size_t Stream::println(const char * to_print) { std::cout << to_print << std::endl; return strlen(to_print); }

void digitalWrite(int pin, int value)
{
	s_digital_write_map[pin] = value;
}

int analogRead(int pin)
{
	char path[32];
	sprintf(path, "analog_input.%d", pin);
	return s_mock_properties.get(path, 0);
}

int digitalRead(int pin)
{
	char path[32];
	sprintf(path, "digital_input.%d", pin);
	return s_mock_properties.get(path, 0);
}

void pinMode(int pin, int mode) { (void)pin; (void)mode; }

unsigned long millis()
{
	return (time(0) - s_start_time) * 1000;
}

unsigned long micros()
{
	return (time(0) - s_start_time) * 1000000;
}

uint8_t eeprom_read_byte (const uint8_t *__p) { return *__p; }
uint16_t eeprom_read_word (const uint16_t *__p) { return *__p; }
uint32_t eeprom_read_dword (const uint32_t *__p) { return *__p; }
float eeprom_read_float (const float *__p) { return *__p; }
void eeprom_read_block (void *__dst, const void *__src, size_t __n) { memcpy(__dst, __src, __n); }

void eeprom_write_byte (uint8_t *__p, uint8_t __value) { *__p = __value; }
void eeprom_write_word (uint16_t *__p, uint16_t __value) { *__p = __value; }
void eeprom_write_dword (uint32_t *__p, uint32_t __value) { *__p = __value; }
void eeprom_write_float (float *__p, float __value) { *__p = __value; }
void eeprom_write_block (const void *__src, void *__dst, size_t __n) { memcpy(__dst, __src, __n); }

void eeprom_update_byte (uint8_t *__p, uint8_t __value) { if (*__p != __value) { *__p = __value; } }
void eeprom_update_word (uint16_t *__p, uint16_t __value) { if (*__p != __value) { *__p = __value; } }
void eeprom_update_dword (uint32_t *__p, uint32_t __value) { if (*__p != __value) { *__p = __value; } }
void eeprom_update_float (float *__p, float __value) { if (*__p != __value) { *__p = __value; } }
void eeprom_update_block (const void *__src, void *__dst, size_t __n) { memcpy(__dst, __src, __n); }

size_t strlen_P(const char * p) { return strlen(p); }
char * strcpy_P(char * dest, const char * p) { strcpy(dest, p); return dest; }

void arduino_mock_init()
{
	s_start_time = time(0);

	boost::property_tree::read_json("mock-setup.json", s_mock_properties);

	ipc_setup();

	setup();
}

void pinMode(int pin, int mode)
{
	s_pin_mode_map[pin] = mode;
}

void quit_mock()
{
	s_quit_mock = true;
}

void run_mock()
{
	setup();
	
	while(!s_quit_mock)
	{
		loop();
	}
}
