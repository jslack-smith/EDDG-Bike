/*  Pin_Definitions.h
 *   
 *   This file contains all pin definitions for the ELSOC Design and Development Group Bike. 
 *   
 *   Change Log: 
 *      27th August 2015 (JL) 
 *          - clean up
 *          
 *      21st August 2015 (JSS)
 *          - clean up
 *          - add 'sensorPin' for testing purposes
 *          
 *      16th August 2015 (JSS)
 *          - created file with initial definitions
 */

#ifndef PIN_DEFINTIONS_H
#define PIN_DEFINITIONS_H

/***********************************
 *   LED Ring - Shift Registers    *
 ***********************************/
#define ring_dataPin    11
#define ring_clkPin     12
#define ring_latchPin   8

/***********************************
 *      Seven Segment Display      *
 ***********************************/

// blanking pins
#define BLpin0          7
#define BLpin1          1
#define BLpin2          1

// 
#define ABCDpin0        10
#define ABCDpin1        3
#define ABCDpin2        4
#define ABCDpin3        5


#define LDpin0          6
#define LDpin1          1
#define LDpin2          1

/***********************************
 *             Sensor              *
 ***********************************/
#define sensorPin       A0

/***********************************
 *              Button             *
 ***********************************/
#define startBtnInt     0

#endif
