/*bibliotecas*/
#include <PubSubClient.h>

#include <UIPEthernet.h>

#include <SPI.h>

byte mac[] = {0x48, 0x67, 0x4B, 0x00, 0x05, 0xB5};
/*variavel mensagen*/
bool message;

/*variavel inteira pino2 de valor 2*/
int pino2 = 2;

/*variavel estado do sensor*/
 bool estado_sensor;
 
  EthernetClient client;
  PubSubClient mqttClient(client);

void setup() {

/*lê o endereco mac*/
  Ethernet.begin(mac);

  Serial.begin(9600);
  
  mqttClient.setServer("54.144.190.205",1883);

  pinMode(pino2,INPUT_PULLUP);
  

}



void loop() {
  mqttClient.connect("lucasSantos");
  
  estado_sensor = digitalRead(pino2);
 
 /*se o estado do sensor for = a 0 ele executa esse trecho*/
  if(estado_sensor == 0){
  message = mqttClient.publish("lucasSantos_t","esta fechado");
  Serial.println("esta fechado");
  }else{
    /*caso nao seja  = a 0 ele executa esse*/
   message = mqttClient.publish("lucasSantos_t","esta aberto");
   Serial.println("esta aberto");
   }
   
 mqttClient.loop();

 

}
