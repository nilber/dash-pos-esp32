#include <Arduino.h>
#include "SPI.h"
#include "SD.h"
#include <util.h>
#include <screen.h>


void initHeader() 
{
    Serial.begin(9600);    
    delay(500);
    Serial.println(F("\n#####################\n"));  
    Serial.printf("CPU frequency: %u MHz\n\n", ESP.getCpuFreqMHz());
    Serial.printf("RAM: %u bytes\n", ESP.getFreeHeap());
    // Serial.printf("ChipID: %s \n", String(ESP.getChipId(), HEX).c_str());
    Serial.println(F("#####################"));

}