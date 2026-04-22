#include <Arduino.h>
#include "motorControl.h"

void initMotorControl() {
  // Set pin sebagai output
  pinMode(LEFT_FORWARD, OUTPUT);
  pinMode(LEFT_BACKWARD, OUTPUT);
  pinMode(RIGHT_FORWARD, OUTPUT);
  pinMode(RIGHT_BACKWARD, OUTPUT);

  // Setup PWM untuk motor left dan right
  ledcSetup(CH_LEFT, PWM_FREQ, PWM_RESOLUTION);
  ledcSetup(CH_RIGHT, PWM_FREQ, PWM_RESOLUTION);

  // Attach PWM ke pin enable
  ledcAttachPin(LEFT_EN, CH_LEFT);
  ledcAttachPin(RIGHT_EN, CH_RIGHT);

  // Stop motor saat inisialisasi
  motorStop();
}

void setMotorSpeed(int leftSpeed, int rightSpeed) {
  // Clamp nilai PWM antara 0-255
  leftSpeed = constrain(leftSpeed, 0, PWM_MAX);
  rightSpeed = constrain(rightSpeed, 0, PWM_MAX);

  ledcWrite(CH_LEFT, leftSpeed);
  ledcWrite(CH_RIGHT, rightSpeed);
}

void motorForward(int speedLeft, int speedRight) {
  digitalWrite(LEFT_FORWARD, HIGH);
  digitalWrite(LEFT_BACKWARD, LOW);

  digitalWrite(RIGHT_FORWARD, HIGH);
  digitalWrite(RIGHT_BACKWARD, LOW);

  setMotorSpeed(speedLeft, speedRight);
}

void motorBackward(int speedLeft, int speedRight) {
  digitalWrite(LEFT_FORWARD, LOW);
  digitalWrite(LEFT_BACKWARD, HIGH);

  digitalWrite(RIGHT_FORWARD, LOW);
  digitalWrite(RIGHT_BACKWARD, HIGH);

  setMotorSpeed(speedLeft, speedRight);
}

void motorTurnLeft(int speedLeft, int speedRight) {
  // Motor kiri mundur, motor kanan maju
  digitalWrite(LEFT_FORWARD, LOW);
  digitalWrite(LEFT_BACKWARD, HIGH);

  digitalWrite(RIGHT_FORWARD, HIGH);
  digitalWrite(RIGHT_BACKWARD, LOW);

  setMotorSpeed(speedLeft, speedRight);
}

void motorTurnRight(int speedLeft, int speedRight) {
  // Motor kiri maju, motor kanan mundur
  digitalWrite(LEFT_FORWARD, HIGH);
  digitalWrite(LEFT_BACKWARD, LOW);

  digitalWrite(RIGHT_FORWARD, LOW);
  digitalWrite(RIGHT_BACKWARD, HIGH);

  setMotorSpeed(speedLeft, speedRight);
}

void motorStop() {
  ledcWrite(CH_LEFT, 0);
  ledcWrite(CH_RIGHT, 0);
}
