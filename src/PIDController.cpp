#include <Arduino.h>
#include "bacaSensor.h"
#include "PIDController.h"

float line_position = 0;
float error = 0;
float center_position = 45;

void PID(){
    bacaMid();

    if (sumOnSensor > 0) {
        line_position = sensorWight / sumOnSensor;
        error = center_position - line_position;
    }
    
    // display sensor data
    for (int i = 7; i >= 0; i--) {
        Serial.print(String(bitRead(bitsensor, i)));
    }

    Serial.print(String(" Weight :" + String(sensorWight)));
    Serial.print(" Error :" + String(error));
    Serial.println();

}