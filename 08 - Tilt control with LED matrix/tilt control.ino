#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include <LedControl.h>

// Initialize ADXL345 Accelerometer
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();

// Initialize LED Matrix (DIN=11, CLK=13, CS=10)
LedControl matrix = LedControl(11, 13, 10, 1);

void setup() {
    Serial.begin(9600);

    // Initialize accelerometer
    if (!accel.begin()) {
        Serial.println("ADXL345 not detected.");
        while (1);
    }

    // Set accelerometer range to ±2G
    accel.setRange(ADXL345_RANGE_2_G);

    // Initialize LED Matrix
    matrix.shutdown(0, false); // Turn on the matrix
    matrix.setIntensity(0, 8); // Set brightness (0-15)
    matrix.clearDisplay(0);    // Clear the matrix
}

void loop() {
    sensors_event_t event;
    accel.getEvent(&event);

    // Convert acceleration to LED matrix coordinates
    int x = map(event.acceleration.x, -10, 10, 0, 7);
    int y = map(event.acceleration.y, -10, 10, 0, 7);

    // Clear previous LED position and update with new one
    matrix.clearDisplay(0);
    matrix.setLed(0, y, x, true);

    delay(100);
}