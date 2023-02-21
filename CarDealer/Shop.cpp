#include "Shop.h"

template <typename A, typename B>
inline float Division(A x, B y)
{
	if (y != 0)
	{
		return x / y;
	}
	else
	{
		throw("Division by 0");
	}
}

void Shop::Run()
{
	InitProducts();
}

void Shop::AddAvailableProduct(const Product& Product)
{
	m_AvailableProducts.push_back(Product);
}

void Shop::AddSoldProduct(const Product& Product)
{
	m_SoldProducts.push_back(Product);
}

void Shop::RemoveAvailableProduct(const std::vector<Product>::const_iterator& Iterator)
{
	m_AvailableProducts.erase(Iterator);
}

const std::vector<Product>& Shop::GetAvailableProducts() const
{
    return m_AvailableProducts;
}

const std::vector<Product>& Shop::GetSoldProducts() const
{
    return m_SoldProducts;
}

void Shop::UpdateProductPrice(uint32_t Index)
{
	seconds ElapsedTime = m_TimeManager.CalculateDuration<seconds>(m_TimeManager.Now(), m_AvailableProducts[Index].Time);
	uint32_t IntervalNumberInElapsedTime = Division(ElapsedTime.count(), m_DeprecationTimeInterval);
	uint32_t BasePrice = m_AvailableProducts[Index].Item->GetBasePrice();
	uint32_t CurrentPrice = m_AvailableProducts[Index].Item->GetCurrentPrice();

	if (ElapsedTime.count() > m_TimeAfterDeprecationStarts &&
		BasePrice - CurrentPrice < BasePrice * m_MaxDeprecation)
	{
		uint32_t DeprecationValue = BasePrice * m_DeprecationStep * (IntervalNumberInElapsedTime - m_TimeAfterDeprecationStarts / m_DeprecationTimeInterval);

		if (BasePrice - CurrentPrice >= BasePrice * m_MaxDeprecation)
		{
			m_AvailableProducts[Index].Item->SetCurrentPrice(BasePrice - BasePrice * m_MaxDeprecation);
		}
		else
		{
			m_AvailableProducts[Index].Item->SetCurrentPrice(BasePrice - DeprecationValue);
		}
	}
}

