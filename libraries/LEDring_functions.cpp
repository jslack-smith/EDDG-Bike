/*  LEDring_functions.cpp
 *   
 *   This file contains all function definitions for the led ring
 *   
 *   Change Log: 
 *      28th August 2015 (JL)
 *          - clean up
 *          - added initialisation function
 *          - removed unused function prototypes
 *          - converted binary patterns to hexadecimal notation and expanded to 16 bits
 *          - added minAnalogInput and maxAnalogInput constants to make expanding easier
 *          
 *      27th August 2015 (JL & JSS)
 *          - fixed bug (inverted output of patterns)
 *          
 *      25th August 2015 (JSS)
 *          - clean up
 *          - fixed bug (variable and definition conflict of "numberOfSegments")
 *          
 *      23rd August 2015 (JSS) 
 *          - added "numberOfSegments" constant definition
 *          
 *      21st August 2015 (JSS)
 *          - fixed bug (missing semi-colon)
 *          
 *      16th August 2015 (JSS)
 *          - created file with initial definitions
 */

// include all necessary header files
#include "Arduino.h"
#include "pin_definitions.h"
#include "LEDring_functions.h"

// LEDring_initialise()
//     this function intialises the led ring display by
//     setting all the necessary pins to the correct pin modes
void LEDring_initialise() {
  pinMode( ring_dataPin, OUTPUT );
  pinMode( ring_clkPin, OUTPUT );
  pinMode( ring_latchPin, OUTPUT ); 
}

// LEDring_set(int score)
//     this function lights the corresponding number of segments in the led
//     ring depending on the score passed as an argument
void LEDring_set(int score) {
    
    // map measured value [0, 1024] to number of segments to light up [0, numOfSegments]
    int numSegments = 0;
    numSegments = map(score, minAnalogInput, maxAnalogInput, 0, numOfSegments);

    // map number of segments to light up to short data
    byte data = 0x00;

    // determine the output pattern based on the mapped score
    switch(numSegments) {
      case 0:  data = 0x0000; break;
      case 1:  data = 0x0001; break;
      case 2:  data = 0x0003; break;
      case 3:  data = 0x0007; break;
      case 4:  data = 0x000F; break;
      case 5:  data = 0x001F; break;
      case 6:  data = 0x003F; break;
      case 7:  data = 0x007F; break;
      case 8:  data = 0x00FF; break;
      case 9:  data = 0x01FF; break;
      case 10: data = 0x03FF; break;
      case 11: data = 0x07FF; break;
      case 12: data = 0x0FFF; break;
      case 13: data = 0x1FFF; break;
      case 14: data = 0x3FFF; break;
      case 15: data = 0x7FFF; break;
      case 16: data = 0xFFFF; break;
      default: data = 0x0000; break;
    }

    // write the pattern to the led ring
    LEDring_singleSet(data);
}

// LEDring_singleSet(short pattern)
//     this function lights the corresponding segments of the led ring depending 
//     on the specific pattern passed as an argument
void LEDring_singleSet( short pattern ) {
    
    // XOR the pattern with 1's to invert the pattern (since it is common anode)
    pattern = 0x00FF^pattern;
  
    // write the data to the led ring by shifting the data out
    digitalWrite(ring_latchPin, 0);
    shiftOut(ring_dataPin, ring_clkPin, MSBFIRST, pattern);
    //shiftOut(ring_dataPin, ring_clkPin, MSBFIRST, pattern>>8);
    digitalWrite(ring_latchPin, 1);
}
