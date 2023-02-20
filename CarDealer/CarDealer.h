#pragma once

#include "Dealer.h"
#include "Car.h"

class CarDealer :
    public Dealer
{
protected:
    void InitProducts() override;
    void ShowProduct(const ProductInfo& ProductToShow) const override;
    void BuyFromCustomer() override;
};

