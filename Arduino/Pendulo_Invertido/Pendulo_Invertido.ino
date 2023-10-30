#include <PID_v1.h>
double sp, setpoint, input, in, out, output;
int sal, val, sal1;
PID pendulo(&in, &out, &sp, 10.57, 8192, 0.01, DIRECT);

void setup() {
  delay(4000);
  setpoint = analogRead(0);
  sp = 0;
  Serial.begin(9600);
  Serial.println(sp);
  pendulo.SetSampleTime(20);
  pendulo.SetMode(AUTOMATIC);
  pendulo.SetOutputLimits(-255, 255);
}
void loop() {
  input = analogRead(0);
  val = setpoint-input;
  in  = val;
  pendulo.Compute();
  if (abs(val) > 0){
    if (val > 0){
      sal = 12;
      sal1 = 10;
      digitalWrite(13, LOW);
      digitalWrite(11, LOW);
    }else{
      sal = 13;
      sal1 = 11;
      digitalWrite(12, LOW);
      digitalWrite(10, LOW);
    }
    output = abs(out);
    analogWrite(sal, output);
    analogWrite(sal1, output);
  }else{
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
  }
  Serial.print(setpoint);
  Serial.print(" ");
  Serial.print(in);
  Serial.print(" ");
  Serial.print(output);
}
