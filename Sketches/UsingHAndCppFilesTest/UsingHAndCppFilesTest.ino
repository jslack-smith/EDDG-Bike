#include "pin_definitions.h"
#include "sevenSeg_functions.h"

void setup() {
  pinMode(BLpin, OUTPUT);
  pinMode(ABCDpin0, OUTPUT);
  pinMode(ABCDpin1, OUTPUT);
  pinMode(ABCDpin2, OUTPUT);
  pinMode(ABCDpin3, OUTPUT);
  pinMode(LDpin0, OUTPUT);
  pinMode(LDpin1, OUTPUT);
  pinMode(LDpin2, OUTPUT);
}

void loop() {
  sevenSeg_set( 1 );
}
