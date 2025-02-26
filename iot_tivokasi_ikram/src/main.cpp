#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);


#define RED_PIN 2
#define YELLOW_PIN 3
#define GREEN_PIN 4

void setup() {
    Wire.begin(42, 39);  
    lcd.init();
    lcd.backlight();
    
    pinMode(RED_PIN, OUTPUT);
    pinMode(YELLOW_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
}

void loop() {
    
    lcd.setCursor(5, 0);
    lcd.print("STOP!");
    digitalWrite(RED_PIN, HIGH);
    delay(30000);
    digitalWrite(RED_PIN, LOW);
    lcd.clear();

    
    lcd.setCursor(1, 0);
    lcd.print("Prepare to go!");
    digitalWrite(YELLOW_PIN, HIGH);
    delay(5000);
    digitalWrite(YELLOW_PIN, LOW);
    lcd.clear();

    
    lcd.setCursor(6, 0);
    lcd.print("GO!");
    digitalWrite(GREEN_PIN, HIGH);
    delay(20000);
    digitalWrite(GREEN_PIN, LOW);
    
    
    for (int i = 0; i < 3; i++) {
        delay(500);
        digitalWrite(GREEN_PIN, HIGH);
        delay(500);
        digitalWrite(GREEN_PIN, LOW);
    }
    lcd.clear();

    
    lcd.setCursor(0, 0);
    lcd.print("Prepare to stop!");
    digitalWrite(YELLOW_PIN, HIGH);
    delay(20000);
    digitalWrite(YELLOW_PIN, LOW);
    lcd.clear();
}
