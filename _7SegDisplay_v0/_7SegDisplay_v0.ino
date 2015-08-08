// 7 seg display driven by CD4543 IC

const int numOfDigits = 2;

class SevenSegDisplay
{
 public:
   SevenSegDisplay( int ABCDpins[], int BLpin, bool PH, int LDpins[] );  
   // Tie PH (phase) in hardware to select between common anode or cathode
   // LDpins (latch disable pins) should be in order from right to left ( digit 0 is the LSB )
   
   void begin();
   void blank(); // turns all segments off
   bool set( int num );  // displays a number on the 7seg display, returns whether or not the input was in range
   int currNum( int digNum );
   
  private:
    int _ABCDpins[4] = {};
    int _BLpin;
    bool _PH;
    int _LDpins[numOfDigits] = {};
    
    int _numOfDigits;
    int _currNum;
    int _digits[numOfDigits] = {};
};

//********************************************************************************************************************************************************
//   Member Definitions
//********************************************************************************************************************************************************

SevenSegDisplay::SevenSegDisplay( int ABCDpins[], int BLpin, bool PH, int LDpins[] ) {
  
  for( int i = 0; i < 4; i++ ) {
    _ABCDpins[i] = ABCDpins[i];
  }
  
  _BLpin = BLpin;
  _PH = PH;
  
  _numOfDigits = numOfDigits;
  
  for( int i = 0; i < numOfDigits; i++ ) {
    _LDpins[i] = LDpins[i];
  }
}

///////////////////////////////////////////////////////////////////////////////

void SevenSegDisplay::begin() {
  
  for( int i = 0; i < 4; i++ ) {
    pinMode(_ABCDpins[i], OUTPUT ); 
  }
  
  for( int i = 0; i < _numOfDigits; i++ ) {
    pinMode( _LDpins[i], OUTPUT );
  }
  
  pinMode( _BLpin, OUTPUT );
  
}

///////////////////////////////////////////////////////////////////////////////

void SevenSegDisplay::blank() {  
  digitalWrite( _BLpin, !_PH ); // enable blanking 
}

//////////////////////////////////////////////////////////////////////////////

bool SevenSegDisplay::set( int num ) {
  ////////////////////////////////////////////////////////////////////////////
  digitalWrite( _BLpin, LOW ); // disable blanking
  
  // enable all latches, no changes will be made to 7seg digits (even though ABCD will be changed
  for( int i = 0; i < _numOfDigits; i++ ) {
    digitalWrite(_LDpins[i], LOW );
  }
  
  ////////////////////////////////////////////////////////////////////////////
  
  // Split up num into digits
  int tempNum = num;
  for( int i = 0; i < _numOfDigits; i++ ) {
    _digits[i] = ( tempNum % (int)pow( 10, i+1 ) ) / (int)pow( 10, i );
    tempNum = tempNum - _digits[i] * (int)pow( 10, i );
  }
  
  ////////////////////////////////////////////////////////////////////////////
  
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
  return true;
}

//////////////////////////////////////////////////////////////////////////////

int SevenSegDisplay::currNum(int digNum) {
  return _digits[digNum];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ABCDpins[] = {2, 3, 4, 5};
int LDpins[] = {12, 13};

SevenSegDisplay Display( ABCDpins, 11, 1, LDpins );

void setup() {
 Display.begin();
}

void loop() {
  for( int i = 7; i >= 0; i-- ) {
    Display.set( i );
    delay( 500 );
  }
}
