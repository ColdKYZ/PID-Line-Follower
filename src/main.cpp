#include <Arduino.h>
#include "bacaSensor.h"
#include "PIDController.h"
#include "motorControl.h"



void setup() {
  Serial.begin(115200);
  initBacaSensor();
  initMotorControl();
}

void loop() {
  // bacaSensor(); 
  // bacaMid();
  // side_callibrate();
  // motorForward(150, 150);
  PID();
  delay(100);
}