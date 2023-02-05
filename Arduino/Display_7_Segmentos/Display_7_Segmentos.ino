const int display[14][7] = {    // Declaramos nuestra variable con 7 pines y 14 formas  de la 0 al caractyer D
    {0, 0, 0, 0, 0, 0, 1},   // Digito cero 
    {1, 0, 0, 1, 1, 1, 1},   // Digito uno
    {0, 0, 1, 0, 0, 1, 0},   // Digito dos
    {0, 0, 0, 0, 1, 1, 0},   // Digito tres
    {1, 0, 0, 1, 1, 0, 0},   // Digito cuatro
    {0, 1, 0, 0, 1, 0, 0},   // Digito cinco
    {0, 1, 0, 0, 0, 0, 0},   // Digito seis
    {0, 0, 0, 1, 1, 1, 1},   // Digito siete
    {0, 0, 0, 0, 0, 0, 0},   // Digito ocho
    {0, 0, 0, 0, 1, 0, 0},   // Digito nueve
    {0, 0, 0, 1, 0, 0, 0},   // Caracter A
    {0, 0, 0, 0, 0, 0, 0},   // Caracter B
    {0, 1, 1, 0, 0, 0, 1},   // Caracter C
    {0, 0, 0, 0, 0, 0, 1}    // Caracter D
};
int digitPins[] = {2, 3, 4, 5, 6, 7, 8};

void setup() {
for(int a = 0; a<=7; a++){
  pinMode(digitPins[a], OUTPUT);
}}

void loop() {
   for (int i = 0; i < 14; i++) {   
    for (int j = 0; j < 7; j++) {   
      digitalWrite(digitPins[j], display[i][j]);
    }
    delay(1000);   // Esperar 1 segundo antes de pasar al siguiente dígito o carácter
  }
}