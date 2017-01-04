#ifndef _ARDUINO_MOCK_H_
#define _ARDUINO_MOCK_H_

#include <avr/pgmspace.h>

#include "io-mock.h"
#include "serial-mock.h"

unsigned long millis();
unsigned long micros();

void arduino_mock_init();
void arduino_mock_run();
void arduino_mock_quit();

#endif
