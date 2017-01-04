#ifndef _SERIAL_MOCK_H_
#define _SERIAL_MOCK_H_

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

#endif
