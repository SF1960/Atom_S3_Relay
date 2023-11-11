/* 
Sketch generated by the Arduino IoT Cloud Thing "Untitled"
https://create.arduino.cc/cloud/things/6cde6503-fff6-4349-956d-8c245b12d16a 

Arduino IoT Cloud Variables description

The following variables are automatically generated and updated when changes are made to the Thing

int pushButton;
bool relayOne;
bool relayTwo;

Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
which are called when their values are changed from the Dashboard.
These functions are generated with the Thing and added at the end of this sketch.
*/

/**************************************************************************************
* Description:  Arduino CLoud control of M5 relay unit using the Atom S3
* Sketch:       M5_Atom_S3_nov06a.ino
* Version:      1.0
* Version Desc: Original Version
* Board:        Atom S3
* Author:       Steve Fuller
* Website:      https://github.com/SF1960/Atom_S3_Relay.git
* Comments      
***************************************************************************************/
#include <WiFi.h>
#include <M5AtomS3.h>
#include "WiFiHelper.h"
#include "arduino_secrets.h"
#include "thingProperties.h"
#include "atomHelper.h"
#include "relayHelper.h"

void setup() {

  Serial.begin(115200);                  // Initialize serial and wait for port to open:
  delay(1500); 

  atom::setup();                         // start the M5 and obtain screen width and height
  atom::connecting();                    // display connecting information

  // attempt to connect to the internet
  bool connected = wifi::connect(SECRET_SSID, SECRET_OPTIONAL_PASS);

  initProperties();                      // Defined in thingProperties.h

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  atom::defaultScreen();                 // show the default screen
  relay::setup();                        // intialise the relay module

}

void loop() {
  ArduinoCloud.update();

  // show the ~ symbol when connected to Arduino
  if(ArduinoCloud.connected()){
    M5.Lcd.setTextSize(2);
    M5.Lcd.setTextColor(CYAN);
    M5.Lcd.drawString("~", 13, 57, 2);
    M5.Lcd.drawString("~", 100, 57, 2);
  } else {
    M5.Lcd.setTextSize(2);
    M5.Lcd.setTextColor(BLACK);
    M5.Lcd.drawString("~", 13, 57, 2);
    M5.Lcd.drawString("~", 100, 57, 2);
  }

  M5.update();                           // Read the press state of the key.
  if (M5.Btn.wasReleased()) {            // when the screen button is released
    relay::latchRelay();                 // function to toggle the relay
  }
  
}

void onRelayOneChange()  {
  relay::latchRelay();                   // function to toggle the relay
}

void onRelayTwoChange()  {
  // Add your code here to act upon RelayTwo change
}