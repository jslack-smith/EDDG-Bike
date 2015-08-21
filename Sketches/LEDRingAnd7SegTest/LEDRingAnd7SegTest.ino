// UsingLibrariesTest.ino
//    Testing custom built library. Counts up from 0 to 9 on the 7 seg display.

// countsdown from 9 then displays your average score

#include <LEDring_functions.h>
#include <LEDring_patterns.h>
#include <pin_definitions.h>
#include <sevenSeg_functions.h>

int sensorValue = 0; // read from analog input sensorPin (potentiometer on A0)
int i = 0;
int j = 0;
double numOfMeasurements = 0;
double sum = 0;
double average = 0;

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

  sensorValue = analogRead( sensorPin );
  //Serial.println(sensorValue);
  LEDring_set(sensorValue);
  delay(20);
  i++;
  numOfMeasurements++;
  //Serial.println(numOfMeasurements);
  sum = sum + sensorValue;
  //Serial.println(sum);
  
  if( i == 50 ) {
    i = 0;  // reset counter
    sevenSeg_set( 9-j );              // display next number
    if( j == 9) {                     // if displaying a zero
      j = -1;                          // reset j
      average = sum / numOfMeasurements;  
      Serial.println(average);
      Serial.println( sum );
      Serial.println( numOfMeasurements );
      average = map(average, 0, 1024, 0, 9);     
      sevenSeg_set( average );            // display average on seven seg display
      sum = 0;                            // reset sum
      numOfMeasurements = 0;              // reset numOfMeasurements
      Serial.println(average);
      Serial.println();
      delay(1000);
    }
    j++;
  }
    
}
