#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//L298N MOTOR DRIVER pins
#define enA 5
#define in1 2
#define in2 3

//upper switch
const byte switchPin1 = 4;
//variables needed to detect switch press
byte switchState1 = LOW;
byte lastSwitchState1 = LOW;
unsigned long counter1 = 0;              //stores switch press number
unsigned long lastDebounceTime1 = 0;
unsigned long debounceDelay1 = 50;
//variables needed for flashing function
unsigned long lastCounterChangeTime1 = 0;
unsigned long flashingInterval1 = 5000;  // Set the interval for flashing in milliseconds

//dipper switch
const byte switchPin2 = 6;  
byte switchState2 = LOW;
byte lastSwitchState2 = LOW;
unsigned long counter2 = 0;
unsigned long lastDebounceTime2 = 0;
unsigned long debounceDelay2 = 50;
unsigned long lastCounterChangeTime2 = 0;
unsigned long flashingInterval2 = 5000;  

//LCD initialization
LiquidCrystal_I2C lcd(0x27, 16, 2);
//by deafult not flashing
bool isFlashing1 = false;
bool isFlashing2 = false;
unsigned long lastFlashTime1 = 0;
unsigned long lastFlashTime2 = 0;

void setup() {
  lcd.init();
  lcd.setBacklight(255);
  lcd.print("Up : ");
  lcd.setCursor(0, 1);
  lcd.print("Dip: ");
  // Serial.begin(9600);
  /*Using digital pin as INPUT makes arduino connect that pin to a large resistor value so it takes very minimal current,
  hence no risk of pin burning*/
  pinMode(switchPin1, INPUT);
  pinMode(switchPin2, INPUT);
  //motor config
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  // pinMode(button, INPUT);
  // Set initial rotation direction =stopped
  pinMode(in1,LOW);
  pinMode(in2,LOW);
  analogWrite(enA,180);
}

void loop() {
  //motor in anticlockwise direction 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  unsigned long currentMillis = millis();
  //loop to handle flashing 
  if ( ((currentMillis - lastCounterChangeTime1) > flashingInterval1) || ((currentMillis - lastCounterChangeTime2) > flashingInterval2)) {
    if (!isFlashing1 || !isFlashing2) {
      isFlashing1 = true;
      isFlashing2 = true;

      lastFlashTime1 = currentMillis;
      lastFlashTime2 = currentMillis;
      }
    //flashing starts,used millis() to avoid using delay which stops entire processing  
    if ((currentMillis - lastFlashTime1) < 500 || (currentMillis - lastFlashTime2) < 500 ) {
      lcd.setBacklight(255);  // Turn backlight on
    } else if ((currentMillis - lastFlashTime1) < 1000 || (currentMillis - lastFlashTime2) < 1000 ) {
      lcd.setBacklight(0);    // Turn backlight off
    } else {
      lastFlashTime1 = currentMillis;
      lastFlashTime2 = currentMillis;
    }
  }
   
  else {
    isFlashing1 = false;
    isFlashing2 = false;
    lcd.setBacklight(255);  // Turn backlight on
  }
  // Handle switch input and counter 1
  byte reading1 = digitalRead(switchPin1);
  if (reading1 != lastSwitchState1) {
    lastDebounceTime1 = currentMillis;
  }
  if ((currentMillis - lastDebounceTime1) > debounceDelay1) {
    if (reading1 != switchState1) {
      switchState1 = reading1;
      if (switchState1 == HIGH) {
        counter1++;
        lastCounterChangeTime1 = currentMillis;  // Update the time of the last counter change
        // lcd.setCursor(6, 0);  // Position for Counter1
        // lcd.print("      ");  // Clear the area
        lcd.setCursor(6, 0);
        lcd.print(counter1);
      }
  }
  }
  lastSwitchState1 = reading1;

  // Handle switch input and counter 2
  byte reading2 = digitalRead(switchPin2);
  if (reading2 != lastSwitchState2) {
    lastDebounceTime2 = currentMillis;
  }
  if ((currentMillis - lastDebounceTime2) > debounceDelay2) {
    if (reading2 != switchState2) {
      switchState2 = reading2;
      if (switchState2 == HIGH) {
        counter2++;
        lastCounterChangeTime2 = currentMillis;  // Update the time of the last counter change
        lcd.setCursor(6, 1);  // Position for Counter2
        lcd.print("      ");  // Clear the area
        lcd.setCursor(6, 1);
        lcd.print(counter2);
      }
    }
  }
  lastSwitchState2 = reading2;
}
