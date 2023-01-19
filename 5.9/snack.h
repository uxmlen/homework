#pragma once

#include <string>

class Snack
{
    std::string product_name;
public:
    Snack(std::string product_name);
    std::string getNameProduct() const;
};
