byte blue;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(230400);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available())
  {
    blue=Serial.read();

    if (blue == 78)
    {
      Serial.println("ON");
      digitalWrite(LED_BUILTIN, LOW);
    }
    if (blue == 65)
    {
      Serial.println("OFF");
      digitalWrite(LED_BUILTIN, HIGH);
    }
  }

}
