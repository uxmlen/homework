#include "snack.h"

Snack::Snack(std::string product_name) 
{
    this->product_name = product_name;
}

std::string Snack::getNameProduct() const
{
    return product_name;
}
