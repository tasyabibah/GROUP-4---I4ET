byte Lab2;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(230400);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available())
  {
    Lab2=Serial.read();

    if (Lab2 == 78)
    {
      Serial.println("LAMP ON");
      digitalWrite(LED_BUILTIN, LOW);
    }
    if (Lab2 == 65)
    {
      Serial.println("LAMP OFF");
      digitalWrite(LED_BUILTIN, HIGH);
    }
  }

}
