#pragma once

#include <vector>
#include <memory>

#include "Product.h"
#include "Owner.h"
#include "Customer.h"
#include "ConsoleMenager.h"
#include "TimeMenager.h"

enum class SERVICE_TYPE
{
	BUY = 1, SELL = 2, EXIT = 3
};

class Dealer
{
public:
	using time = std::chrono::high_resolution_clock::time_point;
	using ProductInfo = std::pair<std::unique_ptr<Product>, time>;

	virtual void Run();
	virtual ~Dealer() {}

protected:
	virtual void InitProducts() = 0;

	virtual void ShowAvailableProducts();
	virtual void ShowSoldProducts();

	virtual void ShowProduct(const ProductInfo& Product) const = 0;

	virtual void WelcomeCustomer();

	virtual void UpdateProductPrice(ProductInfo& Product);

	virtual void BuyFromCustomer() = 0;
	virtual void SellToCustomer();

	virtual void ThankForTransaction();

	virtual void EndWorkingDay();
	virtual void CloseShop();

protected:
	std::vector<ProductInfo> m_AvailableProducts;
	std::vector<ProductInfo> m_SoldProducts;

	float m_DeprecationStep = 0.01f; // decimal (multiply by 100 to get percents)
	float m_MaxDeprecation = 0.2f; // decimal (multiply by 100 to get percents)
	uint32_t m_DeprecationTimeInterval = 10; // seconds
	uint32_t m_TimeAfterDeprecationStarts = 30; // seconds

	Owner m_Owner;
	Customer m_Customer;

	ConsoleMenager m_ConsoleMenager;
	TimeMenager m_TimeMenager;

	bool b_CustomerExited = false;
	bool b_ShopClosed = false;
};

