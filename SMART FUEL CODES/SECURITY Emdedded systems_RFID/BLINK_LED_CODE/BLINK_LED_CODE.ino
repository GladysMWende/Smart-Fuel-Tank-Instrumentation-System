void setup() {
    // initialize digital pin LED_BUILTIN as an output.
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(6, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(6, HIGH);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
