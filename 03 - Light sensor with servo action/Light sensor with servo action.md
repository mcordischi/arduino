# Light Sensor with LCD and Servo Motor

## Project Overview
This project uses a **light-dependent resistor (LDR)** to measure ambient light levels and display the percentage on a **16x2 LCD screen**. If the light level is too low, a **LED indicator** turns on and a **servo motor** moves (simulating the opening of a window or curtain).

## Components Required
- **1x Arduino Uno**
- **1x 16x2 LCD Display (without I2C adapter)**
- **1x 10KΩ Potentiometer** (for LCD contrast)
- **1x Photoresistor (LDR)**
- **1x 10KΩ Resistor** (for the LDR voltage divider)
- **1x LED** (indicator light)
- **1x 220Ω Resistor** (for the LED)
- **1x SG90 Servo Motor**
- **Jumper wires and a breadboard**

---

## Wiring the LCD (Parallel Mode - No I2C Adapter)
| LCD Pin | Connection |
|---------|------------|
| **GND** | GND (Arduino) |
| **VDD** | 5V (Arduino) |
| **VO**  | Center of the 10KΩ potentiometer |
| **RS**  | Arduino **Pin 12** |
| **RW**  | GND (Always in Write Mode) |
| **E**   | Arduino **Pin 11** |
| **D4**  | Arduino **Pin 5** |
| **D5**  | Arduino **Pin 4** |
| **D6**  | Arduino **Pin 3** |
| **D7**  | Arduino **Pin 2** |
| **BLA** | 5V (Backlight Power) |
| **BLK** | GND (Backlight Ground) |

#### Other Connections
- **LDR**: One pin to **5V**, the other to **A0** and **GND via 10KΩ resistor**
- **LED**: Anode (+) to **Pin 7** (with **220Ω resistor**), cathode (-) to **GND**
- **Servo**: Signal (Orange) to **Pin 9**, VCC (Red) to **5V**, GND (Brown) to **GND**

---

## Code (Without I2C Adapter)
```cpp
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
```

---

## Using the I2C Adapter (Simpler Wiring)
If your LCD has an **I2C adapter**, you can reduce the number of connections and free up Arduino pins.

### **I2C Wiring**
| LCD Pin | Connection |
|---------|------------|
| **VCC** | 5V (Arduino) |
| **GND** | GND (Arduino) |
| **SDA** | **A4** (Arduino) |
| **SCL** | **A5** (Arduino) |

### **Code for I2C Adapter**
```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Change 0x27 to 0x3F if necessary
Servo servo;
const int LDR_PIN = A0;
const int LED_PIN = 7;
const int SERVO_PIN = 9;

void setup() {
    pinMode(LDR_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    servo.attach(SERVO_PIN);
    
    lcd.begin(16, 2);
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Light Level:");
    
    servo.write(0);
}

void loop() {
    int lightValue = analogRead(LDR_PIN);
    int lightPercent = map(lightValue, 0, 1023, 0, 100);

    lcd.setCursor(0, 1);
    lcd.print("     ");
    lcd.setCursor(0, 1);
    lcd.print(lightPercent);
    lcd.print("% ");

    if (lightPercent < 30) {
        digitalWrite(LED_PIN, HIGH);
        servo.write(90);
    } else {
        digitalWrite(LED_PIN, LOW);
        servo.write(0);
    }

    delay(500);
}
```

---

## **Code Customization**
- **Change Light Threshold**: Modify `if (lightPercent < 30)` to adjust sensitivity.
- **Adjust Servo Angle**: Change `servo.write(90)` for a different movement.
- **LCD Contrast**: Turn the 10KΩ potentiometer.
- **I2C Address Change**: Some LCDs use `0x3F` instead of `0x27`. Try both.

---

🎉 **Now you can build your own light-sensitive automated system!** 🚀
