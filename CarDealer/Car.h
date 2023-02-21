#pragma once
#include "Product.h"
#include <string>

class Car :
    public Product
{
public:
    Car(const std::string& ModelName, uint32_t YearOfFirstRegistration, float Price)
        : Product(Price), m_ModelName(ModelName), m_YearOfFirstRegistration(YearOfFirstRegistration) {}

    const std::string& GetModelName() const { return m_ModelName; }
    uint32_t GetYearOfFirstRegistration() const { return m_YearOfFirstRegistration; }

protected:
    std::string m_ModelName;
    uint32_t m_YearOfFirstRegistration;
};

