#ifndef _ARDUINO_MOCK_H_
#define _ARDUINO_MOCK_H_

#define HIGH (1)
#define LOW (0)

#define A0 (0)
#define A1 (1)
#define A2 (2)
#define A3 (3)
#define A4 (4)
#define A5 (5)

#define OUTPUT (0)
#define INPUT (1)
#define INPUT_PULLUP (2)

void digitalWrite(int pin, int value);
int digitalRead(int pin);
int analogRead(int pin);
void pinMode(int pin, int mode);

class Stream
{
public:
    size_t write(unsigned char to_write);
	size_t write(const char * to_write);

    size_t print(unsigned char to_print);
	size_t print(const char * to_print);

	size_t println(unsigned char to_print);
	size_t println(const char * to_print);

};

class _Serial : public Stream
{
public:
	void begin(int baud) { (void)baud; }	

	bool available() { return false; }
	char read() { return '\0'; }
};

class HardwareSerial : public _Serial
{

};

extern _Serial Serial;
extern HardwareSerial Serial1;

unsigned long millis();
void arduino_mock_init();

#endif
