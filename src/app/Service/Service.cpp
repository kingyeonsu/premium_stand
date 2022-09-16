#include "Service.h"

Service::Service(View *viewer)
{
    view = viewer;
    lightState = LIGHT_OFF;
    bDistanceLight = false;
}

Service::~Service()
{

}

void Service::updateState(std::string strState)
{
    switch (lightState)
    {
        case LIGHT_OFF:
            if (strState == "modeButton") {
                lightState = LIGHT_1;
            }
            view->setState(lightState);
        break;

        case LIGHT_1:
            if (strState == "modeButton") {
                lightState = LIGHT_2;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            if (bDistanceLight) {
                view->setState(lightState);
            }
            else {
                view->setState(LIGHT_OFF);
            }  
        break;

        case LIGHT_2:
            if (strState == "modeButton") {
                lightState = LIGHT_3;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            if (bDistanceLight) {
                view->setState(lightState);
            }
            else {
                view->setState(LIGHT_OFF);
            }  
        break;

        case LIGHT_3:
            if (strState == "modeButton") {
                lightState = LIGHT_4;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            if (bDistanceLight) {
                view->setState(lightState);
            }
            else {
                view->setState(LIGHT_OFF);
            }           
        break;

        case LIGHT_4:
            if (strState == "modeButton") {
                lightState = LIGHT_5;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            if (bDistanceLight) {
                view->setState(lightState);
            }
            else {
                view->setState(LIGHT_OFF);
            }  
        break;

        case LIGHT_5:
            if (strState == "modeButton") {
                lightState = LIGHT_OFF;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            if (bDistanceLight) {
                view->setState(lightState);
            }
            else {
                view->setState(LIGHT_OFF);
            }
        break;
    }
}

void Service::updateDistance(int distance)
{
    if (distance < 0)
    {
        bDistanceLight = false;
        falseCount++;
        if (falseCount >= 10)
        {
            view->setState(LIGHT_OFF);
        }
        
    }
    else
    {
        if (distance > 30)
        {
            farCount++;
            if (farCount > 10)
            {
                view->setState(LIGHT_OFF);
            }
        }
        else
        {
            farCount = 0;
            falseCount = 0;
            bDistanceLight = true;
            view->setState(lightState);
        }
    }
    printf("distance: %d, ON/OFF: %d, T/F %d, far: %d\n", distance, bDistanceLight, falseCount, farCount);
}