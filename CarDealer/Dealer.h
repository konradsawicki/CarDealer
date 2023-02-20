#pragma once

#include <vector>
#include <memory>

#include "Product.h"
#include "Customer.h"
#include "ConsoleMenager.h"

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

	virtual void ShowProducts(std::vector<ProductInfo>& Products);
	virtual void ShowProduct(const std::unique_ptr<Product>& Product) const = 0;

	virtual void WelcomeCustomer();

	virtual void UpdateProductPrice(ProductInfo& ProductInfoToUpdate);

	virtual void BuyFromCustomer() = 0;
	virtual void SellToCustomer();

	virtual void ThankForTransaction();

	virtual void CloseShop();

protected:
	std::vector<ProductInfo> m_AvailableProducts;
	std::vector<ProductInfo> m_SoldProducts;

	float m_DeprecationStep = 0.01; // decimal (0.1%)
	float m_MaxDeprecation = 0.2; // decimal (20%)
	uint32_t m_DeprecationTimeInterval = 10; // seconds
	uint32_t m_TimeAfterDeprecationStarts = 30; // seconds

	Customer m_Customer;
	ConsoleMenager m_ConsoleMenager;

	bool b_CustomerExited = false;
};

