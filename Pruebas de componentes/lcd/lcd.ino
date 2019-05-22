#include <UTFT.h>

// Declare which fonts we will be using
extern uint8_t SmallFont[];

UTFT myGLCD(ITDB18SP,7,8,9,5,6);// Remember to change the model parameter to suit your display module!

void setup()
{
  randomSeed(analogRead(0));
  
// Setup the LCD
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  myGLCD.clrScr();

}


void loop() {
  myGLCD.setColor(0,0,0);
  myGLCD.fillRect(1,14,158,113);

  for (int i=0; i<5000; i++)
  {
    myGLCD.setColor(random(255), random(255), random(255));
    myGLCD.drawPixel(2+random(156), 16+random(95));
  }

}
