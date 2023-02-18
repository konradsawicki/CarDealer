#include "Product.h"

Product::Product(float Price)
	: m_Price(Price)
{
}

float Product::GetPrice() const
{
	return m_Price;
}

void Product::SetPrice(float Price)
{
	m_Price = Price;
}
