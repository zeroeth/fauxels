/* Limited recreation of expected arduino header for testing */

#ifndef Virtuino_h
#define Virtuino_h


#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/timeb.h> // Portability?
#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "Serial.h"

#define OUTPUT 1
#define HIGH 2
#define LOW 3

#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))

// TODO link against real headers
void pinMode      ( uint8_t, uint8_t );
void digitalWrite ( uint8_t, uint8_t );
int  digitalRead  ( uint8_t );
void delay        ( unsigned long );

unsigned long millis (void);

#ifdef __cplusplus
} // extern C
#endif

#endif // Virduino_h
