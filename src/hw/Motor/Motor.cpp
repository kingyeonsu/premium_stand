#include "Motor.h"

Motor::Motor(int pwmPin)
{
    this->pwmPin = pwmPin;
}

Motor::~Motor()
{
}

void Motor::warningPwmMotor()
{
    softPwmCreate(pwmPin, 0, 100);
    softPwmWrite(pwmPin, 20);
    delay(1000);
    softPwmWrite(pwmPin, 40);
    delay(1000);
    softPwmWrite(pwmPin, 60);
    delay(1000);
    softPwmWrite(pwmPin, 80);
    delay(1000);
    softPwmWrite(pwmPin, 99);
    delay(1000);
    softPwmStop(pwmPin);
}

void Motor::motorOn()
{
    softPwmCreate(pwmPin, 0, 100);
    softPwmWrite(pwmPin, 70);
}

void Motor::motorOff()
{
    softPwmStop(pwmPin);
}