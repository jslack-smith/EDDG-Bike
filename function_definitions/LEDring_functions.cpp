// LEDring_functions.cpp
//  temporary container for LED ring function definitions

#include "Arduino.h"
#include "LEDring_functions.h"

void LEDring_patternDelay( short pattern[], int period )
{
    for( int i = 0; i < sizeof(pattern)/sizeof(int); i++) {
        shiftOut( ring_dataPin, ring_clkPin, MSBFIRST, pattern[i]>>8 ); // shift second byte
        shiftOut( ring_dataPin, ring_clkPin, MSBFIRST, pattern[i] );    // shift first byte
        delay(period);
        i++;
    }
}

void LEDring_set( int score )
{
    // map measured value [0, 1204] to number of segments to light up [0, 16]
    int numOfSegments = 0;
    numOfSegments = map( score, 0, 1024, 0, 16 );

    // map number of segments to light up to short data
    short data = 0x0000;
    if( numOfSegments == 0 ) {
        data = 0x0000;
    }
    else {
        data = 0x1000 >> (numOfSegments - 1);   // using right shift to fill with ones
    }

    // write to LEDring
    shiftOut( ring_dataPin, ring_clkPin, LSBFIRST, data );
    shiftOut( ring_dataPin, ring_clkPin, LSBFIRST, data>>8 );
}
