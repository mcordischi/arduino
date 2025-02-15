# 🚦 Proximity Traffic Light with Arduino

## 🏗 Project Overview  
In this project, we will create a **proximity-based traffic light** using an **infrared proximity sensor, LEDs, and a buzzer**. When an object gets too close, the **red LED** will turn on, and the **buzzer will sound an alarm**. If the area is clear, the **green LED** will turn on.  

## 🔧 Materials Needed  
- **Arduino Uno**  
- **Infrared Proximity Sensor**  
- **1 Red LED** (🔴)  
- **1 Green LED** (🟢)  
- **1 Buzzer**  
- **2 Resistors (220Ω)** (for LEDs)  
- **Breadboard & Jumper Wires**  

---

## 📌 How to Connect the Components  

### 🔹 Infrared Proximity Sensor  
The **proximity sensor** detects when an object is near. It has **three pins**:  

| Sensor Pin | Connects to |
|------------|------------|
| **VCC**  | **5V** on Arduino |
| **GND**  | **GND** on Arduino |
| **OUT**  | **Pin 2** on Arduino |

---

### 🔹 LEDs and Resistors  
LEDs **must always be connected with a resistor** to avoid burning them out. We use **220Ω resistors** to limit the electrical current.  

| LED  | Arduino Pin | Resistor |
|------|------------|------------|
| **Green (🟢)** | **Pin 6** | **220Ω** |
| **Red (🔴)** | **Pin 4** | **220Ω** |

#### **How to Connect an LED with a Resistor:**  
- **Long leg (+) (Anode)** → Connect to **one side of the resistor**  
- **Other side of the resistor** → Connect to the **Arduino pin**  
- **Short leg (-) (Cathode)** → Connect to **GND**  

---

### 🔹 Buzzer  
The buzzer makes a sound when the **red LED is on** (danger detected).  

| Buzzer Pin | Connects to |
|------------|------------|
| **+ (Positive)** | **Pin 7** on Arduino |
| **- (Negative)** | **GND** on Arduino |

---

## 📝 Arduino Code  

```cpp
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
```


## 🔍 How the Code Works?

    The infrared sensor detects if an object is close.
    If something is too close:
        Red LED turns on (⚠️ Warning)
        Buzzer makes a sound
    If there’s nothing close:
        Green LED turns on (✅ Safe zone)
        Buzzer stays off
    The status is also printed in the Serial Monitor.

## 🎯 Extra Challenges

🔹 Try different distances: Place your hand at different distances and see how the system reacts.
🔹 Change the buzzer sound: Use the tone() function to make different alarm sounds.
🔹 Use an LCD Display: Show the status ("SAFE" or "DANGER") on a screen.

🚀 Now you have a working proximity-based traffic light! 🚦🔴🟢