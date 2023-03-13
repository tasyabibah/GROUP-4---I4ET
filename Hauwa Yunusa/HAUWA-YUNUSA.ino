/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

//Hauwa ON/OFF Led light with characters H and A

const int LED_PIN = LED_BUILTIN; // PIN WHERE THE LED LIGHT WILL BE ACTIVATED
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(230400);
}

void loop() {
  if (Serial.available()> 0) { // If character is available on serial port
    char c = Serial.read(); // Read the incoming character
    if (c == 'H') { // If 'H' is received, turn on the LED
      digitalWrite(LED_PIN, LOW);
      Serial.println("LED on");
    } else if (c == 'A') { // If 'A' is received, turn off the LED
      digitalWrite(LED_PIN, HIGH);
      Serial.println("LED off");
    }
  }
}

