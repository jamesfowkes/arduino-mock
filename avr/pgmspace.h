#ifndef _PGMSPACE_H_
#define _PGMSPACE_H_

#define PSTR(x) (x)
#define PROGMEM
#define PGM_P const char *

size_t strlen_P(const char * p);
char * strcpy_P(char * dest, const char * p);

#endif