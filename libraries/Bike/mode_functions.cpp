// mode_functions.cpp
//  holds mode functions (idle mode, start sequence etc...)

#include "Arduino.h"
#include "mode_functions.h"
#include "LEDring_functions.h"
#include "sevenSeg_functions.h"

void startSequence() {
  Serial.println( "Beginning start sequence." );
  sevenSeg_blankAll();
  // flash LED ring as recognition of start button press
  for( int numOfFlashes = 0; numOfFlashes < 2; numOfFlashes++ ) {
    LEDring_set( 1024 );   // turn all segments on
    delay( 150 );
    LEDring_set( 0 );      // turn all segments off
    delay( 150 );
  }

  delay(350);  // gap between button recognition and countdown. Value chosen by trial and error.

  // Countdown: display 3, 2, 1 on sevenSeg at approx 1 Hz
  //  with LEDring flashes (on then off) at approx 0.5 Hz.
  for( int i = 3; i > 0; i-- ) {
    sevenSeg_set( i );
    LEDring_set( 1024 );
    delay(500);
    LEDring_set( 0 );
    delay(500);
  }
  // reset sign
  sevenSeg_blankAll();
  LEDring_set( 0 );
  Serial.println( "Ending start sequence." );

}
