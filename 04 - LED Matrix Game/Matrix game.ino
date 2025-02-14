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
unsigned long lastUpdateTime = 0; //Internal control to check that a second passed

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
        
        // Verify that is has been a second
        if (millis() - lastUpdateTime >= 1000) {
            lastUpdateTime = millis();  // Updates the time
            timeLeft--;  // Reduces the fime left
            display.showNumberDecEx(timeLeft, 0b01000000, true);

            if (timeLeft == 0) {
                gameOver();
            }
        }
    }
}

// Pick a new random LED position
void newTarget() {
    lc.clearDisplay(0);
    activeX = random(0, 4);
    activeY = random(0, 4);
    int posX = 2 * activeX;
    int posY = 2 * activeY;
    lc.setLed(0, posX, posY, true);
    lc.setLed(0, posX+1, posY, true);
    lc.setLed(0, posX, posY+1, true);
    lc.setLed(0, posX+1, posY+1, true);
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

void gameOver() {
    display.showNumberDec(score);  // Muestra el puntaje final
    Serial.println("Game Over! Final Score: " + String(score));
}