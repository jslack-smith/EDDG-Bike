// Start sequence prototype
//  Communicates start button press recognition to user with LEDring flashes. 
//  Then counts down (3, 2, 1) on sevenSeg with LEDring flashes. 

#include <LEDring_functions.h>
#include <LEDring_patterns.h>
#include <pin_definitions.h>
#include <sevenSeg_functions.h>

void setup() {
  // LED ring 
  pinMode( ring_dataPin, OUTPUT );
  pinMode( ring_clkPin, OUTPUT );
  pinMode( ring_latchPin, OUTPUT );  
  
  // 7 Seg Display
  pinMode(BLpin0, OUTPUT);
  pinMode(BLpin1, OUTPUT);
  pinMode(BLpin2, OUTPUT);
  pinMode(ABCDpin0, OUTPUT);
  pinMode(ABCDpin1, OUTPUT);
  pinMode(ABCDpin2, OUTPUT);
  pinMode(ABCDpin3, OUTPUT);
  pinMode(LDpin0, OUTPUT);
  pinMode(LDpin1, OUTPUT);
  pinMode(LDpin2, OUTPUT);

  Serial.begin( 9600 );
}

void loop() {
  Serial.println( "Beginning start sequence." );
  // flash LED ring as recognition of start button press
  for( int numOfFlashes = 0; numOfFlashes < 2; numOfFlashes++ ) {
    LEDring_set( 1024 );   // turn all segments on
    delay( 200 );
    LEDring_set( 0 );      // turn all segments off
    delay( 200);
  }
  
  // Countdown: display 3, 2, 1 on sevenSeg at approx 1 Hz  
  //  with LEDring flashes (on then off) at approx 0.5 Hz.
  for( int i = 3; i > 0; i-- ) {
    sevenSeg_set( i );            
    LEDring_set( 1024 );
    delay(500);
    LEDring_set( 0 );
    delay(500);
  }
  Serial.println( "Ending start sequence." );
}
