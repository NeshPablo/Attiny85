char Dato;
void setup() {
Serial.begin(9600);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
if (Serial.available()>0){
Dato = Serial.read();
Serial.println(Dato);
if(Dato == 'A'){ // Adelante
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW); 
  }
if(Dato == 'B'){ // Atras
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW); 
  } 
 if(Dato == 'D'){ // parar
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW); 
  } 
  if(Dato == 'C'){ // Izquierda
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW); 
  } 
    if(Dato == 'E'){ // Izquierda
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH); 
  } 
  
  
  }              
}
