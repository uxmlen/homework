#pragma once

#include <string>

class Snack
{
    std::string name;
public:
    Snack(const std::string& product_name)
        : name(product_name) {}
    std::string getNameProduct() const;
};
