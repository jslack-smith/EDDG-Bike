// include all necessary local header files
#include "mode_functions.h"
#include "pin_definitions.h"
#include "LEDring_functions.h"
#include "sevenSeg_functions.h"

// create variables for use in the program
int average = 0;
int highScore = 7;
long start_time = 0;
int analogSample = 0;
bool startBtnPressed = 0;

void setup() {

  // initialise the LED ring
  LEDring_initialise();

  // initialise the seven segment display
  sevenSeg_initialise();

  // set the sensor pin as an analog input
  pinMode(sensorPin, INPUT);

  // setup the start button pin as an interrupt
  attachInterrupt(startBtnInt, startInterrupt, FALLING);
}

void loop() {
  
  // reset the start button being pressed
  startBtnPressed = 0;
  
  // enter idle mode until the start button is pressed
  idleMode();
  
  // run the start sequence before beginning
  delay(100);
  startSequence();
  
  // start timing the user
  start_time = millis();
  
  // sample every 100ms for 30 seconds (and update the led ring)
  while(millis() - start_time <= 30000) {
    analogSample = analogRead(sensorPin);
    LEDring_set(analogSample);
    average += analogSample;
    delay(100);
  }
  
  // clear the led ring
  LEDring_set(0);
  
  // flash the average score on the seven segment display (five times)
  sevenSeg_set(average/300);
  delay(1000);
  sevenSeg_blankPin(BLpin0);
  delay(1000);
  sevenSeg_set(average/300);
  delay(1000);
  sevenSeg_blankPin(BLpin0);
  delay(1000);
  sevenSeg_set(average/300);
  delay(1000);
  sevenSeg_blankPin(BLpin0);
  delay(1000);
  sevenSeg_set(average/300);
  delay(1000);
  sevenSeg_blankPin(BLpin0);
  delay(1000);
  sevenSeg_set(average/300);
  delay(1000);

  // update the highscore if it has been broken
  if(analogSample > highScore) {
    highScore = analogSample;
  }
}

void startInterrupt() {
  
  // set the start button flag
  startBtnPressed = 1;
}
