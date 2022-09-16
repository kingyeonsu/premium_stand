#ifndef SERVICE_H
#define SERVICE_H

#pragma once

#include <string>
#include "View.h"
#include "LightState.h"

class Service
{
private:
    int lightState;
    int falseCount = 0;
    int farCount = 0;
    View *view;
    bool bDistanceLight;

public:
    Service(View *viewer);
    ~Service();
    void updateState(std::string strState);
    void updateDistance(int distance);

};

#endif