#include "Shop.h"


void Shop::Run()
{
	InitProducts();
}

void Shop::RemoveAvailableProduct(uint32_t Index)
{
	if (Index < m_AvailableProducts.size())
	{
		m_AvailableProducts.erase(m_AvailableProducts.cbegin() + Index);
	}
	else
	{
		throw(std::exception("Index out of bounds"));
	}
}

const std::vector<Product>& Shop::GetAvailableProducts() const
{
    return m_AvailableProducts;
}

const std::vector<Product>& Shop::GetSoldProducts() const
{
    return m_SoldProducts;
}

void Shop::UpdateProductPrice(uint32_t Index) const
{
	if (Index < m_AvailableProducts.size())
	{
		seconds ElapsedTime = m_TimeManager.CalculateDuration<seconds>(m_TimeManager.Now(), m_AvailableProducts[Index].Time);
		uint32_t IntervalNumberInElapsedTime = ElapsedTime.count() / m_DeprecationTimeInterval;
		uint32_t BasePrice = m_AvailableProducts[Index].Item->GetBasePrice();
		uint32_t CurrentPrice = m_AvailableProducts[Index].Item->GetCurrentPrice();

		if (ElapsedTime.count() > m_TimeAfterDeprecationStarts &&
			BasePrice - CurrentPrice < BasePrice * m_MaxDeprecation)
		{
			uint32_t DeprecationValue = BasePrice * m_DeprecationStep * (IntervalNumberInElapsedTime - m_TimeAfterDeprecationStarts / m_DeprecationTimeInterval);

			if (DeprecationValue >= BasePrice * m_MaxDeprecation)
			{
				m_AvailableProducts[Index].Item->SetCurrentPrice(BasePrice - BasePrice * m_MaxDeprecation);
			}
			else
			{
				m_AvailableProducts[Index].Item->SetCurrentPrice(BasePrice - DeprecationValue);
			}
		}
	}
	else
	{
		throw(std::exception("Index out of bounds"));
	}
}

