# atividade_Redes_ultimaSprint
## objetivo

* objetivo desse projeto é utilizar um Arduino Uno mais um Sensor Magnético para monitorar se a porta de um Rack
de Rede está ABERTO ou FECHADO; enviar essa informação via Internet utilizando o protocolo MQTT (Message
Queuing Telemetry Transport) para um servidor MQTT hospedado na Amazon Web Service (AWS) e exibir a informação
em um cliente MQTT (MQTT Dash) instalado em um Smartphone, conforme imagem abaixo.

![img1](/imagens/1.PNG)

## ultilizando as bibliotecas


[ UIPEthernet ]( https://github.com/UIPEthernet/UIPEthernet/archive/v2.0.9.zip.)(conexão do ENC28J60 com o Arduino)

[ PubSubClient ]( https://github.com/knolleary/pubsubclient/archive/v2.8.zip.)(cliente MQTT para o Arduino)

## Materiais

* Arduino Uno
* Módulo Ethernet (ENC28J60)
* Sensor Magnético (MC-38)
* Jumpers

## Circuito

![img2](imagens/2.PNG)


autor: Lucas Santos

[Linkedin](http://www.linkedin.com/in/lucas-costa-391919197)

