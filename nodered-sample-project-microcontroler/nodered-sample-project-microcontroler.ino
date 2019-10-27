#include <SimpleDHT.h>
#include <PubSubClient.h>
#include <ESP8266WiFi.h>

//WLAN and MQTT credentials
const char* ssid = "your ssid";
const char* wpa = "your wpa";
const char* server = "your mqtt ip";

WiFiClient myWifiClient;
PubSubClient client(myWifiClient);

const int taster = D6;
const int dhtPin = D5;

SimpleDHT11 dht(dhtPin);

//Debounce for button
const long debounceTime = 200;
volatile unsigned long lastMicros;

//Messwerte
byte temperature = 5;
byte humidity = 5;

void setup() {
  //Wifi Setup
  WiFi.begin(ssid, wpa);
  //Wait until Wifi connected
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
  }

  //MQTT Setup
  client.setServer(server, 1883);
  
  pinMode(taster, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(taster), debounceIsr, FALLING);
}

void loop() {
  if(!client.connected()){
    mqttReconnect();
  }
}

void mqttReconnect(){
  while(!client.connected()){
    client.connect("esp0");  
  }
}

void debounceIsr(){
  if((long)(micros()-lastMicros) >= debounceTime * 1000){
    isr();
    lastMicros = micros();
  }
}

void isr(){
  //todo: DHT22 auslesen
  dht.read(&temperature, &humidity, NULL);
  String message = String((float)temperature) + ";" + String((float)humidity);
  client.publish("debugTopic", message.c_str());
}
