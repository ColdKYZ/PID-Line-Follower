#include <Arduino.h>

#define JUMLAH_SENSOR 16

#define SEL_A 25
#define SEL_B 26

int sensorADC[JUMLAH_SENSOR];
int sensorDigital[JUMLAH_SENSOR];
int treshold = 500;


int P, I, D, prevError, error;

void bacaSensor() {
  digitalWrite(SEL_A, 0); digitalWrite(SEL_B, 0);
  delayMicroseconds(10);
  sensorADC[14] = analogRead(32);
  sensorADC[3]  = analogRead(33);
  sensorADC[6]  = analogRead(34);
  sensorADC[8]  = analogRead(35);

  digitalWrite(SEL_A, 1); digitalWrite(SEL_B, 0);
  delayMicroseconds(10);
  sensorADC[12] = analogRead(32);
  sensorADC[2]  = analogRead(33);
  sensorADC[4]  = analogRead(34);
  sensorADC[9]  = analogRead(35);

  digitalWrite(SEL_A, 0); digitalWrite(SEL_B, 1);
  delayMicroseconds(10);
  sensorADC[13] = analogRead(32);
  sensorADC[0]  = analogRead(33);
  sensorADC[5]  = analogRead(34);
  sensorADC[11] = analogRead(35);

  digitalWrite(SEL_A, 1); digitalWrite(SEL_B, 1);
  delayMicroseconds(10);
  sensorADC[15] = analogRead(32);
  sensorADC[1]  = analogRead(33);
  sensorADC[7]  = analogRead(34);
  sensorADC[10] = analogRead(35);

  for(int i = 0; i < JUMLAH_SENSOR; i++) {
    if (sensorADC[i] < treshold) {
      sensorDigital[i] = 0;
    } else {
      sensorDigital[i] = 1;
    }
    Serial.print(sensorDigital[i]);
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(SEL_A, OUTPUT);
  pinMode(SEL_B, OUTPUT);

  analogReadResolution(12);       // 0–4095
  analogSetAttenuation(ADC_11db); // range ~0–3.3V
}

void loop() {
  bacaSensor();
  delay(100);
}