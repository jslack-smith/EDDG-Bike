// UsingLibrariesTest.ino
//    Testing custom built library. Counts up from 0 to 9 on the 7 seg display.

#include <LEDring_functions.h>
#include <LEDring_patterns.h>
#include <pin_definitions.h>
#include <sevenSeg_functions.h>


void setup() {
  pinMode(BLpin1, OUTPUT);
  pinMode(ABCDpin0, OUTPUT);
  pinMode(ABCDpin1, OUTPUT);
  pinMode(ABCDpin2, OUTPUT);
  pinMode(ABCDpin3, OUTPUT);
  pinMode(LDpin0, OUTPUT);
  pinMode(LDpin1, OUTPUT);
  pinMode(LDpin2, OUTPUT);
  
  /*
  sevenSeg_set( 8 );
  delay(1000);
  sevenSeg_blankAll();
  delay(1000);
  */
  
}

void loop() {
  /*
  for( int i =0; i < 10; i++ ) {
    sevenSeg_set( i );
    delay(200);
  }
  */
  sevenSeg_set( 2 );
  delay(2000);
  sevenSeg_set(102);
  delay(2000);
  
}
