int relayPin = D1;

void setup() 
{
  // put your setup code here, to run once:
  pinMode(relayPin, OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  digitalWrite(relayPin, HIGH); // turn the relay on
  delay(2000); //wait for two seconds
  digitalWrite(relayPin, LOW); //turn the relay off
  delay(2000); // wait for another two seconds
}
