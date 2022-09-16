#include "TempHumidView.h"

TempHumidView::TempHumidView(LCD *Lcd, View *view, Motor *motor)
{
    this->lcd = Lcd;
    this->view = view;
    this->motor = motor;
}

TempHumidView::~TempHumidView()
{

}

void TempHumidView::setTempHumidData(float temp, float humid)
{
    char tempBuff[20];
    char humidBuff[20];
    sprintf(tempBuff, "%.1f'C", temp);
    sprintf(humidBuff, "%.1f%c", humid, '%');
    lcd->WriteStringXY(0, 10, tempBuff);
    //lcd->WriteStringXY(1, 10, humidBuff);
    printf("%s %s\n", tempBuff, humidBuff);

}

void TempHumidView::tempWarning(float temp)
{
     if (temp > warningTemp)
    {
        view->warningLightOff();
        printf("WARNING!!\n");
        motor->warningPwmMotor();
    }
}