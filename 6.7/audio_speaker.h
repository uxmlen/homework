#pragma once

#include <string>

#include "portable.h"
#include "appliance.h"

class AudioSpeaker final : public Portable,  public Appliance
{
    // мощность звука
    int power_;
public:
    AudioSpeaker(const std::string product_name, unsigned int price,
                 unsigned short type_battery, unsigned short consumation,
                 int height, int width, int power)
        : Electronic(product_name, price), Portable(type_battery, consumation),
          Appliance(height, width), power_(power) {};
    void showInfo() const;
};
