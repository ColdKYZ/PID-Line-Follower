#pragma once

// Motor A (Left)
#define LEFT_EN 13
#define LEFT_FORWARD 4
#define LEFT_BACKWARD 2

// Motor B (Right)
#define RIGHT_EN 5
#define RIGHT_FORWARD 16
#define RIGHT_BACKWARD 17

// PWM Configuration
#define PWM_FREQ 20000
#define PWM_RESOLUTION 8
#define PWM_MAX 255

// PWM Channels
#define CH_LEFT 0
#define CH_RIGHT 1

void initMotorControl();
void motorForward(int speedLeft, int speedRight);
void motorBackward(int speedLeft, int speedRight);
void motorTurnLeft(int speedLeft, int speedRight);
void motorTurnRight(int speedLeft, int speedRight);
void motorStop();
void setMotorSpeed(int leftSpeed, int rightSpeed);
