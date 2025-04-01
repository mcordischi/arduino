# 🏠 RGB LED Controller with Three Buttons 🏠 

## 🛠️ What You Will Build
You will create a simple **RGB LED controller** using three buttons. Each button increases the intensity of Red, Green, or Blue in three steps. When a color reaches the maximum, it resets to zero.
---
### 📚 Knowledge links - Bonus/Important to read 
- [RGB Importance](RGB_info.md)
- [Resistors - Law the Ohm](Resistors_lawtheohm.md)
---

## 📌 Components Needed
- **1 x Arduino Uno**  
- **1 x RGB LED (Common Cathode)**  
- **3 x Push buttons**  
- **3 x 220Ω resistors (for the LED)**  
- **Jumper wires**  
- **Breadboard**  

---

## ⚡ Wiring Diagram

### 🔴 RGB LED Connections
| **LED Pin**  | **Connect To** |
|-------------|--------------|
| **Red (R)** | Arduino **Pin 9**|
| **Green (G)** | Arduino **Pin 10** |
| **Blue (B)** | Arduino **Pin 11** |
| **Common (Cathode) -** | **5V** |

### 🎮 Button Connections
Each button has **four legs**. We will use only **two opposite legs**.

| **Button**  | **One Leg to...** | **Other Leg to...** |
|------------|------------------|------------------|
| **Red Button** | **GND** | **Arduino Pin 2** |
| **Green Button** | **GND** | **Arduino Pin 3** |
| **Blue Button** | **GND** | **Arduino Pin 4** |

🚨 **Important!** The buttons use **INPUT_PULLUP**, so no resistors are needed!

---

## 💻 Arduino Code
Upload this code to your Arduino:

```cpp
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

int redButton = 2;
int greenButton = 3;
int blueButton = 4;

int levelR = 0;
int levelG = 0;
int levelB = 0;
int stepsSize = 3;
const int steps[3] = {0, 170, 255};

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  pinMode(redButton, INPUT_PULLUP);
  pinMode(greenButton, INPUT_PULLUP);
  pinMode(blueButton, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(redButton) == LOW) {
    levelR = (levelR + 1) % stepsSize;
    delay(200);
  }

  if (digitalRead(greenButton) == LOW) {
    levelG = (levelG + 1) % stepsSize;
    delay(200);
  }

  if (digitalRead(blueButton) == LOW) {
    levelB = (levelB + 1) % stepsSize;
    delay(200);
  }

  analogWrite(redPin, steps[levelR]);
  analogWrite(greenPin, steps[levelG]);
  analogWrite(bluePin, steps[levelB]);
}
```

---

## 🎯 How It Works
1. Each button increases **Red, Green, or Blue** intensity in **two steps** (0 → 170 → 255 → 0).  
2. The colors **reset to 0** after reaching the maximum.  
3. The `delay(200);` prevents accidental multiple presses.  
4. `INPUT_PULLUP` keeps the buttons stable, avoiding extra resistors.  

---

## 🔎 Troubleshooting
- **Only one color changes or does not reset?** → Check the wiring of the LED.  
- **Button doesn’t work?** → Try switching the legs used.  
- **All colors are always ON?** → Make sure your LED is **Common Cathode** and connected to **GND**.  

---

## 🚀 Experiment!
- Try **different step sizes** (e.g., `64` for four steps instead of three).  
- Add a **fourth button** to reset all colors to 0.  
- Make a **rainbow cycle** that changes automatically! 🌈  

🎉 **Enjoy your colorful Arduino project!** 😃

AI powered with ChatGPT
