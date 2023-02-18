#include "Customer.h"

SERVICE_TYPE Customer::ChooseService() const
{
	PRINT("Press 1 to buy a car or 2 to sell a car.", "");

	uint32_t Choice;
	std::cin >> Choice;
	switch (Choice)
	{
		case 1: return SERVICE_TYPE::BUY;
		case 2: return SERVICE_TYPE::SELL;
		default: throw("Invalid service type");
	}
}

uint32_t Customer::ChooseProduct(uint32_t ProductsNumber) const
{
	PRINT("Type number between 1 and ", ProductsNumber);
	uint32_t Choice;
	std::cin >> Choice;
	return Choice;
}
