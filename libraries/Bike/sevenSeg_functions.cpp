// sevenSeg_functions.c
//  temporary holder for sevenSeg function definitions

#include "Arduino.h"
#include "sevenSeg_functions.h"

// constants
#define PH              0
#define numOfDigits     3

void sevenSeg_blank() {
  digitalWrite( BLpin, !PH ); // enable blanking
}

// writes a number to the display. Returns true if that number is 0.
bool sevenSeg_set( int num ) {

  int LDpins[3] = { LDpin0, LDpin1, LDpin2 };
  int ABCDpins[4] = { ABCDpin0, ABCDpin1, ABCDpin2, ABCDpin3 };

  int digits[3] = { 0, 0, 0 };
  int ABCD[4] = { 0, 0, 0, 0 };

  digitalWrite( BLpin, PH ); // disable blanking

  // enable all latches, no changes will be made to 7seg digits (even though ABCD will be changed
  for( int i = 0; i < numOfDigits; i++ ) {
    digitalWrite(LDpins[i], LOW );
  }


  // Split up num into digits
  int tempNum = num;
  for( int i = 0; i < numOfDigits; i++ ) {
    digits[i] = ( tempNum % (int)pow( 10, i+1 ) ) / (int)pow( 10, i );
    tempNum = tempNum - digits[i] * (int)pow( 10, i );
  }


  // print digits to 7 seg display
  for( int i = 0; i < numOfDigits; i++ ) {  // select digit

    // write binary digit to ABCD pins
    for( int j = 0; j < 4; j++ ) { // read num into ABCD array
      digitalWrite( ABCDpins[j], bitRead( digits[i], j ) );
    }

    // disable latch to write to character
    digitalWrite( LDpins[i], HIGH );  // disable curr char latch
    digitalWrite( LDpins[i], LOW ); // all latches enabled
  }
  if( num == 0 ) {
		return true;
	}
	else {
		return false;
	}
}
