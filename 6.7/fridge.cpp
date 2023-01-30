#include <iostream>

#include "fridge.h"

void Fridge::showInfo() const
{
    std::cout << "Название: " << name_ << std::endl
              << "Высота: " << height_ << std::endl
              << "Ширина: " << width_ << std::endl
              << "Число камер : " << number_chambers_ << std::endl
              << "Цена: " << price_ << std::endl;
};
