#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
#define OLED_RESET    -1 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
const int sensorPin = A0;          
const float resistorValue = 5100.0;

void setup() {
  Serial.begin(9600);  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Error: No se pudo inicializar la pantalla OLED"));
    while (true);
  }
  display.display();
  delay(2000);  
  display.clearDisplay(); 
}

void loop() {
  float voltage = readVoltage(sensorPin); 
  float Resistencia = calculateResistance(voltage);  
  printResistanceAndColorCode(Resistencia);  
  delay(1000); 
}

float readVoltage(int pin) {
  int sensorValue = analogRead(pin);  // Leer el valor analógico del pin especificado
  float voltage = sensorValue * (5.0 / 1023.0);  // Convertir el valor a voltaje (0-5V)
  return voltage;
}

float calculateResistance(float voltage) {
  // Calcular la resistencia usando la ley de Ohm: R = (V * R1) / (VCC - V)
  float Resistencia = (voltage * resistorValue) / (5.0 - voltage);
  return Resistencia;
}
void printResistanceAndColorCode(float Resistencia) {
  Serial.print("Resistance: ");
  Serial.print(Resistencia, 2); 
  Serial.println(" ohms");
  char CodigoColor[50];  
  printColorCode(Resistencia, CodigoColor);  
  Serial.println(CodigoColor);  
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(2, 0);
  display.println("  -----------------"); 
  display.println(""); 
  display.print("RES: ");
  display.print(Resistencia, 2);
  display.println(" ohms");
  display.println(""); 
  display.println("  -----------------"); 
  display.println(""); 
  display.setTextSize(1.8);
  display.println("COLOR: ");
  display.println(CodigoColor);
  display.display();
}

void printColorCode(float Resistencia, char* CodigoColor) {
  const char* colorBands[] = {"Neg", "Mar", "Ro", "Nar", "Am", "Ver", "Az", "Vio", "Gris", "Blan"};
  int redondeoRes = int(Resistencia + 0.5);
  int Banda_1 = redondeoRes / 1000;  
  int Banda_2 = (redondeoRes / 100) % 10;
  int multiplier = numDigits(redondeoRes) - 2; 
  const char* tolerance = "Dor";
  sprintf(CodigoColor, "%s %s %s %s", colorBands[Banda_1], colorBands[Banda_2], colorBands[multiplier], tolerance);
}
int numDigits(int number) {
  int digits = 1;
  while (number /= 10) {
    digits++;
  }
  return digits;
}

