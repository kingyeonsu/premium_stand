#include <iostream>
#include <wiringPi.h>
#include "Button.h"
#include "Led.h"
#include "Listener.h"
#include "Controller.h"
#include "View.h"
#include "Service.h"
#include "LCD.h"
#include "ClockView.h"
#include "ClockService.h"
#include "ClockCheck.h"
#include "I2C.h"
#include "DHT11.h"
#include "DHT_Data.h"
#include "UltraSonic.h"
#include "Motor.h"
#include "MotorService.h"
#include "MotorView.h"

int main()
{
    std::cout << "Stand LIght with Clock_temp_humid_distance_pwmMotor" << std::endl;

    Button powerButton(27);
    Button modeButton(28);
    Button motorButton(29);
    Button stopWatchButton(1);
    ClockCheck clockCheck;
    UltraSonic ultraSonic(5, 4);
    Motor motor(26);
    Led led1(21);
    Led led2(22);
    Led led3(23);
    Led led4(24);
    Led led5(25);
    DHT11 dht(7);
    LCD lcd(new I2C("/dev/i2c-1", 0x27));
    View view(&led1, &led2, &led3, &led4, &led5, &lcd);
    TempHumidView temphumidview(&lcd, &view, &motor);
    ClockView clockView(&lcd);
    MotorView motorview(&motor);
    Service service(&view);
    TempHumidService temphumidservice(&temphumidview);
    ClockService clockService(&clockView);
    MotorService motorservice(&motorview);
    Controller control(&service, &clockService, &temphumidservice, &motorservice);
    Listener listener(&modeButton, &powerButton, &motorButton, &stopWatchButton, &control, &clockCheck, &dht, &ultraSonic);
    
    while (1)
    {
        listener.checkEvent();
        view.lightView();
        delay(50);
    }

    return 0;
}