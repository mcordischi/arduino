# 🛠️ Getting Started with Arduino (Windows Guide)

## 🔍 Step 1: Find or Download the Arduino App

- If you’re on Windows, the Arduino IDE might already be installed.
- Check by searching for **“Arduino”** on your Desktop or Start Menu.
- If it's not installed, download it from the official page:

👉 [Arduino IDE Download Page](https://www.arduino.cc/en/software)

## 📹 Step 2: Installation Instructions

For a quick and simple install, follow this video guide:

🎥 **Installing Arduino IDE in Windows** [YouTube](https://www.youtube.com/watch?v=ADn67BYMdH0) 
> _(Skip the ad if there's one!)_

There are other videos and tutorials out there, but this one is short and easy to follow.

---

## ⚠️ Common Problems & Solutions from the Lab

### 🚫 Problem 1: Can't Upload Code (Permissions Issue)

**Issue:** You get an error when trying to upload code to the Arduino.  
**Cause:** Admin restrictions on the computer
**Solution:**
1. Right-click on the **Arduino IDE icon**.
2. Select **“Run as Administrator”**.
3. Click **“Yes”** when prompted.

### 🔌 Problem 2: USB Port Not Working

**Issue:** Code won’t upload from one of the lab computers.  
**Cause:** Faulty USB port.  
**Solution:**  
Use another computer or try a different USB port.

---

## 🧭 Step 3: Select the Correct Board & Port

When uploading code, if you see something like:
## 🔁 Uploading Code: Board & Port Setup

When you're ready to upload your code but **don't see "Arduino"** under the ports (you only see something like `Unknown - COM4`), do the following:

### ✅ Select the Correct Board

1. Go to **Tools > Board**
2. Choose **Arduino Uno**

> We're currently using the **Arduino Uno** microcontroller. In the future, you might use a different board, so always make sure to select the right one for your project.

📺 For a more detailed setup guide:  
**Setup and Program Arduino Uno: Complete Guide** [YouTube](https://www.youtube.com/watch?v=ELUF8m24sZo)

---

## 🚦 Start Simple

Start with an easy example like the LED blink project.

🔗 GitHub Project:  
**[mcordischi/arduino: One-day Arduino Projects](https://github.com/mcordischi/arduino)**

Once you're comfortable, try more advanced ones. Some will require you to:

- Install additional **libraries** (you can search how to do this or explore the **Sketch > Include Library** menu in the Arduino IDE)
- Or we can walk through it together in an online session.

---

## 🎨 Pro Tip: Use Color-Coded Cables

When building circuits, use **different colored wires** to help you debug faster.

- Example: use a **red wire for the red LED and the red button**
- Technically, all jumper wires work the same, but:
  > Using consistent color-coding makes it easier to check connections.

🧠 Example:
- Red LED → connected to **pin 9** with a **red wire**

If your breadboard has lots of cables, this helps avoid confusion and mistakes.

