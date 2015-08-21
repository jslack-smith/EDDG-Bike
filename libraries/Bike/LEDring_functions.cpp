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
    numOfSegments = map( score, 1024, 0, 0, 8 );

    // map number of segments to light up to short data
    byte data = B00000000;

    switch (numOfSegments) {
    case 0: data = B00000000; break;
    case 1: data = B00000001; break;
    case 2: data = B00000011; break;
    case 3: data = B00000111; break;
    case 4: data = B00001111; break;
    case 5: data = B00011111; break;
    case 6: data = B00111111; break;
    case 7: data = B01111111; break;
    case 8: data = B11111111; break;
    default: data = B00000000; break;
    }

    // write to LEDring
    digitalWrite( ring_latchPin, 0 );
    shiftOut( ring_dataPin, ring_clkPin, LSBFIRST, data );
    //shiftOut( ring_dataPin, ring_clkPin, LSBFIRST, data>>8 );
    digitalWrite( ring_latchPin, 1 );
}


void LEDring_singleSet( short pattern )
{
    // write to LEDring
    digitalWrite( ring_latchPin, 0 );
    shiftOut( ring_dataPin, ring_clkPin, LSBFIRST, pattern );
    //shiftOut( ring_dataPin, ring_clkPin, LSBFIRST, data>>8 );
    digitalWrite( ring_latchPin, 1 );
}
