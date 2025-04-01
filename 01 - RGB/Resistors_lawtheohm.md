# Why Use Resistors with LEDs?

## 🏠 [Back Home](README.md) 

### **1. LEDs Need Current Limiting**
- LEDs are **current-driven devices** and do not regulate current automatically.
- Without a resistor, an LED may **draw too much current**, leading to:
  - Overheating 🔥
  - Burning out 💡💥
  - Damage to the power source ⚡

### **2. Ohm’s Law: Calculating the Resistor Value**
Formula:

```math
R = \frac{V_{\text{source}} - V_{\text{LED}}}{I_{\text{LED}}}
```
Link: [Ohm's Law Calculator](https://www.omnicalculator.com/physics/ohms-law)

### **3. Recommended Resistor Values for RGB LEDs**
Remainder: The Arduino Uno typically provides **5V** as the main supply voltage. 
This is available through the 5V pin and is often used to power external components, including LEDs, sensors, and other peripherals.

#### **For a 5V Power Supply**
| LED Color | Forward Voltage (Vf) | Recommended Current (I) | Resistor Calculation | Recommended Resistor |
|-----------|----------------------|--------------------------|----------------------|----------------------|
| **Red**   | 1.8V - 2.2V           | 20mA (0.02A)             | \( \frac{5V - 2V}{0.02A} = 150Ω \) | **150Ω** |
| **Green** | 2.8V - 3.2V           | 20mA (0.02A)             | \( \frac{5V - 3V}{0.02A} = 100Ω \) | **100Ω** |
| **Blue**  | 3.0V - 3.4V           | 20mA (0.02A)             | \( \frac{5V - 3.2V}{0.02A} = 90Ω \) | **90Ω (Use 100Ω)** |

### **4. Conclusion**
Always use a resistor to **protect your LEDs**, ensure **consistent brightness**, and **extend their lifespan**! 🔧💡
