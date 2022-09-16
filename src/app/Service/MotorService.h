#ifndef MOTORSERVICE_H
#define MOTORSERVICE_H

#pragma once
#include <string>
#include "MotorView.h"
#include "MotorState.h"

class MotorService
{
private:
    int motorState = MOTOR_OFF;
    MotorView *motorView;
public:
    MotorService(MotorView *motorView);
    ~MotorService();
    void updateMotorState(std::string strState);
};

#endif