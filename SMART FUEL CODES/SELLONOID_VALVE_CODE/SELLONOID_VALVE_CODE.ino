void setup() {
    // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(4, LOW); 
  delay(300000);                       // wait for a second
  digitalWrite(4, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(3, LOW); 
  delay(600000);                       // wait for a second
}
