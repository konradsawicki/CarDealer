#include "Customer.h"


SERVICE_TYPE Customer::ChooseService() const
{
	PRINT("Type 1 to buy a product, 2 to sell a product or 3 to exit shop and accept with ENTER");

	uint32_t Choice;
	if (std::cin >> Choice)
	{
		CLEAR_BUFFER();
		switch (Choice)
		{
			case 1: return SERVICE_TYPE::BUY;
			case 2: return SERVICE_TYPE::SELL;
			case 3: return SERVICE_TYPE::EXIT;
			default: throw("Invalid service type");
		}
	}
	else
	{
		CLEAR_BUFFER();
		throw("Invalid input type");
	}
}

uint32_t Customer::ChooseProduct(uint32_t ProductsNumber) const
{
	PRINT("Type number between 1 and ", ProductsNumber, " to choose wanted product and accept with ENTER");
	uint32_t Choice;
	if (std::cin >> Choice)
	{
		CLEAR_BUFFER();
		if (Choice >= 1 && Choice <= ProductsNumber)
		{
			return Choice;
		}
		else
		{
			throw("Invalid index");
		}
	}
	else
	{
		CLEAR_BUFFER();
		throw("Invalid input type");
	}
}
