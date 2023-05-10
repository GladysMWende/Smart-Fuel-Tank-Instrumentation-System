// defines pins numbers

const int trigPin = 10; // pin on the arduinowhere the trigger pin is connected
const int echoPin = 9;// pin on the arduino where the echo pin is connected
const int LEDPin1 = 13;// pin on the arduino where the LED pin1 is connected

// defines variables
long duration; // variable where the the reflection time of the ultrasound is stored
int distance; // variable where the distance of the measured object is stored


#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20,16,2);  // set the LCD address to 0x20 for a 16 chars and 2 line display

void setup()
{
  // lcd
  lcd.init();
  lcd.clear();         

  lcd.backlight();      // Make sure backlight is on

  //ultrasonic
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    pinMode(13, OUTPUT); // initialize digital pin1 LED_BUILTIN as an output.
   // pinMode(6, OUTPUT); // initialize digital pin2 LED_BUILTIN as an output.
    Serial.begin(9600); // Starts the serial communication
  
}

    void loop()
 {
// Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
     
     // Sets the trigPin on HIGH state for 10 micro seconds
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
     digitalWrite(trigPin, LOW);
     
// Reads the echoPin, returns the sound wave travel time in microseconds
   duration = pulseIn(echoPin, HIGH);
   
// Calculating the distance
distance= duration*0.034/2;

 if (distance < 400)
 {
 digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)    ||AIR
 }
 
 else if (distance > 400)
 {
 digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW  ||AIR
 
// Prints the level on the LCD and Virtual terminal/ serial monitor

  lcd.setCursor(2,0);   //Set cursor to character 2 on line 0
  lcd.print("LEVEL: ");

  lcd.setCursor(2,1);   //Move cursor to character 2 on line 1
  lcd.print(distance);


  // Prints the level on the Serial Monitor
  Serial.print("LEVEL IN cm: ");
  Serial.println(distance);
  delay (100);
 }
 }
 
 
