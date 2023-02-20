#pragma once

#include "Dealer.h"
#include "Car.h"

class CarDealer :
    public Dealer
{
protected:
    void InitProducts() override;
    void ShowProducts(const std::vector<ProductInfo>& ProductsToShow) override;
    void BuyFromCustomer() override;
};

