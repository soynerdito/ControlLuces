/*********
  Rui Santos
  Complete project details at http://randomnerdtutorials.com  
*********/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include "htmlcode.h"
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPUpdateServer.h>


MDNSResponder mdns;

// Replace with your network credentials
const char* ssid = "...";
const char* password = "...";

ESP8266WebServer server(80);
ESP8266HTTPUpdateServer httpUpdater;

String webPage = "";

int ledPin = 13; // GPIO13
int relayPin = 12; // GPIO12

void turnOn(){
   digitalWrite(ledPin, LOW);
   digitalWrite(relayPin, HIGH);
 }

 void turnOff(){
   digitalWrite(ledPin, HIGH);
   digitalWrite(relayPin, LOW);
 }

String renderHtml(void){
  webPage = HTML_BODY;  
  webPage += "<hr color=";
  if( digitalRead(ledPin) == 0 ){
    webPage += "\"#4CAF50\"";
  }else{
    webPage += "\"#ff4d4d\"";
  }
  webPage += "; size=\"30\" >";
  webPage +=  HTML_END; 
  return webPage;
}

void setup(void){
  // preparing GPIOs
  pinMode(ledPin, OUTPUT);  
  pinMode(relayPin, OUTPUT);

  turnOff();

  WiFi.mode(WIFI_STA);
  delay(1000);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    digitalWrite(ledPin, !digitalRead(ledPin));
    delay(250);
    Serial.print(".");
  }
  digitalWrite(ledPin, LOW);
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  if (mdns.begin("piedra", WiFi.localIP())) {
    Serial.println("MDNS responder started");
  }
  
  server.on("/", [](){
    server.send(200, "text/html", renderHtml());
  });
  server.on("/socket1On", [](){
    turnOn();
    delay(100);
    server.send(200, "text/html", renderHtml());    
  });
  server.on("/socket1Off", [](){
    turnOff();
    delay(100);
    server.send(200, "text/html", renderHtml());    
     
  });

  server.on("/status", [](){
    server.send(200, "text/html", String(digitalRead(relayPin)==0?1:0) );
  });
  
  httpUpdater.setup(&server);
  server.begin();
  Serial.println("HTTP server started");
}
 
void loop(void){
  server.handleClient();
} 
