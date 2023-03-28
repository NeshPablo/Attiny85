#include <Stepper.h>
#include <LiquidCrystal_I2C.h> 

LiquidCrystal_I2C lcd (0x27, 16, 2);
int rev = 2048;
int velocidad = 10;

Stepper myStep (rev, 8, 10, 9, 11);

int estadoMotor = 0;
int contadorPasos = 0;
int seconds = 0;
int btn1 = 2, btn2 = 3, btn3 = 4, btn4 = 5, btn5 = 6, btn6 = 7; //
int ultBtn = 0;

void setup()
{
  lcd.begin(16, 2);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(btn4, INPUT);
  pinMode(btn5, INPUT);
  pinMode(btn6, INPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  myStep.setSpeed(10);
  myStep.step(-contadorPasos);
}

void loop()
{
  lcd.setCursor(0, 0);
  lcd.print("Estado: ");
  lcd.setBacklight(1);
  if(digitalRead(btn1) == HIGH){
    if(ultBtn != 1) {
      lcd.clear();
      lcd.setCursor(8, 0);
      lcd.print("Reversa");
      lcd.setBacklight(1);
      myStep.setSpeed(10);
      myStep.step(-contadorPasos);
      estadoMotor = 0;
      contadorPasos = 0; 
      ultBtn = 1;
    }    
  } else if(digitalRead(btn2) == HIGH){
    if(ultBtn != 2) {
      lcd.clear();
      lcd.setCursor(8, 0);
      lcd.print("Primera");
      lcd.setBacklight(1);
      myStep.setSpeed(10);
      myStep.step(350 - contadorPasos);
      estadoMotor = 1;
      contadorPasos = 350;  
      ultBtn = 2;
    }    
  } else if(digitalRead(btn3) == HIGH){
    if(ultBtn != 3) {
      lcd.clear();
      lcd.setCursor(8, 0);
      lcd.print("Segunda");
      lcd.setBacklight(1);
      myStep.setSpeed(10);
      myStep.step(500 - contadorPasos);
      estadoMotor = 2;
      contadorPasos = 500;
      ultBtn = 3;
    }    
  } else if(digitalRead(btn4) == HIGH){
    if(ultBtn != 4) {
      lcd.clear();
      lcd.setCursor(8, 0);
      lcd.print("Tercera");
      lcd.setBacklight(1);
      myStep.setSpeed(10);
      myStep.step(850 - contadorPasos);
      estadoMotor = 3;
      contadorPasos = 850;
      ultBtn = 4;
    }    
  } else if(digitalRead(btn5) == HIGH){
    if(ultBtn != 5) {
      lcd.clear();
      lcd.setCursor(8, 0);
      lcd.print("Cuarta");
      lcd.setBacklight(1);
      myStep.setSpeed(10);
      myStep.step(1000 - contadorPasos);
      estadoMotor = 4;
      contadorPasos = 1000;
      ultBtn = 5;
    }    
  } 
  else if(digitalRead(btn6) == HIGH){
    if(ultBtn != 6) {
      lcd.clear();
      lcd.setCursor(8, 0);
      lcd.print("Quinta");
      lcd.setBacklight(1);
      myStep.setSpeed(10);
      myStep.step(1500 - contadorPasos);
      estadoMotor = 5;
      contadorPasos = 1500;
      ultBtn = 6;
    }    
  } 
}

