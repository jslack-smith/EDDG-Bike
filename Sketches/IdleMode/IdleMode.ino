// Idle mode prototype

#include <LEDring_functions.h>
#include <LEDring_patterns.h>
#include <mode_functions.h>
#include <pin_definitions.h>
#include <sevenSeg_functions.h>

int highScore = 9;           
boolean startBtnPressed = 0;    // intended to be changed by start button interrupt
short patternArray[] = {};

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
  
  patternArray[0] = 0x0001;
  patternArray[1] = 0x0002;
  patternArray[2] = 0x0004;
  patternArray[3] = 0x0008;
  patternArray[4] = 0x0010;
  patternArray[5] = 0x0020;
  patternArray[6] = 0x0040;
  patternArray[7] = 0x0080;
  
  Serial.begin( 9600 );
  Serial.println("Hello");
  /*
  patternArray[0] = B00000001;
  patternArray[1] = B00000010;
  patternArray[2] = B00000100;
  patternArray[3] = B00001000;
  patternArray[4] = B00010000;
  patternArray[5] = B00100000;
  patternArray[6] = B01000000;
  patternArray[7] = B10000000;
  */
}

void loop() {
  delay(500);
  idleMode();
  //Serial.println("Exited idle mode.");
}

void idleMode() {
  Serial.println("Entered idle mode.");
  // Display high score
  sevenSeg_set( highScore );
  
  // Display pattern on LEDring  
  int i = 0;
  while( !startBtnPressed ) {  // display LEDring pattern while the start button hasn't been pressed
    if( i = numberOfSegments ) {  // reset i if end of patternArray reached
      i = 0;
    }
    LEDring_singleSet( patternArray[i] );
    delay(100);
    i++;
  }
  Serial.println("Exiting idle mode."); // when startBtnPressed is true, exit idle mode
  return;  
}
