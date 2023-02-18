#pragma once

#include <vector>
#include <memory>

#include "Utils.h"
#include "Product.h"
#include "Customer.h"

class Dealer
{
public:
	using time = std::chrono::high_resolution_clock::time_point;
	using ProductInfo = std::pair<std::unique_ptr<Product>, time>;

	virtual void Run();

protected:
	virtual void InitProducts() = 0;
	virtual void ShowProducts(const std::vector<ProductInfo>& ProductsToShow) = 0;

	virtual void WelcomeCustomer();

	virtual void UpdateProductPrice(ProductInfo& ProductInfoToUpdate);

	virtual void BuyFromCustomer();
	virtual void SellToCustomer();

	virtual ~Dealer() {}

protected:
	std::vector<ProductInfo> m_AvailableProducts;
	std::vector<ProductInfo> m_SoldProducts;

	Customer m_Customer;
};

