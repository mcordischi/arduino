# 🎮 Tilt Control with ADXL345 and LED Matrix (MAX7219)

## 📝 Introduction
In this project, we will use an **ADXL345 accelerometer** to detect tilt and control a **LED matrix (8x8 MAX7219)**. The LED matrix will display a dot that moves in the direction of the tilt.  

This project is great for learning about sensors, movement detection, and visualization! 🎯  

---

## 🛠 Materials
- **Arduino Uno**  
- **ADXL345 Accelerometer (I2C Mode)**  
- **8x8 LED Matrix (MAX7219 Controller)**  
- **Jumper wires**  

---

## 📌 Wiring

### **ADXL345 to Arduino (I2C Mode)**
| ADXL345 Pin | Arduino Pin |
|------------|------------|
| VCC        | 5V         |
| GND        | GND        |
| SDA        | A4         |
| SCL        | A5         |
| CS         | 3.3V (to enable I2C mode) |
| SDO        | GND        |

### **LED Matrix (MAX7219) to Arduino**
| MAX7219 Pin | Arduino Pin |
|------------|------------|
| VCC        | 5V         |
| GND        | GND        |
| DIN        | 11         |
| CS         | 10         |
| CLK        | 13         |

---

## 📦 Required Libraries
Before uploading the code, install these two libraries from the **Arduino Library Manager**:  

1️⃣ **Adafruit ADXL345** (for the accelerometer)  
   - Search: `Adafruit ADXL345`  
   - Author: `Adafruit`  

2️⃣ **LedControl** (for the LED matrix)  
   - Search: `LedControl`  
   - Author: `Eberhard Fahle`  

To install them:  
1. Open **Arduino IDE**  
2. Go to **Tools** > **Manage Libraries**  
3. Search for the libraries and click **Install**  

---

## 🔍 Code Explanation
The code reads tilt values from the **ADXL345 accelerometer**, maps them to coordinates (X and Y), and updates the LED matrix to move the dot accordingly.  

### **Arduino Code**
```cpp
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
```

## 🕹 How It Works

* The ADXL345 accelerometer detects tilt in X and Y axes.
* The Arduino converts the tilt into LED matrix coordinates.
* A dot appears in the matrix representing the inclination.
* Tilting right → moves the dot right.
* Tilting forward → moves the dot down.


## 🔧 Possible Improvements

💡 Limit the movement to prevent the dot from going off-screen
💡 Adjust the sensitivity using map() values
💡 Use different color LEDs if your matrix supports RGB
💡 Make a game, like a maze or obstacle avoidance