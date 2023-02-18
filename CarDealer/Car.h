#pragma once
#include "Product.h"
#include <string>

class Car :
    public Product
{
public:
    Car(const std::string& Model, uint32_t YearOfFirstRegistration, float Price);

    const std::string& GetModelName() const;
    uint32_t GetYearOfFirstRegistration() const;

protected:
    std::string m_ModelName;
    uint32_t m_YearOfFirstRegistration;
};

