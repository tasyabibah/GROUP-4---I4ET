
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

