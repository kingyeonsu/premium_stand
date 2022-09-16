#include "Controller.h"

Controller::Controller(Service *serv, ClockService *clockServ, TempHumidService *tempHumidService,  MotorService *motorService)
{
    this->lightState = LIGHT_OFF;
    this->service = serv;
    this->clockService = clockServ;
    this->tempHumidService = tempHumidService;
    this->motorService = motorService;
}

Controller::~Controller()
{
}

void Controller::updateEvent(std::string strBtn)
{
    if (strBtn == "modeButton")
    {
        service->updateState("modeButton");
    }
    if (strBtn == "powerButton")
    {
        service->updateState("powerButton");
        clockService->stopWatchIint();
    }
    if (strBtn == "motorButton")
    {
        motorService->updateMotorState("motorButton");
    }
    if (strBtn == "clockUpdate")
    {
        clockService->updateEvent();
    }

    if (strBtn == "stopWatchButton")
    {
        clockService->stopWatchEvent();
    }
}

void Controller::updateTempHumid(DHT_Data dhtData)
{
    tempHumidService->updateEvent(dhtData);
}

void Controller::updateDistance(int distance)
{
    service->updateDistance(distance);
}