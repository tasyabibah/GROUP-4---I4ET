#include "dweetESP8266.h"

#define THIG_NAME "ie4tgroup4lab5"

const char* ssid= "Tech_D9756536";
const char* password = "37GcDqKd7uD6";


dweet DweetClient;

char *key2 = "waterlevel2"; //

int adc_id = A0;
int HistoryValue = 0;
char printBuffer [128];

void setup() {
  // put your setup code here, to run once:

Serial.begin(115200);
delay(10);



//Conecting to a WiFi network

Serial.println();
Serial.println();
Serial.print(ssid);
WiFi.begin(ssid,password);
while(WiFi.status()!=WL_CONNECTED)
{
  delay(500);
Serial.print(".");
}
Serial.println("");
Serial.println("WIFI Conneted :");
Serial.println("IP Address");
Serial.println(WiFi.localIP());
}

char val[16];

void loop() {




  // put your main code here, to run repeatedly:

// Water level 1
int value = analogRead(adc_id); // get adc value
if(((HistoryValue>-value) && ((HistoryValue - value) >10)) || ((HistoryValue<value) && ((value - HistoryValue) > 10)))
{

sprintf(printBuffer,"ABC%d level is %d\n", adc_id, value);
Serial.print(printBuffer);
HistoryValue = value;

}

String val = String(analogRead(A0));
DweetClient.add(key2, val);
DweetClient.sendAll(THIG_NAME);

// Main Code


delay(500);

}