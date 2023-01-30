#pragma once

#include "portable.h"

class Phone final : public Portable
{
    char OS_; // android (A) vs iphone (I)
public:
    Phone(const std::string product_name, unsigned int price,
          unsigned int type_battery, unsigned short consumation, char OS)
        : Electronic(product_name, price), Portable(type_battery, consumation), OS_(OS) {}
    void showInfo() const;
};
