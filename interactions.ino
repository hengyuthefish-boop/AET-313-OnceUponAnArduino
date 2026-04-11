#include <Servo.h>
Servo dadServo;
Servo trafficServo;

const int ledPin = 13;
const int resetButtonPin = 10;
bool isReset;
int pos = 0;


void setup() {
  Serial.begin(9600);
  dadServo.attach(9);
  trafficServo.attach(8);
  pinMode(ledPin, OUTPUT);
  pinMode(resetButtonPin, INPUT);
  isReset = false;
}

void loop() {
  face();
  trafficCircle();
  if (!isReset) {
    dad();
  }
  reset();
}

void face() {
  digitalWrite(ledPin, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);
}

void dad() {

  if (!isReset) {
    dadServo.write(180);
  }
}

void trafficCircle() {

  trafficServo.write(360);
}

void reset() {
  if (digitalRead(resetButtonPin) == HIGH) {
    isReset = !isReset;
    dadServo.write(90);
    if (isReset) {
      Serial.println("in reset mode");
    } else {
      Serial.println("ready to play");
    }
  }
}
