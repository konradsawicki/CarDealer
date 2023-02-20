#pragma once

#include "Dealer.h"
#include "Car.h"

class CarDealer :
    public Dealer
{
protected:
    void InitProducts() override;
    void ShowProduct(const std::unique_ptr<Product>& ProductToShow) const override;
    void BuyFromCustomer() override;
};

