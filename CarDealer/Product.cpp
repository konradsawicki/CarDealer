#include "Product.h"

Product::Product(uint32_t BasePrice)
	: m_BasePrice(BasePrice), m_CurrentPrice(BasePrice)
{
}

uint32_t Product::GetBasePrice() const
{
	return m_BasePrice;
}

uint32_t Product::GetCurrentPrice() const
{
	return m_CurrentPrice;
}

void Product::SetCurrentPrice(uint32_t CurrentPrice)
{
	m_CurrentPrice = CurrentPrice;
}
