#pragma once

/*********************************************************************************
* Local library for Atom control and management
*
* atom::setup()
*
*********************************************************************************/

int width = 0;
int height = 0;

namespace atom{

  void setup(){
    M5.begin(true, true, false, false);  // Init M5AtomS3.
    width = M5.Lcd.width();
    height = M5.Lcd.height();
    M5.Lcd.drawRoundRect(0, 0, width, height, 5, BLUE);
    M5.Lcd.setTextColor(CYAN);
    M5.Lcd.drawString("Relay Control", 20, 5, 2);
    M5.Lcd.drawString("> Press screen <", 13, 108, 2);
    M5.Lcd.setTextSize(2);
    M5.Lcd.setTextColor(GREEN);
    M5.Lcd.drawString("OFF", 43, 50, 2);
    M5.Lcd.drawRoundRect(35, 45, 60, 40, 3, GREEN);

    USBSerial.printf("WIDTH: %d HEIGHT: %d\n", width, height);
  }

}