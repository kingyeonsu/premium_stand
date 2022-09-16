#ifndef MOTORVIEW_H
#define MOTORVIEW_H

#pragma once

#include "Motor.h"
#include "MotorState.h"

class MotorView
{
private:
    int motorState = MOTOR_OFF;
    Motor *motor;
public:
    MotorView(Motor *motor);
    ~MotorView();
    void motorControl(int motorState);


};

#endif