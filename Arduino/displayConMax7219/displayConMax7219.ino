#include "LedControl.h"

LedControl lc=LedControl(12,11,10,1);

unsigned long delaytime=250;

void setup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);
}
void loop() { 
 hola();
 delay(3000);
 lc.clearDisplay(0);
 arduino();
 delay(3000);
 lc.clearDisplay(0);
 progra();
 delay(3000);
 lc.clearDisplay(0);
}
void arduino(){
 lc.setChar(0,7,'A',false);
 lc.setRow(0,6,0x05);
 lc.setChar(0,5,'d',false);
 lc.setRow(0,4,0x1c);
 lc.setRow(0,3,B00010000);
 lc.setRow(0,2,0x15);
 lc.setRow(0,1,0x1D);
}
void hola(){
 lc.setChar(0,7,'H',false);
 lc.setChar(0,6,0,false);
 lc.setChar(0,5,'L',false);
 lc.setChar(0,4,'A',false);
}
void progra(){
 lc.setChar(0,7,'p',false);
 lc.setRow(0,6,0x05);
 lc.setRow(0,5,0x1D);
 lc.setRow(0,4,B1111011);
 lc.setRow(0,3,0x05);
 lc.setChar(0,2,'A',false);



}

