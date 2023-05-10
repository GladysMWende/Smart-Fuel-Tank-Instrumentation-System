const int buzzer = 9; //buzzer to arduino pin 9


void setup(){
 
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);

}

void loop(){
 
  tone(buzzer, 1000); // Send 1KHz sound signal...
   digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(6, HIGH);   // turn the LED on (HIGH is the voltage level
  delay(1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(6, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);        // ...for 1sec  
}
