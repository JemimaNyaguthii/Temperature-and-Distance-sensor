// C++ code
//
#include <Servo.h>

Servo servo_3;

void setup()
{
  pinMode(A0, INPUT);
  servo_3.attach(3, 500, 2500);

  if ((-40 + 0.488155 * (analogRead(A0) - 20)) > 30) {
    servo_3.write(90);
  }
}

void loop()
{
  delay(10); // Delay a little bit to improve simulation performance
}