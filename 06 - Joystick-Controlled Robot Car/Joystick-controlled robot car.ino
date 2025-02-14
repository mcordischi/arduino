#include <Servo.h>
#include <AccelStepper.h>

// Servo
Servo servo;
const int SERVO_PIN = 13;

// Stepper
#define MotorInterfaceType 4
AccelStepper stepper(MotorInterfaceType, 4, 6, 5, 7);

void setup() {
    servo.attach(SERVO_PIN);
    servo.write(90); // Initial position

    stepper.setMaxSpeed(1000); 
    stepper.setAcceleration(500);
}

void loop() {
    // Read the current position of the Joystick
    int joystickX = analogRead(A0);
    int joystickY = analogRead(A1);

    // Moves the stepper motor, depending on the X coordinates
    int motorSpeed = map(joystickX, 0, 1023, -500, 500);
    stepper.setSpeed(motorSpeed);
    stepper.runSpeed();

    // Moves the servo, depending on the Y coordinates
    int servoAngle = map(joystickY, 0, 1023, 0, 180);
    servo.write(servoAngle);
}