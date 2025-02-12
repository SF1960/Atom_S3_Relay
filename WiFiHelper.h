#pragma once

/*********************************************************************************
* Local library for internet connection and management
*
* wifi::connect()                 attempt to connect to the internet
*
*********************************************************************************/

char ssid[] = "VM3988748_LJ";     //  your network SSID (name)
char pass[] = "nr5jfPxrvxmw";     // your network password
int status = WL_IDLE_STATUS;      // the Wifi radio's status

namespace wifi {

  bool connect(){

  //connect to WiFi
    
  Serial.print("Attempting to connect to WPA SSID: ");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);                  // Connect wifi and return connection status.
  while (WiFi.status() != WL_CONNECTED) {  // If the wifi connection fails. 
    delay(500);                            // delay 0.5s.
    AtomS3.Lcd.print(".");
  }

  Serial.printf("Connected to %s\n", WiFi.SSID());
  AtomS3.Lcd.printf("\n\n ** Connected ** \n\n");
  AtomS3.Lcd.printf(WiFi.SSID().c_str());
  delay(2000);

  return true;                                    // connection successful

  } // connect()

}