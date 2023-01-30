#pragma once

#include "appliance.h"

// тв станция
class TVStation : public Appliance
{
    unsigned short dpi_;
    unsigned short size_of_screen_ = 2 * (height_ + width_);
public:
    TVStation(const std::string product_name, unsigned int price, unsigned int height, 
              unsigned int width, unsigned short dpi)
        : Electronic(product_name, price), Appliance(height, width), 
          dpi_(dpi) {}
    void showInfo() const;
};
