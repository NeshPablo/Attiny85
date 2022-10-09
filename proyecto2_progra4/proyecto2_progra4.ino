const int sol = 159;
const int la = 142;
const int mi = 190;
const int re = 213;
const int si = 127;
const int doq = 239;
const int fa = 179;
const int mi1 = 190;

int i = 0, a = 0;
int b=500, d=250, e=125;
int tempo[] = {
  d, e, d, b, d, e, d, b, b, d, 
  b, d, b, d, b, b, d, d, e, d, d,
  e, d, b, b, d, d, e, d, d, e, d,
  b, b, d, d, e, d, b, b, d, e, d,
  d, e, d, b};
int melodia[] = {
  sol, la, sol, mi, sol, la, sol, mi, re, re,
   si, si, doq, doq, sol, la, la, doq, si, la, sol,
   la, sol, mi, la, la, doq, si, la, sol, la, sol, 
   mi, re, re, fa, re, si, doq, mi1, doq, sol, mi, 
   sol, fa, re, doq};
int estado1[] = {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1};
void setup() {
 pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
}
void loop() {
  playTune();
  delay(100);
}
void TinyTone(unsigned char divisor, unsigned char octave, unsigned long duration)
{
  TCCR1 = 0x90 | (11-octave); // for 8MHz clock
  OCR1C = divisor-1;         // set the OCR
  delay(duration);
  TCCR1 = 0x90;              // stop the counter
}
void playTune(void)
{
for(i=0; i<47;i++){
  TinyTone(melodia[i],6, tempo[i]);
  digitalWrite(0, estado1[i]);
  digitalWrite(2, estado1[i]);
  delay(tempo[i]);  
}
}
