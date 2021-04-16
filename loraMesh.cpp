#include "loraMesh.h"


loraMesh::loraMesh(uint8_t cs, uint8_t rst,uint8_t di0)
{
    _cs = cs;
    _rst = rst;
    _di0 = di0;
    LoRa.setPins(_cs,_rst,_di0);
}

bool loraMesh::init(uint16_t freq)
{
   if (!LoRa.begin(freq))
    {
       // Serial.println("LoRa init failed. Check your connections.");
        return false    ; // if failed, do nothing
    }
    return true;
    broadcastMap(_id);
    on_recive_packet();
}

void loraMesh::broadcastMap(uint8_t id)
{  String output;
    DynamicJsonDocument doc(1024);
    doc["id"] = id;
    serializeJson(doc,output);
    sendLora(output.c_str());
}
void sendLora(const char* payload){
    LoRa.beginPacket();
    LoRa.print(payload);
    LoRa.endPacket();
}
    void on_recive_packet(){
     for(;;){ delay(10);
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());    

    }

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }  } 
    }