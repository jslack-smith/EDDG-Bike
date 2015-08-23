// Idle mode prototype

#include <LEDring_functions.h>
#include <LEDring_patterns.h>
#include <pin_definitions.h>
#include <sevenSeg_functions.h>

int highScore = 0;
bool startBtnPressed = 0;
short patternArray[] = {};

patternArray[0] = B00000001;
patternArray[1] = B00000010;
patternArray[2] = B00000100;
patternArray[3] = B00001000;
patternArray[4] = B00010000;
patternArray[5] = B00100000;
patternArray[6] = B01000000;
patternArray[7] = B10000000;

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
  idleMode();
  Serial.println("Exited idle mode.");
}

void idleMode() {
  Serial.println("Entered idle mode.");
  
  // Display high score
  sevenSeg_set( highScore );
  
  // Display pattern on LEDring  
  int i = 0;
  while( !startBtnPressed ) {  // display LEDring pattern while the start button hasn't been pressed
    if( i = numOfSegments ) {  // reset i if end of patternArray reached
      i = 0;
    }
    LEDring_singleSet( patternArray[i] );
    i++;
  }
  Serial.println("Exiting idle mode."); // when startBtnPressed is true, exit idle mode
  return;  
}
