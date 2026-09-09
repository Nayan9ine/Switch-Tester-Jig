#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//L298N MOTOR DRIVER pins
#define enA 5
#define in1 2
#define in2 3

//upper switch
const int switchPin1 = 4;
int switchState1 = LOW;
int lastSwitchState1 = LOW;
unsigned long counter1 = 0;
unsigned long lastDebounceTime1 = 0;
unsigned long debounceDelay1 = 50;
unsigned long lastCounterChangeTime1 = 0;
unsigned long flashingInterval1 = 5000;  // Set the interval for flashing in milliseconds

//dipper switch
const int switchPin2 = 6;  
int switchState2 = LOW;
int lastSwitchState2 = LOW;
unsigned long counter2 = 0;
unsigned long lastDebounceTime2 = 0;
unsigned long debounceDelay2 = 50;
unsigned long lastCounterChangeTime2 = 0;
unsigned long flashingInterval2 = 5000;  // Set the interval for flashing in milliseconds

//LCD initialization
LiquidCrystal_I2C lcd(0x27, 16, 2);
bool isFlashing1 = false;
bool isFlashing2 = false;
unsigned long lastFlashTime1 = 0;
unsigned long lastFlashTime2 = 0;
// bool backlightState = true;

void setup() {
  lcd.init();
  lcd.setBacklight(255);
  lcd.print("Up : ");
  lcd.setCursor(0, 1);
  lcd.print("Dip: ");
  // Serial.begin(9600);
  pinMode(switchPin1, INPUT);
  pinMode(switchPin2, INPUT);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  // pinMode(button, INPUT);
  // Set initial rotation direction
  pinMode(in1, LOW);
  pinMode(in2,LOW);
  analogWrite(enA,230);
}

void loop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  unsigned long currentMillis = millis();

  // Handle flashing for counter 1
  if ((currentMillis - lastCounterChangeTime1) > flashingInterval1) {
    if (!isFlashing1) {
      isFlashing1 = true;
      lastFlashTime1 = currentMillis;
    }
    if ((currentMillis - lastFlashTime1) < 500) {
      lcd.setBacklight(255);  // Turn backlight on
    } else if ((currentMillis - lastFlashTime1) < 1000) {
      lcd.setBacklight(0);    // Turn backlight off
    } else {
      lastFlashTime1 = currentMillis;
    }
  } else {
    isFlashing1 = false;
    lcd.setBacklight(255);  // Turn backlight on
  }

  // Handle flashing for counter 2
  if ((currentMillis - lastCounterChangeTime2) > flashingInterval2) {
    if (!isFlashing2) {
      isFlashing2 = true;
      lastFlashTime2 = currentMillis;
    }
    if ((currentMillis - lastFlashTime2) < 500) {
      lcd.setBacklight(255);  // Turn backlight on
    } else if ((currentMillis - lastFlashTime2) < 1000) {
      lcd.setBacklight(0);    // Turn backlight off
    } else {
      lastFlashTime2 = currentMillis;
    }
  } else {
    isFlashing2 = false;
    lcd.setBacklight(255);  // Turn backlight on
  }

  // Handle switch input and counter 1
  int reading1 = digitalRead(switchPin1);
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
  int reading2 = digitalRead(switchPin2);
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
