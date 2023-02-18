#pragma once
#include "Utils.h"

enum class SERVICE_TYPE
{
    BUY, SELL
};

class Customer
{
public:
    SERVICE_TYPE ChooseService() const;
    uint32_t ChooseProduct(uint32_t ProductsNumber) const;
};


