#include <Servo.h>

Servo baseServo, shoulderServo, elbowServo, gripperServo;

void setup() {
  Serial.begin(9600); // بدء الاتصال السيريال بسرعة 9600
  baseServo.attach(3);
  shoulderServo.attach(5);
  elbowServo.attach(6);
  gripperServo.attach(9);
}

void loop() {
  // قراءة المقاومات وتحويلها لزوايا (0 إلى 180)
  int a1 = map(analogRead(A0), 0, 1023, 0, 180);
  int a2 = map(analogRead(A1), 0, 1023, 0, 180);
  int a3 = map(analogRead(A2), 0, 1023, 0, 180);
  int a4 = map(analogRead(A3), 0, 1023, 0, 180);

  // تحريك المحركات في البروتس
  baseServo.write(a1);
  shoulderServo.write(a2);
  elbowServo.write(a3);
  gripperServo.write(a4);

  // إرسال الزوايا إلى البايثون مفصولة بفاصلة
  Serial.print(a1); Serial.print(",");
  Serial.print(a2); Serial.print(",");
  Serial.print(a3); Serial.print(",");
  Serial.println(a4);

  delay(50);
}

