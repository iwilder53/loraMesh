#include "loraMesh.h"
#include "ArduinoJson.h"



void parse_incoming_stream(String to_parse){

DynamicJsonDocument doc(1024);
deserializeJson(doc,to_parse);

uint8_t TYPE = doc["TYPE"];
uint8_t ID = doc["id"];
 if (type == 1 && (ID != _id) ){
    doc.addElement(_id);
    serializeJson(doc,to_parse);
    sendLora(to_parse);     
 }
}