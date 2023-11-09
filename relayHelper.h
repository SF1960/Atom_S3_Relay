#include "esp32-hal-gpio.h"
#include "esp32-hal-gpio.h"
#pragma once

/*********************************************************************************
* Local library for relay control and management
*
* relay::setup()
* relay::latchRelay()
*
*********************************************************************************/
#define R1 2

namespace relay{

  void setup(){
    pinMode(R1, OUTPUT);
    digitalWrite(R1, LOW);
  }

  void latchRelay(){

    bool static on = false;

    if (on){
      digitalWrite(R1, LOW);
      relayOne = 0;
      M5.Lcd.fillRect(40, 45, 60, 40, BLACK);
      M5.Lcd.setTextColor(GREEN);
      M5.Lcd.drawString("OFF", 43, 50, 2);
      M5.Lcd.drawRoundRect(35, 45, 60, 40, 3, GREEN);
    } else {
      digitalWrite(R1, HIGH);
      relayOne = 1;
      M5.Lcd.fillRect(40, 45, 60, 40, BLACK);
      M5.Lcd.setTextColor(RED);
      M5.Lcd.drawString("ON", 50, 50, 2);
      M5.Lcd.drawRoundRect(35, 45, 60, 40, 3, RED);
    }

    on = !on;

  }

}