byte receivedByte = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
Serial.begin(230400);
}

void loop(){
if (Serial.available()>0)
 {
  // put your main code here, to run repeatedly:
 receivedByte = Serial.read();
 Serial.println(receivedByte);

if ((receivedByte == 97) || (receivedByte == 65))
{digitalWrite(LED_BUILTIN, LOW);   // turn the LED on by making the voltage LOW
  }

if ((receivedByte == 121) || (receivedByte == 89))
{digitalWrite(LED_BUILTIN, HIGH);   // turn the LED off by making the voltage HIGH
  }

}
}
