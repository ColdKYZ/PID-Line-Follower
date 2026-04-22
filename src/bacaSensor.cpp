#include <Arduino.h>
#include "bacaSensor.h"

#define JUMLAH_SENSOR 16

#define SEL_A 25
#define SEL_B 26

int sensorADC[JUMLAH_SENSOR];
int sensorDigital[JUMLAH_SENSOR];
int treshold = 500;
int sumOnSensor;
int sensorWight;
int bitsensor;
int WeightValue[JUMLAH_SENSOR] = { 0, 0, 0, 0, 10, 20, 30, 40, 50, 60, 70, 80, 0, 0, 0, 0 };
int bitWeight[JUMLAH_SENSOR] = { 0, 0, 0, 0, 1, 2, 4, 8, 16, 32, 64, 128, 0, 0, 0, 0 };

void initBacaSensor() {
  pinMode(SEL_A, OUTPUT);
  pinMode(SEL_B, OUTPUT);

  analogReadResolution(12);       // 0-4095
  analogSetAttenuation(ADC_11db); // range ~0-3.3V
}

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

  sumOnSensor = 0;
  sensorWight = 0;
  bitsensor = 0;
  for(int i = 0; i < 8; i++) {
    int sensorIndex = i + 4;  // Membaca sensor 4-11
    if (sensorADC[sensorIndex] < treshold) {
      sensorDigital[i] = 0;
    } else {
      sensorDigital[i] = 1;
    }
    sumOnSensor += sensorDigital[i];
    sensorWight += sensorDigital[i] * WeightValue[sensorIndex];
    bitsensor += sensorDigital[i] * bitWeight[sensorIndex];

    Serial.print(String(bitRead(bitsensor, i)));
  }
  Serial.print(String(" " + String(bitsensor)));
  Serial.println();
}
