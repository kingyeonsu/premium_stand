#include "MotorService.h"

MotorService::MotorService(MotorView *motorView)
{
    this->motorView = motorView;
    motorState = MOTOR_OFF;
}

MotorService::~MotorService()
{

}

void MotorService::updateMotorState(std::string strState)
{
    switch (motorState)
    {
        case MOTOR_OFF:
            if (strState == "motorButton")
            {
                motorState = MOTOR_ON;               
            }
            break;
        case MOTOR_ON:
            if (strState == "motorButton")
            {
                motorState = MOTOR_OFF;               
            }
            break;   
    }
    printf("motorstate: %d\n", motorState);
    motorView->motorControl(motorState);
    
}