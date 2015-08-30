#ifndef SEVENSEG_FUNCTIONS_H
#define SEVENSEG_FUNCTIONS_H

// 7seg_functions.h
//   Contains functions to interface with the 7 seg display

/* Circuit Specs:
    - CD4543 BCD to 7 Segment decoder
    - 3 digits

*/

#include "pin_definitions.h"

// constants
#define PH              0
#define numOfDigits     3

bool sevenSeg_set( int num );
void sevenSeg_blankPin( int pin );
void sevenSeg_blankAll();
void sevenSeg_unblankAll();
void sevenSeg_unblankPin( int pin );


#endif
