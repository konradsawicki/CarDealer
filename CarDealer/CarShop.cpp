#include "CarShop.h"
#include "Car.h"

void CarShop::InitProducts()
{
	AddAvailableProduct({ std::make_shared<Car>("Honda Civic", 2010, 5000), m_TimeManager.Now() });
	AddAvailableProduct({ std::make_shared<Car>("Audi A6", 2005, 6000), m_TimeManager.Now() });
	AddAvailableProduct({ std::make_shared<Car>("BMW 3", 2008, 7000), m_TimeManager.Now() });
}


