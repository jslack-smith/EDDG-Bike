/*  mode_functions.h
 *   
 *   This file contains all function prototypes and constant definitions for the different modes.
 *   
 *   Change Log: 
 *      
 *      17th September 2015 (JL)
 *          - added chargingMode
 *          - added extern variable for mode button
 *
 *      28th August 2015 (JL)
 *          - clean up
 *          - added idleMode
 *          - created extern variables
 *          
 *      25th August 2015 (JSS)
 *          - created file
 */

#ifndef MODE_FUNCTIONS_H
#define MODE_FUNCTIONS_H

// include all necessary local header files
#include "pin_definitions.h"
#include "LEDring_functions.h"

/***********************************
 *            Constants            *
 ***********************************/


/***********************************
 *            Variables            *
 ***********************************/
extern int highScore;
volatile extern bool startBtnPressed;
volatile extern bool modeBtnPressed;

/***********************************
 *       Function Prototypes       *
 ***********************************/
void startSequence();
void idleMode();
void chargingMode();

#endif
