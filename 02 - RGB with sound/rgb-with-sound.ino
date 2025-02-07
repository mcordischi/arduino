int redPin = 9;
int greenPin = 10;
int bluePin = 11;
int buzzer = 6;
int micPin = A0;

int colors[3] = {0, 0, 0}; // RGB levels
int stepSize = 85; // Three levels: 0 → 85 → 170 → 255 → 0
int threshold = 60; // Adjust based on the environment

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