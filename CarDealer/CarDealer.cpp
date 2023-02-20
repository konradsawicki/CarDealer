#include "CarDealer.h"
#include "Car.h"

CarDealer::CarDealer()
{
	InitProducts();
}

void CarDealer::InitProducts()
{
	using namespace std::chrono;
	m_AvailableProducts.push_back({ std::make_unique<Car>("Honda Civic", 2010, 5000), high_resolution_clock::now() });
	m_AvailableProducts.push_back({ std::make_unique<Car>("Audi A6", 2005, 7000), high_resolution_clock::now() });
	m_AvailableProducts.push_back({ std::make_unique<Car>("BMW 3", 2008, 6500), high_resolution_clock::now() });
}

void CarDealer::ShowProducts(const std::vector<ProductInfo>& ProductsInfoToShow)
{
	uint32_t Index = 1;
	for (const auto& ProdInfo : ProductsInfoToShow)
	{
		if (Car* car = dynamic_cast<Car*>(ProdInfo.first.get()))
		{
			PRINT(Index, ". car");
			PRINT("Model: ", car->GetModelName());
			PRINT("Year of first registration: ", car->GetYearOfFirstRegistration());
			PRINT("Price: ", car->GetPrice(), "$") << std::endl;
			Index++;
		}
	}
}

void CarDealer::BuyFromCustomer()
{
	PRINT("Please give info about product that you want to sell: ");

	std::string ModelName;
	uint32_t YearOfFirstRegistration;
	float Price;

	PRINT("Model: "); m_Customer.GiveInfo(ModelName);
	PRINT("Year of first registration: "); m_Customer.GiveInfo(YearOfFirstRegistration);
	PRINT("Price: "); m_Customer.GiveInfo(Price);

	m_AvailableProducts.push_back({ std::make_unique<Car>(ModelName, YearOfFirstRegistration, Price),
									std::chrono::high_resolution_clock::now() });
}
