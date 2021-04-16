#include "stdio.h"
#include "LoRa.h"
#include "ArduinoJson.h"
#include "FreeRTOS.h"
#include<Arduino.h>
class loraMesh
{
  public:
    loraMesh(uint8_t cs, uint8_t rst,uint8_t di0);
    bool init(uint16_t freq);
    void broadcastMap(uint8_t id);
    void sendLora(const char* payload);
  private:
    uint8_t _id;    uint8_t _cs;
    uint8_t _rst;
    uint8_t _di0;
    void on_recive_packet();
};