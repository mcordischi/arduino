# 🎮 Sound Controlled Motor

## 📝 Introduction
In this project, we will use a **microphone** to detect sound and control a **motor**. The motor will rotate for a couple of seconds and then stop

This project is great for learning about sensors.

---

## 🛠 Materials
- **Arduino Uno**  
- **1 x Yellow DC Motor**  
- **1 x KY-037 Microphone Module**  
- **1 x Relay**
- **Jumper wires**  

---

## 📌 Wiring

### **Relay to Arduino**
| Relay | Arduino Pin |
|------------|------------|
| S        | Pin 7         |
| -        | GND        |
| +        | 5V         |

### **Relay to Motor**
| Relay | Arduino Pin |
|------------|------------|
| COM        | Motor -         |
| NO       | 5V Arduino        |
| +        | 5V         |


### Motor**
| Motor | Connect to |
|------------|------------|
| +        | 5V         |
| -        | Relay COM        |

### 🎤 Microphone KY-037 Connections
| **Microphone Pin**  | **Connect To** |
|---------------------|---------------|
| **VCC** | **5V** |
| **GND** | **GND** |
| **A0** | **Arduino Pin A0** |

---

### **Arduino Code**
```cpp
const int soundSensor = 2; // Digital Pin of the sound sensor
const int micPin = A0; //Analog Pin of the sound sensor
const int relayPin = 7; // Relay Pin
const int motorTime = 2000; // Time in milliseconds (2 seg)
int threshold = 400; // Adjust based on the environment

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Motor turned off at the start
  Serial.begin(9600);
}

void loop() {
  int micValue = analogRead(micPin);
  Serial.println(micValue);
  
  if (micValue > threshold) { 
    digitalWrite(relayPin, HIGH); // Turn on the motor
    delay(motorTime); // wait for some time
    digitalWrite(relayPin, LOW); // Turn off the motor
  }
}
```

## 🔧 Possible Improvements

💡 Adjust the sensitivity changing the threshold
💡 You can connect other modules instead of a Motor
💡 What if the motor moves everytime there is sound?