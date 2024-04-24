#include <LiquidCrystal_I2C.h>

const int buzzerPin = 13;
const int LCD_ADDR = 0x27; // Replace with your I2C address

LiquidCrystal_I2C lcd(LCD_ADDR, 16, 2);

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  lcd.begin();
  lcd.backlight();
}

void loop() {
  while(Serial.available() > 0) {
    char command = Serial.read();
    if (command == 'F') {
      tone(buzzerPin, 1000);
      delay(500);
      noTone(buzzerPin);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Fall Detected");
    } else if (command == 'W') {
      // Stop the buzzer if 'W' command is received
      noTone(buzzerPin);
      lcd.clear();
      lcd.print("Done");
    }
  }
}