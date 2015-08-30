/*  mode_functions.cpp
 *   
 *   This file contains all function prototypes and constant definitions for the different modes.
 *   
 *   Change Log: 
 *      28th August 2015 (JL)
 *          - clean up
 *          - added idleMode
 *          - created extern variables
 *          
 *      25th August 2015 (JSS)
 *          - created file
 */

// include all necessary header files
#include "Arduino.h"
#include "mode_functions.h"
#include "LEDring_patterns.h"
#include "LEDring_functions.h"
#include "sevenSeg_functions.h"

// startSequence()
//     this function runs the start sequence animation to 
//     countdown to when the rider should start pedalling
void startSequence() {
  
  // blank the seven segment display out
  sevenSeg_blankAll();
  
  // flash LED ring as recognition of start button press
  for(int numOfFlashes = 0; numOfFlashes < 2; numOfFlashes++) {
    LEDring_set(1024);
    delay(250);
    LEDring_set(0);
    delay(250);
  }

  // provide a small delay before starting the countdown
  delay(350);
  
  // display a countdown on the seven segment display and flash the led ring
  for(int i = 3; i > 0; i--) {
    sevenSeg_set(i);
    LEDring_set(1024);
    delay(500);
    LEDring_set(0);
    delay(500);
  }
  
  // clear the sign
  sevenSeg_blankAll();
  LEDring_set(0);
}

// idleMode()
//     this function runs a series of animations whilst
//     there is nothing else happening
void idleMode() {

  // create variables for use in the function
  int i = 0;
  int loops = 0;
  bool change = 0;
  
  // display high score on the seven segment display
  sevenSeg_set(highScore);
  
  // display cool patterns on the led ring
  while(!startBtnPressed) {
    
    // if the end of the pattern is reached, increment the loop counter and reset i
    if(i == numOfSegments) {
      i = 0;
      loops++;;
    }

    // choose which pattern to display
    if(change == 1) {
      LEDring_singleSet(pattern_onebyone[i]);
    }
    else {
      LEDring_singleSet(pattern_twobytwo[7-i]);
    }
    i++;
    delay(50);
    
    // check if the pattern needs to be changed or not (5 loops each pattern)
    if(loops >= 5) {
      change = !change;
      loops = 0;
      startBtnPressed = 1;
    }
  }
  return;
}
