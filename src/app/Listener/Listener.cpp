#include "Listener.h"

Listener::Listener(Button *modeButton, Button *powerButton, Button *motorButton, Button *stopWatchButton,
 Controller *control, ClockCheck *clock,
 DHT11 *dht11, UltraSonic *ultraSonic)
{
    this->modeButton = modeButton;
    this->powerButton = powerButton;
    this->motorButton = motorButton;
    this->stopWatchButton = stopWatchButton;
    this->controller = control;
    this->clockCheck = clock;
    this->dht11 = dht11;
    this->ultraSonic = ultraSonic;
    stopWatchState = 0;
}

Listener::~Listener()
{
}

void Listener::checkEvent()
{
    if (modeButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("modeButton");
    }

    if (powerButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("powerButton");
    }

    if (motorButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("motorButton");
    }

    if (stopWatchButton->getState() == RELEASE_ACTIVE)
    {
        stopWatchState = !stopWatchState;
    }

    if (stopWatchState)
    {
        controller->updateEvent("stopWatchButton");
    }

    if (clockCheck->isUpdate())
    {
        controller->updateEvent("clockUpdate");
    }
    
    static unsigned int prevTempHumidTime = 0;
    if (millis() - prevTempHumidTime > 1000)
    {
        prevTempHumidTime = millis();
        DHT_Data dhtData = dht11->readData();
        if (!dhtData.error)
        {
            controller->updateTempHumid(dhtData);
        }
    }

    static unsigned int prevUltraSonicTime = 0;
    if (millis() - prevUltraSonicTime > 1000)
    {
        prevUltraSonicTime = millis();
        int distance = ultraSonic->readDistance();
        controller->updateDistance(distance);
    }
    
}