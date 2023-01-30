#pragma once

#include "electronic.h"

class Appliance : virtual public Electronic
{
protected:
    unsigned int height_;
    unsigned int width_;
public:
    Appliance(unsigned int height, unsigned int width)
        : height_(height), width_(width) {};
};
