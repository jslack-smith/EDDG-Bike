// UsingLibrariesTest.ino
//    Testing custom built library. Counts up from 0 to 9 on the 7 seg display.

#include <LEDring_functions.h>
#include <LEDring_patterns.h>
#include <pin_definitions.h>
#include <sevenSeg_functions.h>


void setup() {
  pinMode( ring_dataPin, OUTPUT );
  pinMode( ring_clkPin, OUTPUT );
  pinMode( ring_latchPin, OUTPUT );  
}

short data = B10000000;

void loop() {
  /*for( int i = 0; i < 522; i++ ) {
    LEDring_singleSet( i );
    delay(1);
  } */
    
    LEDring_singleSet(data);
    delay(1000);
    data >> 1;
    if(data == B00000000) {
      data = B10000000;
    }
    
  /*
  digitalWrite( ring_latchPin, 0 );
  shiftOut( ring_dataPin, ring_clkPin, LSBFIRST, data );
  digitalWrite( ring_latchPin, 1 );
  */
}
