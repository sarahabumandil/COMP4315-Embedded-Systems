#include <Servo.h>

// Create Servo objects for 4 joints
Servo baseServo;
Servo shoulderServo;
Servo elbowServo;
Servo gripperServo;

// Potentiometer analog pins
int potBase = A0;
int potShoulder = A1;
int potElbow = A2;
int potGripper = A3;

void setup() {
  // Attach servos to PWM pins
  baseServo.attach(3);
  shoulderServo.attach(5);
  elbowServo.attach(6);
  gripperServo.attach(9);
}

void loop() {
  // Read potentiometers (0-1023) and map to servo angles (0-180)
  int angleBase = map(analogRead(potBase), 0, 1023, 0, 180);
  int angleShoulder = map(analogRead(potShoulder), 0, 1023, 0, 180);
  int angleElbow = map(analogRead(potElbow), 0, 1023, 0, 180);
  int angleGripper = map(analogRead(potGripper), 0, 1023, 0, 180);

  // Move servos to mapped angles
  baseServo.write(angleBase);
  shoulderServo.write(angleShoulder);
  elbowServo.write(angleElbow);
  gripperServo.write(angleGripper);

  delay(15); // Small delay for smooth movement
}
