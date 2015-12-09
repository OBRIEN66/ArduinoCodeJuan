// This program will control a servo with a joystick
#include <Servo.h>

Servo servo;

int ServoPin = 3;
int xAxisPin = A1;
int pos = 0;

void setup() {
  servo.attach(ServoPin);
  Serial.begin(9600);
  pinMode(xAxisPin, INPUT);
  
}

void loop() {
  if (digitalRead(xAxisPin) > 0){
    servo.write(pos + 1);
  }
  if (digitalRead(xAxisPin) < 0){
    servo.write(pos - 1);
  }

}
