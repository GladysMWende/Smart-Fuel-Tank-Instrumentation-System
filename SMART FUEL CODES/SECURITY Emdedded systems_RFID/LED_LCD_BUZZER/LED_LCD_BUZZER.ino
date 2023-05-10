const int buzzer = 8; //buzzer to arduino pin 9
#include <LiquidCrystal_I2C.h>

#include <SPI.h>
#include <MFRC522.h>
#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x20 for a 16 chars and 2 line display

void setup()
{
 
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  
  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on

  Serial.begin(9600);    // Initialize serial communications with the PC
  while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
  
}

void loop() {
 // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
     noTone(buzzer);     // Stop sound...
      delay(1000);
     digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
     delay(1000);        // ...for 1sec
   lcd.setCursor(2,0);   //Set cursor to character 2 on line 0
   lcd.print("GROUP 5");
   lcd.setCursor(2,1);   //Move cursor to character 2 on line 1
   lcd.print("AUTHORISED");
  // lcd.clear(); 
  }
  else
  {
    digitalWrite(6, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(1000);        // ...for 1sec
       tone(buzzer, 1000); // Send 1KHz sound signal...
       delay(1000);
       lcd.setCursor(2,0);   //Set cursor to character 2 on line 0
   lcd.print("GROUP 5");
   lcd.setCursor(2,1);   //Move cursor to character 2 on line 1
   lcd.print("INTRUDER");
   //lcd.clear(); 
  }
    return;
    // Dump debug info about the card; PICC_HaltA() is automatically called
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
  }

  
