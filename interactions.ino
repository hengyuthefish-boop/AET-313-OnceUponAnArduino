const int ledPin = 13;
void setup() {

  // put your setup code here, to run once
pinMode(ledPin, OUTPUT);
}

void loop() {
  face();
}

void face(){
  digitalWrite(ledPin, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);  
}
