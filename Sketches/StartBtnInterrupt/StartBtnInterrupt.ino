// Start button interrupt

void setup() {
  
}

void loop() {
  
}


// from http://forum.arduino.cc/index.php?topic=45000.0
void startBtnInterrupt_handler()
{
 static unsigned long last_interrupt_time = 0;
 unsigned long interrupt_time = millis(); // could overflow be a problem?
 // If interrupts come faster than 200ms, assume it's a bounce and ignore
 if (interrupt_time - last_interrupt_time > 200) 
 {
   startBtnPressed = true;
 }
 last_interrupt_time = interrupt_time;
}
