/*  LEDring_patterns.h
 *   
 *   This file contains all pattern definitions for the LED ring. All patterns are stored in a short array.
 *   
 *   Change Log: 
 *      28th August 2015 (JL)
 *          - clean up
 *          - changed binary values to hexadecimal notation
 *          
 *      27th August 2015 (JL)
 *          - added onebyone pattern
 *          - added twobytwo pattern
 *          
 *      16th August 2015 (JSS)
 *          - created file
 */

#ifndef LEDRING_PATTERNS_H
#define LEDRING_PATTERNS_H

// include all necessary header files
#include <Arduino.h>
#include "LEDring_functions.h"

// define the patterns in an array of shorts (hexadecimal notation)
short pattern_onebyone[numOfSegments] = {0x0001, 0x0002, 0x0004, 0x0008, 0x0010, 0x0020, 0x0040, 0x0080};
short pattern_twobytwo[numOfSegments] = {0x0011, 0x0022, 0x0044, 0x0088, 0x0011, 0x0022, 0x0044, 0x0088};

#endif
