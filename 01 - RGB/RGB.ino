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