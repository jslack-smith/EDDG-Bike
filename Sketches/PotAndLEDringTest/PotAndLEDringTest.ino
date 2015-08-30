// UsingLibrariesTest.ino
//    Testing custom built library. Counts up from 0 to 9 on the 7 seg display.

#include <LEDring_functions.h>
#include <LEDring_patterns.h>
#include <pin_definitions.h>
#include <sevenSeg_functions.h>

int sensorValue = 0;

void setup() {
  pinMode( ring_dataPin, OUTPUT );
  pinMode( ring_clkPin, OUTPUT );
  pinMode( ring_latchPin, OUTPUT );  
}

void loop() {
  
  sensorValue = analogRead( sensorPin );
    
    LEDring_set(sensorValue);
    delay(20);
    
}
