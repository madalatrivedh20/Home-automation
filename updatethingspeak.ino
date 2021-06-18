#include "ThingSpeak.h"
#include <ESP8266WiFi.h>

//Replace your wifi credentials here
const char* ssid     = "3vedh";
const char* password = "tri12vedh";

//change your channel number here
unsigned long channel = 824364;

//1,2 and 3 are channel fields. You don't need to change if you are following this tutorial. However, you can modify it according to your application
unsigned int led1 = 1;
unsigned int led2 = 2;
unsigned int led3 = 3;
unsigned int led4 = 4;
unsigned int led5 = 5;
unsigned int led6 = 6;
unsigned int fan1 = 1;
unsigned int fan2 = 2;
unsigned int fan3 = 3;
unsigned int fan4 = 4;
unsigned int fan5 = 5;
unsigned int fan6 = 6;


WiFiClient  client;


void setup() {
  Serial.begin(115200);
  delay(100);
  
  pinMode(16, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(16, 0);
  digitalWrite(14, 0);
  digitalWrite(13, 0);
  digitalWrite(12, 0);
  digitalWrite(15, 0);
  digitalWrite(3, 0);
  digitalWrite(5, 0);
  digitalWrite(4, 0);
  digitalWrite(0, 0);
  digitalWrite(1, 0);
  digitalWrite(2, 0);
  digitalWrite(10, 0);
  // We start by connecting to a WiFi network
 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());
  ThingSpeak.begin(client);

}

 
 
 
void loop() {

  //get the last data of the fields
  
  int led_1 = ThingSpeak.readFloatField(channel, led1);
  int led_2 = ThingSpeak.readFloatField(channel, led2);
  int led_3 = ThingSpeak.readFloatField(channel, led3);
  int led_4 = ThingSpeak.readFloatField(channel, led4);
  int led_5 = ThingSpeak.readFloatField(channel, led5);
  int led_6 = ThingSpeak.readFloatField(channel, led6);
  int fan_1 = ThingSpeak.readFloatField(channel, led1);
  int fan_2 = ThingSpeak.readFloatField(channel, led2);
  int fan_3 = ThingSpeak.readFloatField(channel, led3);
  int fan_4 = ThingSpeak.readFloatField(channel, led4);
  int fan_5 = ThingSpeak.readFloatField(channel, led5);
  int fan_6 = ThingSpeak.readFloatField(channel, led6);

  if(led_1 == 1){
    digitalWrite(16, 1);
    Serial.println("led1 is On..!");
  }
  else if(led_1 == 0){
    digitalWrite(16, 0);
    Serial.println("led1 is Off..!");
  }

  if(led_2 == 1){
    digitalWrite(14, 1);
    Serial.println("led2 is On..!");
  }
  else if(led_2 == 0){
    digitalWrite(14, 0);
    Serial.println("led2 is Off..!");
  }

  if(led_3 == 1){
    digitalWrite(13, 1);
    Serial.println("led3 is On..!");
  }
  else if(led_3 == 0){
    digitalWrite(13, 0);
    Serial.println("led3 is Off..!");
  }

  if(led_4 == 1){
    digitalWrite(12, 1);
    Serial.println("led4 is On..!");
  }
  else if(led_4 == 0){
    digitalWrite(12, 0);
    Serial.println("led4 is Off..!");
  }

  if(led_5 == 1){
    digitalWrite(15, 1);
    Serial.println("led5 is On..!");
  }
  else if(led_5 == 0){
    digitalWrite(15, 0);
    Serial.println("led5 is Off..!");
  }

  if(led_6 == 1){
    digitalWrite(3, 1);
    Serial.println("led6 is On..!");
  }
  else if(led_6 == 0){
    digitalWrite(3, 0);
    Serial.println("led6 is Off..!");
  }

  if(fan_1 == 2){
    digitalWrite(5, 1);
    Serial.println("fan1 is On..!");
  }
  else if(fan_1 == 3){
    digitalWrite(5, 0);
    Serial.println("fan1 is Off..!");
  }

  if(fan_2 == 2){
    digitalWrite(4, 1);
    Serial.println("fan2 is On..!");
  }
  else if(fan_2 == 3){
    digitalWrite(4, 0);
    Serial.println("fan2 is Off..!");
  }

  if(fan_3 == 2){
    digitalWrite(0, 1);
    Serial.println("fan3 is On..!");
  }
  else if(fan_3 == 3){
    digitalWrite(0, 0);
    Serial.println("fan3 is Off..!");
  }

  if(fan_4 == 2){
    digitalWrite(1, 1);
    Serial.println("fan4 is On..!");
  }
  else if(fan_4 == 3){
    digitalWrite(1, 0);
    Serial.println("fan4 is Off..!");
  }

  if(fan_5 == 2){
    digitalWrite(2, 1);
    Serial.println("fan5 is On..!");
  }
  else if(fan_5 == 3){
    digitalWrite(2, 0);
    Serial.println("fan5 is Off..!");
  }

  if(fan_6 == 2){
    digitalWrite(10, 1);
    Serial.println("fan6 is On..!");
  }
  else if(fan_6 == 3){
    digitalWrite(10, 0);
    Serial.println("fan6 is Off..!");
  }
    
  Serial.println(led_1);
  Serial.println(led_2);
  Serial.println(led_3);
  Serial.println(led_4);
  Serial.println(led_5);
  Serial.println(led_6);
  Serial.println(fan_1);
  Serial.println(fan_2);
  Serial.println(fan_3);
  Serial.println(fan_4);
  Serial.println(fan_5);
  Serial.println(fan_6);
  delay(5000);

}
