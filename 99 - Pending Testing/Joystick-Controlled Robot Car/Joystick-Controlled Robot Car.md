# 🚗 Joystick-Controlled Robot Car with Servo & Stepper Motor

In this project, we'll build a **simple robot car** controlled by a **joystick**.  
- **Joystick X-axis** → Controls the **stepper motor** (speed & direction).  
- **Joystick Y-axis** → Moves a **servo motor** (steering or other movement).  
- **Joystick button** → Resets positions.  
- **LCD Display** → Shows **servo angle & motor speed**.  

---

## 🛠 Components Needed  
- **1x Arduino Uno**  
- **1x Joystick Module**  
- **1x Servo SG90**  
- **1x Stepper Motor 28BYJ-48 + ULN2003 driver**  
- **1x 16x2 LCD Display**  
- **1x 10KΩ Potentiometer** (for LCD contrast)  
- **Wires & Breadboard**  

---

## 🔌 Wiring  
### **1️⃣ Joystick**
| Joystick Pin | Arduino Pin |
|-------------|------------|
| **VCC** | 5V |
| **GND** | GND |
| **VRX** | A0 |
| **VRY** | A1 |
| **SW**  | 8 |

### **2️⃣ Servo SG90**
| Servo Cable | Arduino Pin |
|------------|------------|
| **Signal (orange)** | 13 |
| **VCC (red)** | 5V |
| **GND (brown)** | GND |

### **3️⃣ Stepper Motor (28BYJ-48 with ULN2003)**
| ULN2003 Pin | Arduino Pin |
|------------|------------|
| **IN1** | 4 |
| **IN2** | 5 |
| **IN3** | 6 |
| **IN4** | 7 |
| **VCC** | 5V |
| **GND** | GND |

### **4️⃣ LCD 16x2**
| LCD Pin | Arduino Pin |
|---------|------------|
| **GND** | GND |
| **VDD** | 5V |
| **VO**  | Middle pin of **10KΩ potentiometer** |
| **RS**  | 12 |
| **RW**  | GND |
| **E**   | 11 |
| **D4**  | 10 |
| **D5**  | 9 |
| **D6**  | 3 |
| **D7**  | 2 |
| **BLA** | 5V |
| **BLK** | GND |

---

## 📜 Arduino Code  
```cpp
#include <Servo.h>
#include <Stepper.h>
#include <LiquidCrystal.h>

// LCD setup
LiquidCrystal lcd(12, 11, 10, 9, 3, 2);

// Stepper motor setup
const int stepsPerRevolution = 2048;
Stepper stepper(stepsPerRevolution, 4, 6, 5, 7);

// Servo setup
Servo servo;

// Joystick pins
const int VRX_PIN = A0;
const int VRY_PIN = A1;
const int SW_PIN  = 8; // Joystick button

// Variables for joystick values
int xValue = 0;
int yValue = 0;
int buttonState = HIGH;

int servoAngle = 90; // Initial servo position
int motorSpeed = 0;  // Stepper speed

void setup() {
    pinMode(SW_PIN, INPUT_PULLUP);
    servo.attach(13);
    stepper.setSpeed(0);

    lcd.begin(16, 2);
    lcd.print("Servo: ");
    lcd.setCursor(0, 1);
    lcd.print("Motor: ");

    servo.write(servoAngle);
}

void loop() {
    xValue = analogRead(VRX_PIN);
    yValue = analogRead(VRY_PIN);
    buttonState = digitalRead(SW_PIN);

    // Map joystick X to motor speed
    motorSpeed = map(xValue, 0, 1023, -10, 10);
    stepper.setSpeed(abs(motorSpeed));
    
    if (motorSpeed > 0) {
        stepper.step(stepsPerRevolution / 100);
    } else if (motorSpeed < 0) {
        stepper.step(-stepsPerRevolution / 100);
    }

    // Map joystick Y to servo angle
    int newAngle = map(yValue, 0, 1023, 0, 180);
    
    if (newAngle != servoAngle) {
        servoAngle = newAngle;
        servo.write(servoAngle);
    }

    // Display on LCD
    lcd.setCursor(7, 0);
    lcd.print("    ");
    lcd.setCursor(7, 0);
    lcd.print(servoAngle);
    lcd.print("°");

    lcd.setCursor(7, 1);
    lcd.print("    ");
    lcd.setCursor(7, 1);
    lcd.print(abs(motorSpeed));
    lcd.print(" RPM");

    // Reset positions if joystick button is pressed
    if (buttonState == LOW) {
        servoAngle = 90;
        servo.write(servoAngle);
        stepper.setSpeed(0);
    }

    delay(100);
}
```


## 🔍 Understanding the Code

    Reads joystick values (X and Y).
    Moves the stepper motor based on the X-axis:
        Left ➝ Rotates one way
        Right ➝ Rotates the other way
        Center ➝ Stops
    Controls the servo based on the Y-axis.
        Up ➝ Increases angle
        Down ➝ Decreases angle
    Displays motor speed & servo angle on LCD.
    Joystick button resets everything to initial state.

## 🚀 Expanding the Project: Car Automation Ideas

Once you have a working car, here are 5 automation ideas:

    Obstacle Avoidance → Add an ultrasonic sensor to detect objects and stop or turn.
    Remote Control → Use an infrared remote to drive instead of the joystick.
    Line Following → Add IR sensors so the car follows a line on the floor.
    Speed Control → Adjust speed using a potentiometer or a second joystick.
    Sound Activation → Start moving when a microphone detects a clap.

## 🌱 Recycled Materials for the Car

You can build the car's body using recycled materials! Here are some ideas:
### Body Structure

    Cardboard (cut pieces from boxes)
    Ice cream sticks (to make a strong frame)
    Plastic bottles (cut and shape for lightweight parts)

### Wheels & Axles

    Bottle caps (for wheels)
    CDs or old DVDs (for larger wheels)
    Pencils or straws (for axles)
    Skewers or toothpicks (to attach wheels)

### Mobile Axle Solution

    Use a straw as a guide for an axle (pencil or skewer).
    Attach wheels with hot glue or tape but allow them to spin.
    If possible, mount the front axle on a rotating base (like a bottle cap with a hole).

## 🎯 Final Challenge: Make it Your Own!

    Decorate your car with colors or stickers.
    Improve stability by adjusting the wheel alignment.
    Try different terrains (smooth table, rough floor, etc.).
    Modify movement logic (e.g., joystick Y could control acceleration).

💡 Have fun experimenting and making your car unique! 🚀