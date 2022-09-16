#include "MotorView.h"

MotorView::MotorView(Motor *motor)
{
    this->motor = motor;
    motorState = MOTOR_OFF;
}

MotorView::~MotorView()
{

}

void MotorView::motorControl(int motorState)
{
    switch (motorState)
    {
    case MOTOR_OFF:
        motor->motorOn();
        break;
    
    case MOTOR_ON:
        motor->motorOff();
        break;
    }
}