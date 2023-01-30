#include <iostream>

#include "phone.h"

void Phone::showInfo() const
{
    std::cout << "Название: " << name_ << std::endl
              << "Тип аккумулятора: " << type_battery_ << std::endl
              << "Время работы аккумулятора?: " << working_hours << std::endl
              << "Потребление: " << consumation_ << std::endl
              << "OS: " << (OS_ == 'I' ? "Iphone" : "Android") << std::endl
              << "Цена: " << price_ << std::endl;

};
