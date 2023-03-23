#include "CarDealer.h"
#include "CarShop.h"
#include "Car.h"


void CarDealer::InitShop()
{
	m_Shop = std::make_unique<CarShop>();
	m_Shop->Run();
}

void CarDealer::ShowProduct(const Product& Product) const
{
	if (auto car = std::dynamic_pointer_cast<Car>(Product.Item))
	{
		m_ConsoleManager.Print("Model: ", car->GetModelName());
		m_ConsoleManager.Print("Year of first registration: ", car->GetYearOfFirstRegistration());
		m_ConsoleManager.Print("Price: ", car->GetCurrentPrice(), "$");
	}
	else
	{
		throw(std::exception());
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

	m_Shop->AddAvailableProduct(std::make_shared<Car>(ModelName, YearOfFirstRegistration, static_cast<uint32_t>(Price * 1.2)));
	ThankForTransaction();
}

