#pragma once

#include "Dealer.h"
#include "Car.h"

class CarDealer :
    public Dealer
{
protected:
    void InitProducts() override;
    void ShowProduct(const ProductInfo& Product) const override;
    void BuyFromCustomer() override;
};

