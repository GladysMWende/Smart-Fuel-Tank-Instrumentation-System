     
     
       // defines pins numbers

const int trigPin = 10; // pin on the arduinowhere the trigger pin is connected
const int echoPin = 9;// pin on the arduino where the echo pin is connected
const int LEDPin1 = 3;// pin on the arduino where the LED pin1 is connected
const int LEDPin2 = 2;// pin on the arduino where the LED pin2 is connected

// defines variables
long duration; // variable where the the reflection time of the ultrasound is stored
int distance; // variable where the distance of the measured object is stored


#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x20 for a 16 chars and 2 line display

void setup()
{
  // lcd
  lcd.init();
  lcd.clear();         

  lcd.backlight();      // Make sure backlight is on

  //ultrasonic
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    pinMode(3, OUTPUT); // initialize digital pin1 LED_BUILTIN as an output.
    pinMode(2, OUTPUT); // initialize digital pin2 LED_BUILTIN as an output.
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

 if (distance < 300)
 {
 digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)    ||AIR
 digitalWrite(2, LOW);   // turn the LED on (HIGH is the voltage level)     ||FUEL
 }
 
 else 
 {
 digitalWrite(3, LOW);    // turn the LED off by making the voltage LOW  ||AIR
 digitalWrite(2, HIGH);    // turn the LED off by making the voltage LOW   || FUEL
 }
 
// Prints the level on the LCD and Virtual terminal/ serial monitor

  lcd.setCursor(2,0);   //Set cursor to character 2 on line 0
  lcd.print("LEVEL IN cm: ");
   delay (100);

  lcd.setCursor(2,1);   //Move cursor to character 2 on line 1
  lcd.print(distance);


  // Prints the level on the Serial Monitor
  Serial.print("...UPLOADED LEVEL IN CLOUD:");
  Serial.println(distance);
  delay (100);
  
 }
