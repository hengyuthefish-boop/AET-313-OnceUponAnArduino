#include <Servo.h>
Servo dadServo;
Servo trafficServo;
Servo boatServo;
Servo busServo;
Servo globeServo;

const int ledPin = 13;
const int stairLedPin = 12;
const int resetButtonPin = 10;
bool isReset;
int pos = 0;
int globePos = 0;


void setup() {
  Serial.begin(9600);
  dadServo.attach(9);
  trafficServo.attach(8);
  boatServo.attach(4);
  busServo.attach(3);
  globeServo.attach(2);
  pinMode(ledPin, OUTPUT);
  pinMode(stairLedPin, OUTPUT);
  pinMode(resetButtonPin, INPUT);
  isReset = false;
}

void loop() {
  face();
  trafficCircle();
  if (!isReset) {
    dad();
  }
  stairs();
  reset();
  boat();
  bus();
  globe();
}

void face() {
  digitalWrite(ledPin, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);
}

void stairs() {
  digitalWrite(stairLedPin, HIGH);  // turn the LED on (HIGH is the voltage level)
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

void boat() {
  if (!isReset) {
    boatServo.write(180);
  }
}

void bus() {

  for (pos = 0; pos <= 35; pos += 1) {  
    busServo.write(pos);               
    delay(15);
    if (pos == 35) {
      busServo.detach();
    }  
  }
}

void globe() {
  for (globePos = 0; globePos <= 10; globePos += 1) {  
    globeServo.write(globePos);               
    delay(15);
    if (globePos == 10) {
      globeServo.detach();
    }  
  }
}

void reset() {
  if (digitalRead(resetButtonPin) == HIGH) {
    isReset = !isReset;
    dadServo.write(90);
    boatServo.write(0);
    busServo.attach(3);
  for (pos = 180; pos >= 60; pos -= 1) {  
    busServo.write(pos);               
    delay(15);
    if (pos == 150) {
      busServo.detach();
    }  
  }
  for (globePos = 180; globePos >= 170; globePos -= 1) {  
    globeServo.write(globePos);               
    delay(15);
    if (pos == 170) {
      globeServo.detach();
    }  
  }
    if (isReset) {
      Serial.println("in reset mode");
    } else {
      Serial.println("ready to play");
    }
  }
}
