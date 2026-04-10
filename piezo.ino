const int piezoPin = 11; //piezo pin
//a very high note
#define NOTE_DS8 4978

// the note piezo plays
int melody = NOTE_DS8;
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations = 8;

void setup() {
  Serial.begin (9600);
  pinMode(piezoPin, OUTPUT);

  tone(11, melody);         //turn piezo on
  Serial.print("piezo on");
  // stop the tone playing:
  noTone(11);
}

void loop() {
  // no need to repeat
}
