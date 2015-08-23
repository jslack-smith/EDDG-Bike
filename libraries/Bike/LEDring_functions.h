#ifndef LEDRING_FUNCTIONS_H
#define LEDRING_FUNCTIONS_H

// LEDring_functions.h
//   Contains functions to interface with the LED ring

/* Circuit Specs:
    - 2 74HC595 IC's
    - 2 High Current Darlington Array IC's
    - 16 segments

*/

#include "pin_definitions.h"

// constants
#define numOfSegments 8

// takes a array of 16-bit shorts (pattern[]) and displays it on the LEDring. Each short in pattern is
//  displayed for "period" ms. Uses delays.
void LEDring_patternDelay( short pattern[], int period );
void LEDring_set( int score );
void LEDring_singleSet( short pattern );

#endif
