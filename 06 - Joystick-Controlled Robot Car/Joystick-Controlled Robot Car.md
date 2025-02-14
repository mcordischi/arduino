# 🚗 Joystick-Controlled Robot Car with Servo & Stepper Motor

In this project, we'll build a **simple robot car** controlled by a **joystick**.  
- **Joystick X-axis** → Controls the **stepper motor** (speed & direction).  
- **Joystick Y-axis** → Moves a **servo motor** (steering or other movement).  
- **Joystick button** → Resets positions.  

---

## 🛠 Components Needed  
- **1x Arduino Uno**  
- **1x Joystick Module**  
- **1x Servo SG90**  
- **1x Stepper Motor 28BYJ-48 + ULN2003 driver**  
- **Wires & Breadboard**  

---

## Arduino IDE Configuration

You will see in the code that it uses a library **AccelStepper.h** that is no supported by default.

To install a new library in the IDE, click on *Tools -> Manage Libraries...*. Search the library and install it.

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

---

## 📜 Arduino Code
```cpp
#include <Servo.h>
#include <AccelStepper.h>

// Servo
Servo servo;
const int SERVO_PIN = 13;

// Stepper
#define MotorInterfaceType 4
AccelStepper stepper(MotorInterfaceType, 4, 6, 5, 7);

void setup() {
    servo.attach(SERVO_PIN);
    servo.write(90); // Initial position

    stepper.setMaxSpeed(1000); 
    stepper.setAcceleration(500);
}

void loop() {
    // Read the current position of the Joystick
    int joystickX = analogRead(A0);
    int joystickY = analogRead(A1);

    // Moves the stepper motor, depending on the X coordinates
    int motorSpeed = map(joystickX, 0, 1023, -500, 500);
    stepper.setSpeed(motorSpeed);
    stepper.runSpeed();

    // Moves the servo, depending on the Y coordinates
    int servoAngle = map(joystickY, 0, 1023, 0, 180);
    servo.write(servoAngle);
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