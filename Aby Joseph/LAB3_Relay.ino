int relaypin = D1;

void setup() {
  // put your setup code here, to run once:
pinMode(relaypin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(relaypin,HIGH);
delay(2000);
digitalWrite(relaypin,LOW);
delay(2000);
}
