#include <Arduino.h>
#include "bacaSensor.h"


void setup() {
  Serial.begin(115200);
  initBacaSensor();
}

void loop() {
  bacaSensor();
  delay(100);
}