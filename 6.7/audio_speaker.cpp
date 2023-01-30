#include <iostream>

#include "audio_speaker.h"

void AudioSpeaker::showInfo() const
{
    std::cout << "Название: " << name_ << std::endl
              << "Тип аккумулятора: " << type_battery_ << std::endl
              << "Время работы аккумулятора?: " << working_hours << std::endl
              << "Потребление: " << type_battery_ << std::endl
              << "Цена: " << price_ << std::endl;
}
