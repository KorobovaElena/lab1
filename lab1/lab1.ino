#include "button.h"

#define PIN_BUTTON 5
Button button(PIN_BUTTON);

int lampsPins[] = {6, 7, 8};

#define totalModes 5;
int currentMode;
int blinkTime;

bool allLights;

void setup() {
  allLights = false;
  blinkTime = millis();
  currentMode = 0;
}

void loop() {
  if (button.wasPressed())
  {
    currentMode = (currentMode + 1) % totalModes;
  }
  
  switch (currentMode)
  {
    case 1:
     turn_on_all();
    break;
    case 2:
     blink_all(500);
    break;
    case 3:
     blink_all(250);
    break;
    case 4:
     blink_all(100);
    break;
    default:
      turn_off_all();
    break;
  }
}

void set_brightness(int pin, int brightness) {
  analogWrite(pin, 255-brightness);
}

void turn_off_all() {
  for (int i = 0; i < sizeof(lampsPins)/sizeof(int); i++)
  {
    set_brightness(i, 0);
  }
  allLights = false;
}

void turn_on_all() {
  for (int i = 0; i < sizeof(lampsPins)/sizeof(int); i++)
  {
    set_brightness(i, 255);
  }
  allLights = true;
}

void blink_all(unsigned long delayTime) {
  if (millis() - blinkTime >= delayTime)
  {
    if (allLights)
      turn_off_all();
    else
      turn_on_all();
    blinkTime = millis();
  }
}
