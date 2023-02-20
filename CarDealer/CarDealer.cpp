#include "CarDealer.h"
#include "Car.h"

void CarDealer::InitProducts()
{
	using namespace std::chrono;
	m_AvailableProducts.push_back({ std::make_unique<Car>("Honda Civic", 2010, 5000), high_resolution_clock::now() });
	m_AvailableProducts.push_back({ std::make_unique<Car>("Audi A6", 2005, 7000), high_resolution_clock::now() });
	m_AvailableProducts.push_back({ std::make_unique<Car>("BMW 3", 2008, 6500), high_resolution_clock::now() });
}

void CarDealer::ShowProduct(const ProductInfo& ProductInfoToShow) const
{
	if (Car* car = dynamic_cast<Car*>(ProductInfoToShow.first.get()))
	{
		m_ConsoleMenager.Print("Model: ", car->GetModelName());
		m_ConsoleMenager.Print("Year of first registration: ", car->GetYearOfFirstRegistration());
		m_ConsoleMenager.Print("Price: ", car->GetCurrentPrice(), "$");
	}
}

void CarDealer::BuyFromCustomer()
{
	m_ConsoleMenager.ClearConsole();
	m_ConsoleMenager.Print("Please give info about product that you want to sell: "); m_ConsoleMenager.EndLine();

	std::string ModelName;
	uint32_t YearOfFirstRegistration;
	float Price;

	m_ConsoleMenager.Print("Model: "); m_Customer.Answer(ModelName);
	m_ConsoleMenager.Print("Year of first registration: "); m_Customer.Answer(YearOfFirstRegistration);
	m_ConsoleMenager.Print("Price ($): "); m_Customer.Answer(Price);

	m_AvailableProducts.push_back({ std::make_unique<Car>(ModelName, YearOfFirstRegistration, Price),
									std::chrono::high_resolution_clock::now() });

	ThankForTransaction();
}

