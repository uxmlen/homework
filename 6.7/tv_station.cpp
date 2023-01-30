#include <iostream>

#include "tv_station.h" 

void TVStation::showInfo() const
{
    std::cout << "Название: " << name_ << std::endl
              << "Диаметр экрана: " << size_of_screen_ << std::endl
              << "DPI: " << dpi_ << std::endl
              << "Длина: " << dpi_ << std::endl
              << "Ширина: " << dpi_ << std::endl
              << "Цена: " << price_ << std::endl;
}
