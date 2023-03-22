#include<ESP8266WiFi.h>
const char* ssid = "udcdocencia";
const char* password = "Universidade.2223";

// Host to Connect to and WIFi client parameters

const char* host = "postman-echo.com";
WiFiClient client;
const int httpPort = 80;


//WiFi Netork Parameters
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
//a small delay is added to initilaize the serial port
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

void loop() {
  // put your main code here, to run repeatedly:
delay(5000);
Serial.print("connecting to ");
Serial.println(host);

//A connection to the website is opned 
if(!client.connect(host,httpPort))
{
Serial.println("Failed Connection");  
return;
};



// Specific URL is Indicated and the Connectionn request is sent

String url ="http://postman-echo.com/get";
Serial.print("Requesting URL:");
Serial.println(url);
client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: "+host+"\r\n" + "Connection: close\r\n\r\n");

// We wait 5 sec for the server response
unsigned long timeout = millis();
while(client.available()==0)
{
  if (millis() - timeout>5000)
{
Serial.println(">>> Client Timeout !");
client.stop();
return;
}  
}

while(client.available())
{
  // The server response is processed

  String line = client.readStringUntil('\r');
  Serial.print(line);
}
Serial.println();
Serial.println("closing conection");
}