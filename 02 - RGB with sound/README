# RGB LED with Sound Control

## 🎯 What You Will Build
You will create an **RGB LED controller with sound detection**. The LED color changes when a **loud sound** (like a clap) is detected by the **KY-037 microphone sensor**. A **buzzer** will play a tone when the color changes.

---

## 📌 Components Needed
- **1 x Arduino Uno**  
- **1 x RGB LED (Common Cathode)**  
- **1 x KY-037 Microphone Module**  
- **1 x Buzzer**  
- **3 x 220Ω resistors (for the LED)**  
- **Jumper wires**  
- **Breadboard**  

---

## ⚡ Wiring Diagram

### 🔴 RGB LED Connections
| **LED Pin**  | **Connect To** |
|-------------|--------------|
| **Red (R)** | Arduino **Pin 9** (through a **220Ω resistor**) |
| **Green (G)** | Arduino **Pin 10** (through a **220Ω resistor**) |
| **Blue (B)** | Arduino **Pin 11** (through a **220Ω resistor**) |
| **Common (Cathode)** | **GND** |

### 🎤 Microphone KY-037 Connections
| **Microphone Pin**  | **Connect To** |
|---------------------|---------------|
| **VCC** | **5V** |
| **GND** | **GND** |
| **A0** | **Arduino Pin A0** |

### 🔊 Buzzer Connections
| **Buzzer Pin**  | **Connect To** |
|-----------------|---------------|
| **+ (Positive)** | **Arduino Pin 6** |
| **- (Negative)** | **GND** |

---

## 💻 Arduino Code
Upload this code to your Arduino:

```cpp
int redPin = 9;
int greenPin = 10;
int bluePin = 11;
int buzzer = 6;
int micPin = A0;

int colors[3] = {0, 0, 0}; // RGB levels
int stepSize = 85; // Three levels: 0 → 85 → 170 → 255 → 0
int threshold = 600; // Adjust based on the environment

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int micValue = analogRead(micPin);
  Serial.println(micValue);
  
  if (micValue > threshold) {
    changeColor();
    tone(buzzer, 1000, 100); // Beep sound
    delay(500); // Prevents multiple detections
  }
}

void changeColor() {
  static int colorIndex = 0;
  colors[colorIndex] = (colors[colorIndex] + stepSize) % 256;
  analogWrite(redPin, colors[0]);
  analogWrite(greenPin, colors[1]);
  analogWrite(bluePin, colors[2]);
  colorIndex = (colorIndex + 1) % 3;
}
```

---

## 🎛️ How It Works
1. The **KY-037 microphone** detects a loud noise and sends a signal.  
2. The Arduino reads this signal. If it’s above the **threshold**, it triggers an action.  
3. The **RGB LED changes color** (cycling through red → green → blue).  
4. The **buzzer beeps** when the color changes.  
5. A **small delay (500ms)** prevents multiple triggers from a single sound.  

---

## 🔎 Troubleshooting
- **The LED doesn’t change colors?** → Adjust the `threshold` value in the code.  
- **Too many false triggers?** → Increase the delay time or adjust the mic sensitivity using its potentiometer.  
- **No sound from the buzzer?** → Make sure it’s correctly connected to **Pin 6** and **GND**.  

---

## 🚀 Experiment!
- Try **changing colors randomly** instead of cycling through red, green, and blue.  
- Use different **buzzer tones** for each color.  
- Add a **push button** to manually reset the LED to black (off).  

🎉 **Enjoy your interactive sound-controlled RGB LED project!** 🔊🌈

