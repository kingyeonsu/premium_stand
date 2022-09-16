#ifndef TEMPHUMIDVIEW_H
#define TEMPHUMIDVIEW_H

#pragma once

#include <LCD.h>
#include <View.h>
#include <wiringPi.h>
#include <Motor.h>

class TempHumidView
{
private:
    LCD *lcd;
    View *view;
    Motor *motor;
    int warningTemp = 28;

public:
    TempHumidView(LCD *Lcd, View *view, Motor *motor);
    ~TempHumidView();
    void setTempHumidData(float temp, float humid);
    void tempWarning(float temp);

};

#endif