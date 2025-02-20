#include "esp32-hal-gpio.h"
#pragma once

/*********************************************************************************
* Local library for Atom control and management
*
* atom::setup()               initialise the M5 Atom S3
* atom::connecting()          display connecting message
* atom::defaultScreen()       display the default screen configuration
* atom::screenOn()            turn on display
* atom::screenOff()           turn off display
* atom::brightness()          set the screen's brightness
*
*********************************************************************************/

int width = 0;                           // initialise the width integer
int height = 0;                          // initialise the height integer
#define backLight 16                     // backlight pin

namespace atom{

  void setup(){
    pinMode(backLight, INPUT);           // backlight input pin
    relayOne = false;                    // set the relay cloud variable to false
    relayTwo = true;                     // set the screen cloud variable to true
    inAuto = false;                      // set the screen cloud variable to false
    auto cfg = M5.config();
    AtomS3.begin(cfg);
    width = AtomS3.Lcd.width();          // get the screen's width
    height = AtomS3.Lcd.height();        // get the screen's height
  }

  void connecting(){
    AtomS3.Lcd.fillScreen(BLACK);
    AtomS3.Lcd.setTextColor(CYAN);
    AtomS3.Lcd.drawString("Connecting..", width, height, 2);
  }
 
  void defaultScreen(){
    AtomS3.Lcd.fillScreen(BLACK);
    AtomS3.Lcd.drawRoundRect(0, 0, width, height, 5, GREEN);
    AtomS3.Lcd.setTextSize(1);
    AtomS3.Lcd.setTextColor(CYAN);
    AtomS3.Lcd.drawString("Relay Control", 22, 5, 2);
    AtomS3.Lcd.drawString("> Press screen <", 13, 108, 2);
    AtomS3.Lcd.setTextSize(2);
    AtomS3.Lcd.setTextColor(GREEN);
    AtomS3.Lcd.drawString("OFF", 43, 50, 2);
    AtomS3.Lcd.drawRoundRect(35, 45, 60, 40, 3, GREEN);

    Serial.printf("WIDTH: %d HEIGHT: %d\n", width, height);
  }

  void screenOff(){
    digitalWrite(backLight, LOW);                // turn off backlight - the preffered method, which doesn't seem to work at the moment
    AtomS3.Lcd.setBrightness(0);                 // set the screen brightness to zero (off)
    relayTwo = false;                            // set the screen relay Cloud Variable to False
    Serial.printf("relayTwo: %d",relayTwo);
  }

  void screenOn(){
    digitalWrite(backLight, HIGH);               // turn on backlight - the preffered method, which doesn't seem to work at the moment
    AtomS3.Lcd.setBrightness(screenBrightness);  // set the screen brightness to the value iin the cloud
    relayTwo = true;                             // set the screen relay Cloud Variable to True
    Serial.printf("relayTwo: %d",relayTwo);
  }

  void brightness(){
    AtomS3.Lcd.setBrightness(screenBrightness);  // set the screen's brightness depending on the value of cloud variable
  }

  
}