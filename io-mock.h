#ifndef _IO_MOCK_H_
#define _IO_MOCK_H_

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

#endif
