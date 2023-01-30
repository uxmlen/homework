#pragma once

#include "electronic.h"

class Portable : virtual public Electronic
{
protected:
    // тип аккумулятора
    unsigned short type_battery_; // номер типа
    // потребление
    unsigned short consumation_; 
    // сколько часов работает? (расчёт по выдуманной формуле)
    unsigned short working_hours = (type_battery_ + consumation_) * 2;
public:
    Portable(unsigned short type_battery, unsigned short consumation)
        : type_battery_(type_battery), consumation_(consumation) {};
};
