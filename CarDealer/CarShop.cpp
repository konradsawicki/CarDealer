#include "CarShop.h"


void CarShop::InitProducts()
{
	AddAvailableProduct(std::make_shared<Car>("Honda Civic", 2010, 5000));
	AddAvailableProduct(std::make_shared<Car>("Audi A6", 2005, 6000));
	AddAvailableProduct(std::make_shared<Car>("BMW 3", 2008, 7000));
}

void CarShop::AddAvailableProduct(const std::shared_ptr<Item>& Item)
{
	if (dynamic_cast<Car*>(Item.get()))
		m_AvailableProducts.emplace_back(Item, m_TimeManager.Now());
	else
	{
		throw(std::exception());
	}
}

void CarShop::AddSoldProduct(const std::shared_ptr<Item>& Item)
{
	if (dynamic_cast<Car*>(Item.get()))
		m_SoldProducts.emplace_back(Item, m_TimeManager.Now());
	else
	{
		throw(std::exception());
	}
}