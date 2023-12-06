#include "esp32-hal-gpio.h"
#pragma once

/*********************************************************************************
* Local library for Atom control and management
*
* atom::setup()               initialise the M5 Atom
* atom::connecting()          display connecting 
* atom::defaultScreen()       display the default screen configuration
* atom::screenOn()
* atom::screenOff()
*
*********************************************************************************/

int width = 0;                           // initialise the width integer
int height = 0;                          // initialise the height integer
#define backLight 16                     // backlight pin

namespace atom{

  void setup(){
    pinMode(backLight, INPUT);           // backlight input pin
    M5.begin(true, true, false, false);  // Init M5AtomS3.
    width = M5.Lcd.width();              // get the screen's width
    height = M5.Lcd.height();            // get the screen's height
  }

  void connecting(){
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setTextColor(CYAN);
    M5.Lcd.drawString("Connecting..", width, height, 2);
  }
 
  void defaultScreen(){
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.drawRoundRect(0, 0, width, height, 5, GREEN);
    M5.Lcd.setTextColor(CYAN);
    M5.Lcd.drawString("Relay Control", 22, 5, 2);
    M5.Lcd.drawString("> Press screen <", 13, 108, 2);
    M5.Lcd.setTextSize(2);
    M5.Lcd.setTextColor(GREEN);
    M5.Lcd.drawString("OFF", 43, 50, 2);
    M5.Lcd.drawRoundRect(35, 45, 60, 40, 3, GREEN);

    USBSerial.printf("WIDTH: %d HEIGHT: %d\n", width, height);
  }

  void screenOFF(){
    digitalWrite(backLight, LOW);        // turn off backlight
  }

  void screenOn(){
    digitalWrite(backLight, HIGH);       // turn on backlight
  }

}