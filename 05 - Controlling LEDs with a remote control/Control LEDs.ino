#include <IRremote.h>
#include <LiquidCrystal.h>

const int IR_RECEIVER_PIN = 2;
const int BUZZER_PIN = 3;
const int LED_1 = 4;
const int LED_2 = 5;
const int LED_3 = 6;

IRrecv irrecv(IR_RECEIVER_PIN);
decode_results results;

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
    Serial.begin(9600);
    irrecv.enableIRIn();  // Start the IR receiver
    
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);
    pinMode(LED_3, OUTPUT);

    lcd.begin(16, 2);
    lcd.print("Waiting...");
}

void loop() {
    if (irrecv.decode(&results)) {
        Serial.println(results.value, HEX); // Print button code in HEX
        
        lcd.clear();
        lcd.print("Btn: ");
        lcd.print(results.value, HEX);

        // 🚨 Challenge: These button codes are WRONG! Fix them below! 🚨
        if (results.value == 0xFF10AF) {  // Should be 0xFF30CF
            digitalWrite(LED_1, !digitalRead(LED_1));
        }
        if (results.value == 0xFF20BF) {  // Should be 0xFF18E7
            digitalWrite(LED_2, !digitalRead(LED_2));
        }
        if (results.value == 0xFF40DF) {  // Should be 0xFF7A85
            digitalWrite(LED_3, !digitalRead(LED_3));
        }
        if (results.value == 0xFFA25D) {  // Power button (turn buzzer ON for 0.5s)
            digitalWrite(BUZZER_PIN, HIGH);
            delay(500);
            digitalWrite(BUZZER_PIN, LOW);
        }

        irrecv.resume();  // Receive next signal
    }
}