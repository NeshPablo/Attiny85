int s1, s2, s3, s4, s5; String tmp;
int Bin1 = 9, Bin2 = 10, Ain1 = 7, Ain2 = 8;
int pwmA = 6, pwmB = 11;
int Vmax = 75, Vmd = 20, vb = 55;
void setup ( ) {
 //  Serial . begin ( 9600 ) ;
   pinMode(Bin1, OUTPUT);
   pinMode(Bin2, OUTPUT);
   pinMode(Ain1, OUTPUT);
   pinMode(Ain2, OUTPUT);
   pinMode(pwmA, OUTPUT);
   pinMode(pwmB, OUTPUT);   
}
void loop ( ) {
   s1 = digitalRead ( A1 ) ; s2 = digitalRead ( A2 ) ;
   s3 = digitalRead ( A3 ) ; s4 = digitalRead ( A4 ) ; 
   s5 = digitalRead ( A5 ) ;

 //  tmp = "+
  //S1="" + String ( s1 ) + " S2=" + String ( s2 ) + " S3=" + String ( s3 ) + " S4=" + String ( s4 ) + " S5=" + String ( s5 ) ;
 //  Serial . println ( tmp ) ;


if(s1 == 1 && s5 == 1 ) {
analogWrite(pwmA, Vmax);
analogWrite(pwmB, Vmax);
digitalWrite(Ain1, HIGH);
digitalWrite(Ain2, LOW);
digitalWrite(Bin1,HIGH);
digitalWrite(Bin2, LOW); 
}
else if(s1 == 0 && s5 == 1 ) {
analogWrite(pwmA, 40);
analogWrite(pwmB, 150);
digitalWrite(Ain1, LOW);
digitalWrite(Ain2, HIGH);
digitalWrite(Bin1,HIGH);
digitalWrite(Bin2, LOW); 
}
else if(s1 == 1 && s5 == 0 ) {
analogWrite(pwmA, 150);
analogWrite(pwmB, 40);
digitalWrite(Ain1, HIGH);
digitalWrite(Ain2, LOW);
digitalWrite(Bin1,LOW);
digitalWrite(Bin2, HIGH); 
}/*
if( s2 == 1 && s4 == 1 && s1 == 1 && s5 == 1 ) {
analogWrite(pwmA, Vmax);
analogWrite(pwmB, Vmax);
digitalWrite(Ain1, HIGH);
digitalWrite(Ain2, LOW);
digitalWrite(Bin1,HIGH);
digitalWrite(Bin2, LOW); 
}
else if(s2 == 0 && s4 == 1 && s1 == 0 && s5 == 1 ) {
analogWrite(pwmA, Vmax);
analogWrite(pwmB, Vmd);
digitalWrite(Ain1, LOW);
digitalWrite(Ain2, LOW);
digitalWrite(Bin1,HIGH);
digitalWrite(Bin2, LOW); 
}
else if(s2 == 1 && s4 == 0 && s1 == 1 && s5 == 0 ) {
analogWrite(pwmA, Vmax);
analogWrite(pwmB, Vmd);
digitalWrite(Ain1, HIGH);
digitalWrite(Ain2, LOW);
digitalWrite(Bin1,LOW);
digitalWrite(Bin2, LOW); 
}
else if(s1 == 0 && s5 == 1 && s2 == 0 && s4 == 1 ) {
analogWrite(pwmA, 0);
analogWrite(pwmB, 200);
digitalWrite(Ain1, LOW);
digitalWrite(Ain2, LOW);
digitalWrite(Bin1,HIGH);
digitalWrite(Bin2, LOW); 
}
else if(s1 == 0 && s5 == 0 && s2 == 1 && s4 == 1 ) {
analogWrite(pwmA, 200);
analogWrite(pwmB, 0);
digitalWrite(Ain1, HIGH);
digitalWrite(Ain2, LOW);
digitalWrite(Bin1,LOW);
digitalWrite(Bin2, LOW); 
}*/
else {
analogWrite(pwmA, 0);
analogWrite(pwmB, 0);  
}/*
else if(s1 == 1 && s2 == 1 && s3 == 1 && s4 == 1 && s5 == 0) {
analogWrite(pwmA, Vmd);
analogWrite(pwmB, Vmax);
digitalWrite(Ain1, HIGH);
digitalWrite(Ain2, LOW);
digitalWrite(Bin1,HIGH);
digitalWrite(Bin2, LOW); 
}
else if(s1 == 1 && s2 == 1 && s3 == 1 && s4 == 0 && s5 == 1) {
analogWrite(pwmA, vb);
analogWrite(pwmB, Vmax);
digitalWrite(Ain1, HIGH);
digitalWrite(Ain2, LOW);
digitalWrite(Bin1,HIGH);
digitalWrite(Bin2, LOW); 
}
else if(s1 == 1 && s2 == 0 && s3 == 1 && s4 == 1 && s5 == 1) {
analogWrite(pwmA, Vmd);
analogWrite(pwmB, Vmax);
digitalWrite(Ain1, HIGH);
digitalWrite(Ain2, LOW);
digitalWrite(Bin1,HIGH);
digitalWrite(Bin2, LOW); 
}
else if(s1 == 0 && s2 == 1 && s3 == 1 && s4 == 1 && s5 == 1) {
analogWrite(pwmA, vb);
analogWrite(pwmB, Vmax);
digitalWrite(Ain1, HIGH);
digitalWrite(Ain2, LOW);
digitalWrite(Bin1,HIGH);
digitalWrite(Bin2, LOW); 
}
else if(s1 == 1 && s2 == 1 && s3 == 1 && s4 == 1 && s5 == 1) {
analogWrite(pwmA, 0);
analogWrite(pwmB, 0);
digitalWrite(Ain1, LOW);
digitalWrite(Ain2, LOW);
digitalWrite(Bin1,LOW);
digitalWrite(Bin2, LOW); 
}

 /*
if(s3 == 0){
analogWrite(pwmA, Vmax);
analogWrite(pwmB, Vmax);
digitalWrite(Ain1, HIGH);
digitalWrite(Ain2, LOW);
digitalWrite(Bin1,HIGH);
digitalWrite(Bin2, LOW);   
}
else if(s2 == 0){
analogWrite(pwmA, Vmd);
analogWrite(pwmB, Vmax);
digitalWrite(Ain1, HIGH);
digitalWrite(Ain2, LOW);
digitalWrite(Bin1,HIGH);
digitalWrite(Bin2, LOW); 
}
else if(s4 == 0){
analogWrite(pwmA,Vmax);
analogWrite(pwmB, Vmd);
digitalWrite(Ain1, HIGH);
digitalWrite(Ain2, LOW);
digitalWrite(Bin1,HIGH);
digitalWrite(Bin2, LOW); 
}
else {
analogWrite(pwmA, 0);
analogWrite(pwmB, 0);
digitalWrite(Ain1, LOW);
digitalWrite(Ain2, LOW);
digitalWrite(Bin1,LOW);
digitalWrite(Bin2, LOW); 
}*/

}
