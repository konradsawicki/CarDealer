#pragma once
#include "Utils.h"

enum class SERVICE_TYPE
{
    BUY, SELL, EXIT
};

class Customer
{
public:
    SERVICE_TYPE ChooseService() const;
    uint32_t ChooseProduct(uint32_t ProductsNumber) const;

    template<typename T>
    void GiveInfo(T& Info);
};

template<typename T>
inline void Customer::GiveInfo(T& Info)
{
	if (std::cin >> Info)
	{
		CLEAR_BUFFER();
	}
	else
	{
		CLEAR_BUFFER();
		throw("Invalid input type");
	}
}
