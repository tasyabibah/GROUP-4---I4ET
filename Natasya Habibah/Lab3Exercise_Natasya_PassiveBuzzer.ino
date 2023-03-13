#include "pitches.h"

//notes in the melody:
int melody [] = {
  NOTE_D5, NOTE_C5};
  int duration = 500; // 500 miliseconds

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int thisNote = 0; thisNote < 2; thisNote++) {
    //pin D1 controls the sound, emitting each note every 'duration' miliseconds
    tone(D1, melody[thisNote], duration);

    // Output the voice after 500 miliseconds
    delay(500);
  }

  //restart after a second
  delay(1000);
}
