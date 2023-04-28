#pragma once

#include "appliance.h"

class Fridge final : public Appliance {
    // число камер (в холодильники)
    unsigned short number_chambers_;

public:
    Fridge(const std::string product_name, unsigned int price,
        unsigned int height, unsigned int width, unsigned short number_chambers)
        : Electronic(product_name, price)
        , Appliance(height, width)
        , number_chambers_(number_chambers)
    {
    }
    void showInfo() const override;
};
