# Reflex Game with LED Matrix and Button Matrix

## 🎯 What You Will Build
This project is a **reflex game** using an **8x8 LED matrix** and a **4x4 button matrix**. The goal is to **press the correct button** matching the **lit-up LED square** within **2 seconds** to score points. The score will be displayed on a **4-digit, 8-segment display**.

---

## 📌 Components Needed
- **1 x Arduino Uno**  
- **1 x 8x8 LED Matrix** (with MAX7219 controller)  
- **1 x 4x4 Button Matrix**  
- **1 x 4-Digit, 8-Segment Display**  
- **Jumper wires**  
- **Breadboard**  

---

## ⚡ Wiring Diagram

### 🔲 8x8 LED Matrix (MAX7219) Connections
| **Matrix Pin**  | **Connect To** |
|-------------|--------------|
| **VCC** | **5V** |
| **GND** | **GND** |
| **DIN** | **Arduino Pin 11** |
| **CS** | **Arduino Pin 10** |
| **CLK** | **Arduino Pin 13** |

### 🔘 4x4 Button Matrix Connections
| **Matrix Pin**  | **Connect To** |
|----------------|---------------|
| **Row 1** | **Arduino Pin 2** |
| **Row 2** | **Arduino Pin 3** |
| **Row 3** | **Arduino Pin 4** |
| **Row 4** | **Arduino Pin 5** |
| **Col 1** | **Arduino Pin 6** |
| **Col 2** | **Arduino Pin 7** |
| **Col 3** | **Arduino Pin 8** |
| **Col 4** | **Arduino Pin 9** |

### 🏆 4-Digit, 8-Segment Display Connections
| **Display Pin**  | **Connect To** |
|-----------------|---------------|
| **VCC** | **5V** |
| **GND** | **GND** |
| **DIN** | **Arduino Pin A1** |
| **CS** | **Arduino Pin A2** |
| **CLK** | **Arduino Pin A3** |

---

## 💻 Arduino Code
Upload this code to your Arduino:

```cpp
#include <LedControl.h>
#include <TM1637Display.h>

#define MATRIX_DIN 11
#define MATRIX_CS 10
#define MATRIX_CLK 13
#define SEG_DIN A1
#define SEG_CS A2
#define SEG_CLK A3

LedControl lc = LedControl(MATRIX_DIN, MATRIX_CLK, MATRIX_CS, 1);
TM1637Display display(SEG_CLK, SEG_DIN);

int buttonRows[4] = {2, 3, 4, 5};
int buttonCols[4] = {6, 7, 8, 9};
int score = 0;
int activeRow, activeCol;
unsigned long startTime;

void setup() {
    for (int i = 0; i < 4; i++) {
        pinMode(buttonRows[i], INPUT_PULLUP);
        pinMode(buttonCols[i], INPUT_PULLUP);
    }
    display.setBrightness(7);
    randomSeed(analogRead(0));
    generateNewTarget();
}

void loop() {
    if (millis() - startTime > 2000) { // Timeout
        generateNewTarget();
    }
    
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            if (digitalRead(buttonRows[row]) == LOW && digitalRead(buttonCols[col]) == LOW) {
                if (row == activeRow && col == activeCol) {
                    score++;
                    display.showNumberDec(score);
                    generateNewTarget();
                }
            }
        }
    }
}

void generateNewTarget() {
    lc.clearDisplay(0);
    activeRow = random(0, 4);
    activeCol = random(0, 4);
    
    int x = activeCol * 2;
    int y = activeRow * 2;
    
    lc.setLed(0, y, x, true);
    lc.setLed(0, y, x + 1, true);
    lc.setLed(0, y + 1, x, true);
    lc.setLed(0, y + 1, x + 1, true);
    
    startTime = millis();
}
```

---

## 🎮 How It Works
1. The **8x8 LED matrix** lights up a **2x2 square** at a random position.  
2. The player must press the **correct button** on the **4x4 button matrix** that matches the LED position.  
3. If the player presses the correct button **within 2 seconds**, they **gain 1 point**. The score updates on the **7-segment display**.  
4. If the player **misses the time limit**, a new position is generated.  

---

## 🔎 Troubleshooting
- **No LEDs lighting up?** → Check the **8x8 LED matrix wiring**.  
- **Buttons not working?** → Ensure proper **pull-up resistors** and wiring.  
- **Score doesn’t update?** → Verify the **7-segment display** connections.  

---

## 🚀 Experiment!
- **Add a buzzer** for feedback on correct/incorrect presses.  
- **Increase difficulty** by reducing the time limit.  
- **Add different colors** to the LED matrix for multiple difficulty levels.  

🎉 **Enjoy your interactive reflex game!** 🚀

