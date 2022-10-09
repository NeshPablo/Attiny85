//Definomos las notas que utilizaremos
#define sol  392
#define la 440
#define mi 330
#define re 587
#define si 493
#define la 440
#define do 523
#define fa 698
#define mi1 659
int i = 0, a = 0;
int b=900, d=450, e=225;
int tempo[] = {
  d, e, d, b, d, e, d, b, b, d, 
  b, d, b, d, b, b, d, d, e, d, d,
  e, d, b, b, d, d, e, d, d, e, d,
  b, b, d, d, e, d, b, b, d, e, d,
  d, e, d, b};
int melodia[] = {
  sol, la, sol, mi, sol, la, sol, mi, re, re,
   si, si, do, do, sol, la, la, do, si, la, sol,
   la, sol, mi, la, la, do, si, la, sol, la, sol, 
   mi, re, re, fa, re, si, do, mi1, do, sol, mi, 
   sol, fa, re, do};
int buzzer = 12;
int estado1[] = {1,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,1,0,1,0,0,1,0,0,1};
int estado2[] = {0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1};
int estado3[] = {0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,0,0,1,1};
void setup(){
  pinMode(buzzer, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}
void loop(){
for(i=0; i<47;i++){
  tone(buzzer, melodia[i]);
  digitalWrite(3, estado1[i]);
  digitalWrite(4, estado2[i]);
  digitalWrite(5, estado3[i]);
  delay(tempo[i]);  
  noTone(buzzer);
}}

 