#include <Servo.h>
#include <LiquidCrystal.h>

// Initialize LCD with pin configuration
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

Servo servo;
const int LDR_PIN = A0;
const int LED_PIN = 7;
const int SERVO_PIN = 9;

void setup() {
    pinMode(LDR_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    servo.attach(SERVO_PIN);
    
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("Light Level:");
    
    servo.write(0);  // Initial servo position
}

void loop() {
    int lightValue = analogRead(LDR_PIN);
    int lightPercent = map(lightValue, 0, 1023, 0, 100);

    lcd.setCursor(0, 1);
    lcd.print("     "); // Clear previous value
    lcd.setCursor(0, 1);
    lcd.print(lightPercent);
    lcd.print("% ");

    if (lightPercent < 30) { // If light is low
        digitalWrite(LED_PIN, HIGH);
        servo.write(90); // Open curtain
    } else {
        digitalWrite(LED_PIN, LOW);
        servo.write(0); // Close curtain
    }

    delay(500);
}