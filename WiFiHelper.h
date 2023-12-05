#pragma once

/*********************************************************************************
* Local library for internet connection and management
*
* wifi::connect()                 attempt to connect to the internet
*
*********************************************************************************/

namespace wifi {

  bool connect(){

    //connect to WiFi
    Serial.printf("Connect to Select_WiFi\n");
    M5.Lcd.printf("Connect to \n");
    M5.Lcd.printf("Select_WiFi on\n");
    M5.Lcd.printf("on a device and\n");
    M5.Lcd.printf("choose your network.\n");
    M5.Lcd.printf("Enter your password.");

    // use WiFiManager library to obtain available WiFi networks
    WiFi.mode(WIFI_STA);
    WiFiManager wm;
    //wm.resetSettings(); //uncomment to force selecting WiFi network 
    bool res;
    res = wm.autoConnect("Select_WiFi","");
    
    Serial.printf("Connected to %s", WiFi.SSID());
    M5.Lcd.printf("\nConnected %s\n", WiFi.SSID().c_str());
    delay(1000);

    return true;                                    // connection successful

  } // connect()

}