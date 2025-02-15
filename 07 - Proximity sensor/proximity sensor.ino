#define SENSOR_PIN 2  // Proximity sensor input
#define GREEN_LED 6   // Green LED
#define RED_LED 4     // Red LED
#define BUZZER 7      // Buzzer

void setup() {
    pinMode(SENSOR_PIN, INPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);
    pinMode(BUZZER, OUTPUT);

    Serial.begin(9600);
}

void loop() {
    int proximity = digitalRead(SENSOR_PIN); // Read sensor

    if (proximity == LOW) { // Object detected
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(RED_LED, HIGH);
        digitalWrite(BUZZER, HIGH);
        Serial.println("⚠️ Object too close! 🚨");
    } 
    else { // No object detected
        digitalWrite(GREEN_LED, HIGH);
        digitalWrite(RED_LED, LOW);
        digitalWrite(BUZZER, LOW);
        Serial.println("✅ All clear.");
    }

    delay(100);
}
