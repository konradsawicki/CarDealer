#pragma once

#include <memory>
#include <vector>

#include "TimeManager.h"
#include "Item.h"

struct Product
{
	std::shared_ptr<Item> Item;
	std::chrono::high_resolution_clock::time_point Time;
};

class Shop
{
protected:
	virtual void InitProducts() = 0;

public:
	virtual void Run();
	virtual void AddAvailableProduct(const std::shared_ptr<Item>& Item) = 0;
	virtual void AddSoldProduct(const std::shared_ptr<Item>& Item) = 0;

	virtual void RemoveAvailableProduct(uint32_t Index);

	virtual const std::vector<Product>& GetAvailableProducts() const;
	virtual const std::vector<Product>& GetSoldProducts() const;

	virtual void UpdateProductPrice(uint32_t Index);

	
	
	virtual ~Shop() {}

protected:
	std::vector<Product> m_AvailableProducts;
	std::vector<Product> m_SoldProducts;

	TimeManager m_TimeManager;

	float m_DeprecationStep = 0.001f;			// decimal (multiply by 100 to get percents)
	float m_MaxDeprecation = 0.2f;				// decimal (multiply by 100 to get percents)
	uint32_t m_DeprecationTimeInterval = 10;	// seconds
	uint32_t m_TimeAfterDeprecationStarts = 30; // seconds
};

template <typename A, typename B>
inline float Division(A x, B y)
{
	if (y != 0)
	{
		return x / y;
	}
	else
	{
		throw(std::exception());
	}
}
