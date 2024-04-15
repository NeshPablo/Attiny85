const int sensorPin = A0;  // Pin analógico donde está conectado el punto medio del divisor de voltaje
const float resistorValue = 4700.0;  // Valor de la resistencia fija en ohmios (4.7 kohmios)

void setup() {
  Serial.begin(9600);  // Inicializar la comunicación serial a 9600 baudios
}

void loop() {
  float voltage = readVoltage(sensorPin);  // Leer el voltaje en el pin analógico
  float resistance = calculateResistance(voltage);  // Calcular la resistencia variable
  printResistanceAndColorCode(resistance);  // Imprimir el valor de la resistencia y el código de colores
  delay(1000);  // Esperar 1 segundo antes de la próxima lectura
}

float readVoltage(int pin) {
  int sensorValue = analogRead(pin);  // Leer el valor analógico del pin especificado
  float voltage = sensorValue * (5.0 / 1023.0);  // Convertir el valor a voltaje (0-5V)
  return voltage;
}

float calculateResistance(float voltage) {
  // Calcular la resistencia usando la ley de Ohm: R = (V * R1) / (VCC - V)
  float resistance = (voltage * resistorValue) / (5.0 - voltage);
  return resistance;
}

void printResistanceAndColorCode(float resistance) {
  Serial.print("Resistance: ");
  Serial.print(resistance, 2);  // Imprimir el valor de la resistencia con dos decimales
  Serial.println(" ohms");
  printColorCode(resistance);  // Llamar a la función para imprimir el código de colores
}

void printColorCode(float resistance) {
  Serial.print("Color code: ");

  // Definir los valores de las bandas de colores para una resistencia de 4 bandas
  const char* colorBands[] = {"Negro", "Marrón", "Rojo", "Naranja", "Amarillo", "Verde", "Azul", "Violeta", "Gris", "Blanco"};
  
  // Aproximar el valor de la resistencia al valor más cercano
  int roundedResistance = int(resistance + 0.5);  // Redondear al entero más cercano
  
  // Calcular el valor de la primera banda (primer dígito)
  int firstDigit = roundedResistance / 100;
  
  // Calcular el valor de la segunda banda (segundo dígito)
  int secondDigit = (roundedResistance / 10) % 10;
  
  // Calcular el valor del multiplicador (número de ceros)
  int multiplier = 0;
  while (roundedResistance >= 10) {
    roundedResistance /= 10;
    multiplier++;
  }
  
  // Imprimir las bandas de colores correspondientes
  Serial.print(colorBands[firstDigit]);
  Serial.print(" ");
  Serial.print(colorBands[secondDigit]);
  Serial.print(" ");
  Serial.println(colorBands[multiplier]);
}
