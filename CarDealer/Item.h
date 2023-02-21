#pragma once

#include <stdint.h>
#include "ConsoleManager.h"

class Item
{
public:
	Item(uint32_t BasePrice)
		: m_BasePrice(BasePrice), m_CurrentPrice(BasePrice) {}

	virtual uint32_t GetBasePrice() const { return m_BasePrice; }
	virtual uint32_t GetCurrentPrice() const { return m_CurrentPrice; }
	virtual void SetCurrentPrice(uint32_t CurrentPrice) { m_CurrentPrice = CurrentPrice; }

	virtual ~Item() {};

protected:
	uint32_t m_BasePrice;
	uint32_t m_CurrentPrice;
};

