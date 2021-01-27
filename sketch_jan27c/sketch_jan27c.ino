#include <PubSubClient.h>

#include <UIPEthernet.h>

#include <SPI.h>

byte mac[] = {0x48, 0x67, 0x4B, 0x00, 0x05, 0xB5};
bool message;
int pino2 = 2;
 bool estado_sensor;
 
  EthernetClient client;
  PubSubClient mqttClient(client);

void setup() {

  Ethernet.begin(mac);

  Serial.begin(9600);
  
  mqttClient.setServer("3.82.94.158",1883);

  Serial.print("o ip do arduino e:");
  Serial.println(Ethernet.localIP());
  
  Serial.print("a mascara de rede do arduino e:");
  Serial.println(Ethernet.subnetMask());
  
  Serial.print("o gateway do arduino e:");
  Serial.println(Ethernet.gatewayIP());

  pinMode(pino2,INPUT_PULLUP);
  Serial.begin(9600);

  delay(5000);

}





void loop() {
  mqttClient.connect("lucasSantos");
  
  estado_sensor = digitalRead(pino2);
 
  if(estado_sensor == 0){
  message = mqttClient.publish("lucasSantos_t","esta fechado");
  }else{
   message = mqttClient.publish("lucasSantos_t","esta aberto");
   }
   
 mqttClient.loop();

 delay(500);
 
}
