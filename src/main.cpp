#include <Arduino.h>
#include "bacaSensor.h"
#include "PIDController.h"
#include "motorControl.h"

int base_speed = 170;
float Kp = 1.7;
float Kd = 2.3;


void setup() {
  Serial.begin(115200);
  initBacaSensor();
  initMotorControl();
}

void loop() {
  // bacaSensor(); 
  // bacaMid();
  // side_callibrate();
  PID(base_speed, Kp, Kd);
}