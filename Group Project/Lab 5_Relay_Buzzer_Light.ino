#include "dweetESP8266.h"
#include "pitches.h"
#define THIG_NAME "ie4tgroup4lab5"

const char* ssid= "Tech_D9756536";
const char* password = "37GcDqKd7uD6";
char *key3 = "Relay";
char *key4 = "Buzzer";
char *key5 = "Light";
char *key6 = "Relay2";

//notes in the melody:
int melody [] = {
  NOTE_D5, NOTE_C5, NOTE_GS2,};
  int duration = 15000; // 500 miliseconds
dweet DweetClient;
int relaypin = D1;
int relaypin2 = D7;
void setup() {
  // put your setup code here, to run once:
pinMode(relaypin,OUTPUT);
pinMode(relaypin2,OUTPUT);
pinMode(D3,OUTPUT);
Serial.begin(115200);
delay(10);


//Conecting to a WiFi network
Serial.println();
Serial.println();
Serial.print("Connecting to ");
Serial.print(ssid);
WiFi.begin(ssid,password);
while(WiFi.status()!=WL_CONNECTED){
  delay(500);
Serial.print(".");
}
Serial.println("");
Serial.println("WIFI Conneted");
Serial.println("IP Address: ");
Serial.println(WiFi.localIP());
}



void loop(){
  // put your main code here, to run repeatedly:
String value1 = DweetClient.getDweet(THIG_NAME,"waterlevel1");
String value2 = DweetClient.getDweet(THIG_NAME,"waterlevel2");
Serial.println(value1);
Serial.println(value2);

//Relay 
if ((value1)>(value2))
{
digitalWrite(relaypin,HIGH);
digitalWrite(relaypin2,LOW);
digitalWrite(D2,HIGH);
digitalWrite(D3, HIGH);
for (int thisNote = 0; thisNote < 3; thisNote++) {
  //pin D1 controls the sound, emitting each note every 'duration' miliseconds
  tone(D2, melody[thisNote], duration);
  delay(500);  
   // Output the voice after 500 miliseconds
  }

}
else
{
digitalWrite(relaypin2,HIGH);  
digitalWrite(relaypin,LOW);
digitalWrite(D3, LOW);
for (int thisNote = 3; thisNote > 0; thisNote--) {
  //pin D1 controls the sound, emitting each note every 'duration' miliseconds
  tone(D7, melody[thisNote], duration);
  delay(500);  
   // Output the voice after 500 miliseconds
  }
digitalWrite(D2,LOW);
delay(500);
}
String value3 = String(digitalRead(D1));
String value4 = String(digitalRead(D2));
String value5 = String(digitalRead(D3));
String value6 = String(digitalRead(D7));
DweetClient.add(key3, value3); // specifies the args of type "String"
DweetClient.add(key4, value4);
DweetClient.add(key5, value5);
DweetClient.add(key6, value6);
DweetClient.sendAll(THIG_NAME);

}