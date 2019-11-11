#include "button.h"

#define PIN_BUTTON 5
Button button(PIN_BUTTON);

int lampsPins[] = {6, 7, 8};

#define totalModes 4;
int currentMode;

int delayTime;
int stepspeed;

void setup() {
  currentMode = 0;
  delayTime = 500;
}

void loop() {
  if (button.wasPressed())
  {
    currentMode = (currentMode + 1) % totalModes;
  }
  
  switch (currentMode)
  {
    case 1:
      stepspeed = 1;
      delayTime = 500;
    break;
    case 2:
      stepspeed = 5;
      delayTime = 250;
    break;
    case 3:
      stepspeed = 25;
      delayTime = 100;
      break;
    default:
    
    break;
  }
}
