#ELSOC Design and Development Group
#Bike-Powered Sign Project

The ELSOC Design and Development Group is a collection of students collaboratively working on projects to demonstrate the ablities of Electrical Engineering students at UNSW.

This project is a Bike-Powered Sign, that uses a generator and battery management system to power an EE&T LED display, whilst also providing a display of measurable metrics. It is also able to charge your phone!

##User Guide
Make sure your sketchbook location is set to where your local repo is. Go to File -> Preferences -> Sketchbook Location in the Arduino IDE to change your sketchbook location.

##Repository Contents
sketches/ contains all Arduino sketches for testing and running
libraries/ contains all .h files and .cpp files for declaring functions and constants

##Change Log
See the change log at the top of each file to see the changes made to each specific file.

##To-Do List
- [ ] Interfaces:
	- [x] Seven Segment display (3 digits)
	- [x] LED ring (16 segments)
	- [x] Start button interrupt
	- [ ] Mode select button interrupt
	- [ ] LED indicator lights for bike display (mode in use)

- [ ] Modes:
	- [x] Start sequence countdown
	- [x] Idle mode
	- [ ] Free-run mode
	- [x] Competition mode
	- [ ] Implement dual mode system

- [ ] Free-Run Mode:
	- [ ] Implement start on first button press (with start sequence)
	- [ ] Implement end on second button press (with end sequence?)
	- [ ] Display peak score whilst riding
	- [ ] Update LEDring based on sampled score (~100ms)

- [x] Competition Mode:
	- [x] Implement start on button press (with start sequence)
	- [x] Display final score (average over 30 seconds)
	- [x] Update LEDring based on sampled score (~100ms)

- [ ] Other:
	- [ ] Store high score in EEPROM for data retention
