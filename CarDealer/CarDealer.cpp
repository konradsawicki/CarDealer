#include "CarDealer.h"
#include "Car.h"

void CarDealer::InitProducts()
{
	m_AvailableProducts.push_back({ std::make_unique<Car>("Honda Civic", 2010, 5000), m_TimeMenager.Now() });
	m_AvailableProducts.push_back({ std::make_unique<Car>("Audi A6", 2005, 7000), m_TimeMenager.Now() });
	m_AvailableProducts.push_back({ std::make_unique<Car>("BMW 3", 2008, 6500), m_TimeMenager.Now() });
}

void CarDealer::ShowProduct(const ProductInfo& Product) const
{
	Car* car = dynamic_cast<Car*>(Product.first.get());
	if (car)
	{
		m_ConsoleMenager.Print("Model: ", car->GetModelName());
		m_ConsoleMenager.Print("Year of first registration: ", car->GetYearOfFirstRegistration());
		m_ConsoleMenager.Print("Price: ", car->GetCurrentPrice(), "$");
	}
	else
	{
		throw("Invalid product type");
	}
}

void CarDealer::BuyFromCustomer()
{
	m_ConsoleMenager.ClearConsole();
	m_ConsoleMenager.Print("Please give info about the product that you want to sell: ", '\n');

	m_ConsoleMenager.Print("Model: "); 
	std::string ModelName = m_Customer.GetAnswer<std::string>();

	m_ConsoleMenager.Print('\n', "Year of first registration: ");
	uint32_t YearOfFirstRegistration = m_Customer.GetAnswer<uint32_t>();

	m_ConsoleMenager.Print('\n', "Price ($): ");
	uint32_t Price = m_Customer.GetAnswer<uint32_t>();

	m_AvailableProducts.push_back({std::make_unique<Car>(ModelName, YearOfFirstRegistration, Price), m_TimeMenager.Now()});
	ThankForTransaction();
}

