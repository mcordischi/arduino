# 🎮 Arduino Project: Controlling LEDs and Buzzer with a Remote

## 📌 Project Overview  
In this project, we will use an **infrared (IR) remote** to control:  
- **LEDs** (turning them on/off).  
- **A buzzer** (making sounds).  
- **An LCD screen** (displaying the last pressed buttons).  

This is a great way to learn about **infrared signals, button inputs, and output control!**  

---

## 🛠 Components Needed  
- 1x **Arduino Uno**  
- 1x **IR Receiver Module (1838B)**  
- 1x **Buzzer**  
- 3x **LEDs (red, green, blue or any colors)**  
- 3x **220Ω Resistors** (optional for LEDs)  
- 1x **16x2 LCD Display**  
- 1x **Potentiometer (B10K)** (for LCD contrast)  
- 1x **Infrared Remote Control**  
- **Jumper Wires**  
- 1x **Breadboard**  

---

## 🔌 Wiring Diagram  

### 📌 **1️⃣ IR Receiver Module (for Remote Control)**
| IR Receiver Pin | Connect to: |
|----------------|-------------|
| **OUT**        | **Pin 2** (Arduino) |
| **GND**        | GND (Arduino) |
| **VCC**        | 5V (Arduino) |

The order of the pins of the IR Receiver are looking it up front. More info in the **Datasheet** http://www.datasheetmeta.com/pdf.php?q=VS1838B



### 📌 **2️⃣ Buzzer**
| Buzzer Pin  | Connect to: |
|------------|-------------|
| **(+) Positive** | **Pin 3** (Arduino) |
| **(-) Negative** | GND (Arduino) |

### 📌 **3️⃣ LEDs**
| LED | Arduino Pin |
|-----|------------|
| **LED 1** | **Pin 4** |
| **LED 2** | **Pin 5** |
| **LED 3** | **Pin 6** |

🔹 Each LED should have a 220Ω resistor in series. The LED longer leg is connected to a resistor, then the other end of the resistor is connected to the Arduino
🔹 Connect the shorter leg of the LED to GND (-)

### 📌 **4️⃣ LCD Display (Without I2C)**
| LCD Pin | Connect to: |
|---------|------------|
| **GND**  | GND (Arduino) |
| **VCC**  | 5V (Arduino) |
| **VO (Contrast)** | Middle pin of **potentiometer** |
| **RS**   | **Pin 7** |
| **RW**   | GND (Arduino) |
| **E**    | **Pin 8** |
| **D4**   | **Pin 9** |
| **D5**   | **Pin 10** |
| **D6**   | **Pin 11** |
| **D7**   | **Pin 12** |
| **BLA (Backlight +)** | 5V |
| **BLK (Backlight -)** | GND |

---

## 📥 Installing the IRremote Library  

To make the IR remote work, you need to install the **IRremote by Shirriff** library (v2.6.0).  

**Steps to install:**  
1️⃣ Open **Arduino IDE** → Go to **Sketch** → **Include Library** → **Manage Libraries...**  
2️⃣ Search for **"IRremote by Shirriff"** (Install version **2.6.0**).  
3️⃣ Done! Now you can use:  
```cpp
#include <IRremote.h>
```



## 🖥 The Code

```cpp
#include <IRremote.h>
#include <LiquidCrystal.h>

const int IR_RECEIVER_PIN = 2;
const int BUZZER_PIN = 3;
const int LED_1 = 4;
const int LED_2 = 5;
const int LED_3 = 6;

IRrecv irrecv(IR_RECEIVER_PIN);
decode_results results;

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
    Serial.begin(9600);
    irrecv.enableIRIn();  // Start the IR receiver
    
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);
    pinMode(LED_3, OUTPUT);

    lcd.begin(16, 2);
    lcd.print("Waiting...");
}

void loop() {
    if (irrecv.decode(&results)) {
        Serial.println(results.value, HEX); // Print button code in HEX
        
        lcd.clear();
        lcd.print("Btn: ");
        lcd.print(results.value, HEX);

        // 🚨 Challenge: These button codes are WRONG! Fix them below! 🚨
        if (results.value == 0xFF10AF) {  // Should be 0xFF30CF
            digitalWrite(LED_1, !digitalRead(LED_1));
        }
        if (results.value == 0xFF20BF) {  // Should be 0xFF18E7
            digitalWrite(LED_2, !digitalRead(LED_2));
        }
        if (results.value == 0xFF40DF) {  // Should be 0xFF7A85
            digitalWrite(LED_3, !digitalRead(LED_3));
        }
        if (results.value == 0xFFA25D) {  // Power button (turn buzzer ON for 0.5s)
            digitalWrite(BUZZER_PIN, HIGH);
            delay(500);
            digitalWrite(BUZZER_PIN, LOW);
        }

        irrecv.resume();  // Receive next signal
    }
}
```

## 🎯 Challenge: Fix the Incorrect Button Codes!

The button codes in the code above are wrong!

🔴 Find and replace them with the correct ones:

    LED 1 should use: 0xFF30CF
    LED 2 should use: 0xFF18E7
    LED 3 should use: 0xFF7A85

💡 Hint: Run the test code below to read the real button codes:

```cpp
#include <IRremote.h>
const int IR_RECEIVER_PIN = 2;
IRrecv irrecv(IR_RECEIVER_PIN);
decode_results results;

void setup() {
    Serial.begin(9600);
    irrecv.enableIRIn();
}

void loop() {
    if (irrecv.decode(&results)) {
        Serial.println(results.value, HEX);
        irrecv.resume();
    }
}
```

## 🎨 Additional Ideas to Improve the Project!

🔹 Make a game where players must press specific buttons quickly!
🔹 Control servo motors with the remote!
🔹 Use the LCD screen to display messages or scores!
🔹 Add a countdown timer on the LCD when pressing a button!
🔹 Create a secret code that unlocks an action when pressing buttons in a sequence!

## ✅ The Correct Button Codes Are...

🎉 LED 1: 0xFF30CF
🎉 LED 2: 0xFF18E7
🎉 LED 3: 0xFF7A85

Did you figure it out? Great job! 🚀
Now, try customizing the project with your own ideas!
