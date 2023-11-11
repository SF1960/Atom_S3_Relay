#pragma once

namespace wifi {

  bool connect(String ssid, String password){

    //connect to WiFi
    Serial.printf("Connecting to %s ", ssid);
    M5.Lcd.printf("Connecting.");

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid.c_str(), password.c_str());

    int tries = 0;
    while (WiFi.status() != WL_CONNECTED) {
      M5.Lcd.printf(".");
      Serial.printf(".");
      delay(500);
      if (tries++ >= 5){ return false; } // failed to connect
    }
    
    Serial.printf("Connected to %s", ssid);
    M5.Lcd.printf("\nStarting Arduino..");
    delay(1000);

    return true;                                     // connection successful

  } // connect()

}