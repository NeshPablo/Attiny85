int leds[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
int n = 10;
int state = 0;
int direction = 1;
int btn_Pause = 12;
int btn_Reset = analogRead(A0);
int btn_Start = 13;
int tiempo = 0;
int valor;
int var = A1;

bool isRunning = false;


void setup() {
  Serial.begin(9600);
  for (int i = 0; i < n; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(btn_Pause, INPUT_PULLUP);
  pinMode(btn_Reset, INPUT_PULLUP);
  pinMode(btn_Start, INPUT_PULLUP);
}

void loop() {
  valor=map(analogRead(var),0,1023,250,3000);
  Serial.println(valor);

  for(int y = 20; y >= valor; y++){
    
  }
    
  
  if (analogRead(btn_Reset) >= 512) {
    state = 0;
    direction = 1;
    isRunning = false;
    for (int i = 0; i < n; i++) {
      digitalWrite(leds[i], LOW);
    }
  }
  if (digitalRead(btn_Start) == LOW) {
    isRunning = !isRunning;
  }
  if (isRunning) {
    for (int i = 0; i < n; i++) {
      digitalWrite(leds[i], LOW);
    }
    digitalWrite(leds[state], HIGH);
    state += direction;
    if (state == n - 1 || state == 0) {
      direction = -direction;
    }
    if (digitalRead(btn_Pause) == LOW) {
      isRunning = !isRunning;
    }
    delay(valor);
  }
}