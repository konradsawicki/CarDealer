#pragma once

#include "Shop.h"
#include "Car.h"

class CarShop :
    public Shop
{
protected:
	void InitProducts() override;

public:
	void AddAvailableProduct(const std::shared_ptr<Item>& Item) override;
	void AddSoldProduct(const std::shared_ptr<Item>& Item) override;
};

