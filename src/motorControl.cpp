#include <Arduino.h>
#include "motorControl.h"

void initMotorControl() {
  // Set pin sebagai output
  pinMode(LEFT_FORWARD, OUTPUT);
  pinMode(LEFT_BACKWARD, OUTPUT);
  pinMode(RIGHT_FORWARD, OUTPUT);
  pinMode(RIGHT_BACKWARD, OUTPUT);

  // Setup PWM untuk motor left dan right
  ledcSetup(CH_LEFT, PWM_FREQ_LEFT, PWM_RESOLUTION);
  ledcSetup(CH_RIGHT, PWM_FREQ_RIGHT, PWM_RESOLUTION);

  // Attach PWM ke pin enable
  ledcAttachPin(LEFT_EN, CH_LEFT);
  ledcAttachPin(RIGHT_EN, CH_RIGHT);

  // Stop motor saat inisialisasi
  motorStop();
}


void setMotorSpeed(float leftSpeed, float rightSpeed) {

  // ===== MOTOR KIRI =====
  if (leftSpeed >= 0) {
    digitalWrite(LEFT_FORWARD, HIGH);
    digitalWrite(LEFT_BACKWARD, LOW);
  } else {
    digitalWrite(LEFT_FORWARD, LOW);
    digitalWrite(LEFT_BACKWARD, HIGH);
    leftSpeed = -leftSpeed;
  }

  // ===== MOTOR KANAN =====
  if (rightSpeed >= 0) {
    digitalWrite(RIGHT_FORWARD, HIGH);
    digitalWrite(RIGHT_BACKWARD, LOW);
  } else {
    digitalWrite(RIGHT_FORWARD, LOW);
    digitalWrite(RIGHT_BACKWARD, HIGH);
    rightSpeed = -rightSpeed;
  }

  // Clamp setelah jadi positif
  leftSpeed = constrain(leftSpeed, 0, PWM_MAX);
  rightSpeed = constrain(rightSpeed, 0, PWM_MAX);

  ledcWrite(CH_LEFT, leftSpeed);
  ledcWrite(CH_RIGHT, rightSpeed);
}

void motorForward(float speedLeft, float speedRight) {
  digitalWrite(LEFT_FORWARD, HIGH);
  digitalWrite(LEFT_BACKWARD, LOW);

  digitalWrite(RIGHT_FORWARD, HIGH);
  digitalWrite(RIGHT_BACKWARD, LOW);

  setMotorSpeed(speedLeft, speedRight);
}

void motorBackward(float speedLeft, float speedRight) {
  digitalWrite(LEFT_FORWARD, LOW);
  digitalWrite(LEFT_BACKWARD, HIGH);

  digitalWrite(RIGHT_FORWARD, LOW);
  digitalWrite(RIGHT_BACKWARD, HIGH);

  setMotorSpeed(speedLeft, speedRight);
}

void motorTurnLeft(float speedLeft, float speedRight) {
  // Motor kiri mundur, motor kanan maju
  digitalWrite(LEFT_FORWARD, LOW);
  digitalWrite(LEFT_BACKWARD, HIGH);

  digitalWrite(RIGHT_FORWARD, HIGH);
  digitalWrite(RIGHT_BACKWARD, LOW);

  setMotorSpeed(speedLeft, speedRight);
}

void motorTurnRight(float speedLeft, float speedRight) {
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
