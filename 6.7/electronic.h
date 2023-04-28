#pragma once

#include <string>

class Electronic {
protected:
    const std::string name_;
    unsigned int price_;

public:
    Electronic(const std::string product_name, unsigned int price)
        : name_(product_name)
        , price_(price) {};
    const std::string getProductName() const;
    virtual void showInfo() const = 0;
    virtual ~Electronic() = default;
};
