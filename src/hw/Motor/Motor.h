#ifndef MOTOR_H
#define MOTOR_H

#pragma once

#include <wiringPi.h>
#include <softPwm.h>

class Motor
{
private:
    int pwmPin;

public:
    Motor(int pwmPin);
    virtual ~Motor();
    void warningPwmMotor();
    void motorOn();
    void motorOff();

};

#endif