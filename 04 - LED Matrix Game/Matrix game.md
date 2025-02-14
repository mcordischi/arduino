# 🎮 LED Matrix Reaction Game with Score Display

## 📌 Project Overview  
In this project, we'll create a **reaction-based game** using:  
- **An 8x8 LED Matrix** to display random light-up areas.  
- **A 4x4 Button Matrix** to detect player responses.  
- **A 4-digit 7-segment display** to show the player's score and remaining time.  

The player has **20 seconds** to press the correct button corresponding to the lit-up section on the LED matrix. Each correct press increases the score!  

---

## 🛠 Components Needed  
- 1x **Arduino Uno**  
- 1x **8x8 LED Matrix** (with MAX7219 controller)  
- 1x **4x4 Button Matrix**  
- 1x **4-Digit 7-Segment Display (TM1637)**  
- **Jumper Wires**  
- 1x **Breadboard**  

---

## 🔌 Wiring Diagram  

### 📌 **1️⃣ LED Matrix (MAX7219 Controller)**
| LED Matrix Pin | Connect to: |
|---------------|-------------|
| **VCC**       | 5V (Arduino) |
| **GND**       | GND (Arduino) |
| **DIN**       | **Pin 11** |
| **CS**        | **Pin 10** |
| **CLK**       | **Pin 9** |

### 📌 **2️⃣ 4x4 Button Matrix**
| Button Matrix Row | Connect to: |
|------------------|-------------|
| **Row 1** | **Pin 3** |
| **Row 2** | **Pin 4** |
| **Row 3** | **Pin 5** |
| **Row 4** | **Pin 6** |

| Button Matrix Column | Connect to: |
|---------------------|-------------|
| **Column 1** | **Pin A0** |
| **Column 2** | **Pin A1** |
| **Column 3** | **Pin A2** |
| **Column 4** | **Pin A3** |

### 📌 **3️⃣ 4-Digit 7-Segment Display (TM1637)**
| Display Pin | Connect to: |
|------------|-------------|
| **VCC**    | 5V (Arduino) |
| **GND**    | GND (Arduino) |
| **CLK**    | **Pin 7** |
| **DIO**    | **Pin 8** |

---

## 📥 Installing Required Libraries  

To make the LED matrix and display work, install the following libraries:  
1️⃣ **"LedControl"** (for MAX7219 LED matrix)  
2️⃣ **"TM1637"** (for 4-digit 7-segment display)  

📌 **Installation Steps:**  
- Open **Arduino IDE** → **Sketch** → **Include Library** → **Manage Libraries...**  
- Search for **"LedControl"** and **"TM1637"**  
- Click **Install**  

---

## 🖥 The Code  

```cpp
#include <LedControl.h>
#include <TM1637Display.h>

// LED Matrix (MAX7219)
LedControl lc = LedControl(11, 9, 10, 1); 

// 4-Digit Display (TM1637)
#define CLK 7
#define DIO 8
TM1637Display display(CLK, DIO);

// Button Matrix Setup
const int rowPins[4] = {3, 4, 5, 6};
const int colPins[4] = {A0, A1, A2, A3};

// Game variables
int score = 0;
int timeLeft = 20;  // 20 seconds to play
int activeX, activeY; // Active LED position

void setup() {
    Serial.begin(9600);

    // Initialize LED matrix
    lc.shutdown(0, false);
    lc.setIntensity(0, 8);
    lc.clearDisplay(0);

    // Initialize button matrix
    for (int i = 0; i < 4; i++) {
        pinMode(rowPins[i], OUTPUT);
        digitalWrite(rowPins[i], HIGH);
        pinMode(colPins[i], INPUT_PULLUP);
    }

    // Initialize display
    display.setBrightness(5);
    display.showNumberDecEx(timeLeft, 0b01000000, true);
    
    // Start first round
    newTarget();
}

void loop() {
    if (timeLeft > 0) {
        checkButtons();
        delay(200);
    } else {
        display.showNumberDec(score); // Show final score
    }
}

// Pick a new random LED position
void newTarget() {
    lc.clearDisplay(0);
    activeX = random(0, 4);
    activeY = random(0, 4);

    lc.setLed(0, activeX, activeY, true);
}

// Check if player pressed correct button
void checkButtons() {
    for (int row = 0; row < 4; row++) {
        digitalWrite(rowPins[row], LOW);
        for (int col = 0; col < 4; col++) {
            if (digitalRead(colPins[col]) == LOW) {
                if (row == activeX && col == activeY) {
                    score++;
                    newTarget();
                }
            }
        }
        digitalWrite(rowPins[row], HIGH);
    }
}
```

---

## 🎯 How to Play  
🔹 **A random square will light up on the LED matrix.**  
🔹 **You have 2 seconds to press the correct button on the 4x4 keypad.**  
🔹 **Each correct press gives +1 point.**  
🔹 **Game ends when time runs out, displaying your final score!**  

---

## 🎨 Additional Ideas to Improve the Project!  
🔹 Make it **multiplayer** (alternate turns or compare scores).  
🔹 Add **sound effects** (a buzzer for correct/wrong presses).  
🔹 Change **difficulty levels** (reduce response time).  
🔹 Show a **countdown timer** on the 7-segment display.  

🎉 **Enjoy your interactive reflex game!** 🚀