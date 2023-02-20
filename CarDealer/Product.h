#pragma once

#include <stdint.h>

class Product
{
public:
	Product(uint32_t BasePrice);

	virtual uint32_t GetBasePrice() const;
	virtual uint32_t GetCurrentPrice() const;
	virtual void SetCurrentPrice(uint32_t CurrentPrice);

	virtual ~Product() {};

protected:
	uint32_t m_BasePrice;
	uint32_t m_CurrentPrice;
};

