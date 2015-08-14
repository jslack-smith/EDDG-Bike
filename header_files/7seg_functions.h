// 7seg_functions.h
//   Contains functions to interface with the 7 seg display

/* Circuit Specs:
    - CD4543 BCD to 7 Segment decoder
    - 3 digits

*/

#include "pin_definitions.h"

void SevenSegDisplay::blank() {  
  digitalWrite( _BLpin, !_PH ); // enable blanking 
}

// writes a number to the display. Returns true if that number is 0.
bool SevenSegDisplay::set( int num ) {	

  digitalWrite( _BLpin, _PH ); // disable blanking
  
  // enable all latches, no changes will be made to 7seg digits (even though ABCD will be changed
  for( int i = 0; i < _numOfDigits; i++ ) {
    digitalWrite(_LDpins[i], LOW );
  }
  
  
  // Split up num into digits
  int tempNum = num;
  for( int i = 0; i < _numOfDigits; i++ ) {
    _digits[i] = ( tempNum % (int)pow( 10, i+1 ) ) / (int)pow( 10, i );
    tempNum = tempNum - _digits[i] * (int)pow( 10, i );
  }
  
    
  // print digits to 7 seg display
  for( int i = 0; i < _numOfDigits; i++ ) {  // select digit
    
    // write binary digit to ABCD pins
    for( int j = 0; j < 4; j++ ) { // read num into ABCD array
      digitalWrite( _ABCDpins[j], bitRead( _digits[i], j ) );
    }
    
    // disable latch to write to character
    digitalWrite( _LDpins[i], HIGH );  // disable curr char latch                
    digitalWrite( _LDpins[i], LOW ); // all latches enabled
  }
  if( num == 0 ) {
		return true;
	}
	else {
		return false;
	}
}
