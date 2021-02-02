# atividade_Redes_ultimaSprint
## objetivo

* objetivo desse projeto é utilizar um Arduino Uno mais um Sensor Magnético para monitorar se a porta de um Rack
de Rede está ABERTO ou FECHADO; enviar essa informação via Internet utilizando o protocolo MQTT (Message
Queuing Telemetry Transport) para um servidor MQTT hospedado na Amazon Web Service (AWS) e exibir a informação
em um cliente MQTT (MQTT Dash) instalado em um Smartphone, conforme imagem abaixo.

![img1](/imagens/1.PNG)

## ultilizando as bibliotecas

* UIPEthernet (conexão do ENC28J60 com o Arduino)
* PubSubClient (cliente MQTT para o Arduino)

## Materiais

* Arduino Uno
* Módulo Ethernet (ENC28J60)
* Sensor Magnético (MC-38)
* Jumpers

## Circuito

![img2](imagens/2.PNG)


autor: Lucas Santos

[LinkedIn](http://www.linkedin.com/in/lucas-costa-391919197)





/*bibliotecas*/
#include <PubSubClient.h>

#include <UIPEthernet.h>

#include <SPI.h>

byte mac[] = {0x48, 0x67, 0x4B, 0x00, 0x05, 0xB5};

/*variaveis mensagem recebe dois valores*/
bool message;

/*variavel do pino inteira de valor 2*/
int pino2 = 2;

/*variaveis estado do sensor */
bool estado_sensor;
 
  EthernetClient client;
  PubSubClient mqttClient(client);

void setup() {

/*lê o endereco mac*/
  Ethernet.begin(mac);

  Serial.begin(9600);
  
  mqttClient.setServer("3.82.94.158",1883);

/*retorna o valor do ip*/
  Serial.print("o ip do arduino e:");
  Serial.println(Ethernet.localIP());

  /*retorna a mascara de rede*/
  Serial.print("a mascara de rede do arduino e:");
  Serial.println(Ethernet.subnetMask());

  /*retorna o gateway*/
  Serial.print("o gateway do arduino e:");
  Serial.println(Ethernet.gatewayIP());

  pinMode(pino2,INPUT_PULLUP);
  Serial.begin(9600);

  delay(5000);

}





void loop() {
  mqttClient.connect("lucasSantos");
  
  estado_sensor = digitalRead(pino2);

 /*se o estado do sernsor for  = a zero entao ele retornara a mensagem de fechado */
  if(estado_sensor == 0){
  message = mqttClient.publish("lucasSantos_t","esta fechado");
  }else{
    /*caso nao for =0 ele ira executar isso */
   message = mqttClient.publish("lucasSantos_t","esta aberto");
   }

   /*repete as acoes*/
 mqttClient.loop();

 delay(500);
 
}
