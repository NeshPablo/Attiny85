int leds[] = {3, 5, 7, 9, 11};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 6; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  
  digitalWrite(leds[0], 0);
  digitalWrite(leds[1], 1);
  delay(300);
  digitalWrite(leds[1], 0);
  digitalWrite(leds[2], 1);
  delay(3000);
  digitalWrite(leds[2], 0);
  digitalWrite(leds[3], 1);
  delay(100);
  digitalWrite(leds[3], 0);
  digitalWrite(leds[4], 1);
  delay(800);
  digitalWrite(leds[4], 0);
  digitalWrite(leds[0], 1);
  delay(500);


 }