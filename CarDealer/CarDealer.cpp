#include "CarDealer.h"
#include "CarShop.h"
#include "Car.h"


void CarDealer::InitShop()
{

	if (m_Shop = std::make_unique<CarShop>())
	{
		m_Shop->Run();
	}
	else
	{
		exit(1);
	}
}

void CarDealer::ShowProduct(const Product& Product) const
{
	Car* car = dynamic_cast<Car*>(Product.Item.get());
	if (car)
	{
		m_ConsoleManager.Print("Model: ", car->GetModelName());
		m_ConsoleManager.Print("Year of first registration: ", car->GetYearOfFirstRegistration());
		m_ConsoleManager.Print("Price: ", car->GetCurrentPrice(), "$");
	}
	else
	{
		throw("Invalid Item type");
	}
}

void CarDealer::BuyFromCustomer()
{
	m_ConsoleManager.ClearConsole();
	m_ConsoleManager.Print("Please give info about the product that you want to sell: ", '\n');

	m_ConsoleManager.Print("Model: "); 
	std::string ModelName = m_Customer.GetAnswer<std::string>();

	m_ConsoleManager.Print('\n', "Year of first registration: ");
	uint32_t YearOfFirstRegistration = m_Customer.GetAnswer<uint32_t>();

	m_ConsoleManager.Print('\n', "Price ($): ");
	uint32_t Price = m_Customer.GetAnswer<uint32_t>();

	m_Shop->AddAvailableProduct({std::make_shared<Car>(ModelName, YearOfFirstRegistration, Price * 1.2), m_TimeManager.Now()});
	ThankForTransaction();
}

