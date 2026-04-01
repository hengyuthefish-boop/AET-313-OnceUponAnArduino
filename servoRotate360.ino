#include <Servo.h>

Servo myservo;//create servo variable
const int buttonPin = 2;

void setup() {
  myservo.attach(9);//attach servo on pin 9
  pinMode(buttonPin, INPUT);
}

void loop() {
  if (digitalRead(buttonPin) ==HIGH){
    myservo.write(180);// turn to angle 180 (customize here what angle to turn)
  } else{
    myservo.write(0);
  }

}
