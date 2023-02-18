#include "Car.h"

Car::Car(const std::string& ModelName, uint32_t YearOfFirstRegistration, float Price)
	: Product(Price), m_ModelName(ModelName), m_YearOfFirstRegistration(YearOfFirstRegistration)

{
}

const std::string& Car::GetModelName() const
{
	return m_ModelName;
}

uint32_t Car::GetYearOfFirstRegistration() const
{
	return m_YearOfFirstRegistration;
}

