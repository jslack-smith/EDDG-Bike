// include all necessary local header files
#include "mode_functions.h"
#include "pin_definitions.h"
#include "LEDring_functions.h"
#include "sevenSeg_functions.h"

// define how long the rider needs to ride for (seconds)
#define runtime 10
#define ARRAY_LENGTH  10

// create variables for use in the program
long average = 0;
int score_array[ARRAY_LENGTH] = {0};
int highScore = 0;
long start_time = 0;
int analogSample = 0;
volatile bool startBtnPressed = 0;
volatile bool modeBtnPressed = 0;

void setup() {

  // initialise the LED ring
  LEDring_initialise();

  // initialise the seven segment display
  sevenSeg_initialise();

  // set the sensor pin as an analog input
  pinMode(sensorPin, INPUT);

  // setup the start button pin as an interrupt
  attachInterrupt(startBtnInt, startInterrupt, CHANGE);
  
  // setup the mode button pin as an interrupt
  attachInterrupt(modeBtnInt, modeInterrupt, CHANGE);
}

void loop() {
  
  // reset the start button being pressed
  startBtnPressed = 0;
  
  // enter idle mode until the start button is pressed
  idleMode();
  
  // run the start sequence before beginning
  delay(100);
  startSequence();
  
  if(modeBtnPressed == 0) {
  
    // start timing the user
    start_time = millis();
    
    // sample every 100ms for 30 seconds (and update the led ring)
    sevenSeg_set(30);
    while(millis() - start_time <= runtime*1000) {
      analogSample = analogRead(sensorPin);
      LEDring_set(analogSample);
      average += analogSample;
      delay(100);
      sevenSeg_set(runtime - ((millis() - start_time))/1000);
    }
    
    // clear the led ring
    LEDring_set(0);
    
    // flash the average score on the seven segment display (five times)
    sevenSeg_set(average/(runtime*10));
    delay(1000);
    sevenSeg_blankAll();
    delay(1000);
    sevenSeg_set(average/(runtime*10));
    delay(1000);
    sevenSeg_blankAll();
    delay(1000);
    sevenSeg_set(average/(runtime*10));
    delay(1000);
    sevenSeg_blankAll();
    delay(1000);
    sevenSeg_set(average/(runtime*10));
    delay(1000);
    sevenSeg_blankAll();
    delay(1000);
    sevenSeg_set(average/(runtime*10));
    delay(1000);
  
    int i = 0;

    while((i < (ARRAY_LENGTH - 1)) && (score_array[i] > average/(runtime*10))) {
	    i++;
    }

    if(i < ARRAY_LENGTH) {
	    for(int j = (ARRAY_LENGTH - 1); j >= i; j--) {
		    score_array[j] = score_array[j - 1];
	    }
	    score_array[i] = average/(runtime*10);
    }

sevenSeg_set(i+1);
delay(5000);
  
    // update the highscore if it has been broken
    if(average/(runtime*10) > highScore) {
      highScore = average/(runtime*10);
    }
  }
  
  // if the mode is charging mode
  else {
    
    // turn the seven segment displays off
    sevenSeg_blankAll();
    
    // continuously read in the sensor value until the start button is pressed and display it on the ring
    while(!startBtnPressed) {
      analogSample = analogRead(sensorPin);
      LEDring_set(analogSample);
      delay(100);
    }
  }
}

void startInterrupt() {
  
  // set the start button flag
  startBtnPressed = 1;
}

void modeInterrupt() {
  
  // set the mode button flag
  modeBtnPressed = !modeBtnPressed;
}
