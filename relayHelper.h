#include "esp32-hal-gpio.h"
#include "esp32-hal-gpio.h"
#pragma once

/*********************************************************************************
* Local library for relay control and management
*
* relay::setup()                     set up the relay module
* relay::latchRelay()                toggle the relay and set the text 
*
*********************************************************************************/

#define R1 2                         // assign the relay output pin 2 to macro R1

namespace relay{

  void setup(){
    pinMode(R1, OUTPUT);            // set R1 as an output
    digitalWrite(R1, LOW);          // initialise the relay as off
    relayOne = false;               // set the cloud variable for the relay to off
    relayTwo = true;                // set the cloud variable for the screen to on
  }

  void latchRelay(){

    bool static on = true;          // define a static boolean as true

    if (on){
      
      digitalWrite(R1, LOW);        // turn off the relay
      relayOne = false;             // set the cloud variable to 0

      AtomS3.Lcd.fillRect(40, 45, 60, 40, BLACK);
      AtomS3.Lcd.setTextColor(GREEN);
      AtomS3.Lcd.drawString("OFF", 43, 50, 2);
      AtomS3.Lcd.drawRoundRect(35, 45, 60, 40, 3, GREEN);
      AtomS3.Lcd.drawRoundRect(0, 0, width, height, 5, GREEN);

    } else {

      digitalWrite(R1, HIGH);       // turn on the relay
      relayOne = true;              // set the cloud variable to 1

      AtomS3.Lcd.fillRect(40, 45, 60, 40, BLACK);
      AtomS3.Lcd.setTextColor(RED);
      AtomS3.Lcd.drawString("ON", 50, 50, 2);
      AtomS3.Lcd.drawRoundRect(35, 45, 60, 40, 3, RED);
      AtomS3.Lcd.drawRoundRect(0, 0, width, height, 5, RED);
    }

    on = !on;                       // toggle the static variable

  }

  void relay1_ON(){
    
    digitalWrite(R1, HIGH);         // turn on the devices output pin
    relayOne = 1;                   // set the cloud variable to inform the dashboard 
    
  }
  
  void relay1_OFF(){
    
    digitalWrite(R1, LOW);          // turn off the devices outout pin
    relayOne = 0;                   // set the cloud variable to inform the dashboard 
    
  }
  
}