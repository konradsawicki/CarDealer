#pragma once

#include "Dealer.h"

class CarDealer :
    public Dealer
{
protected:
    void InitShop() override;
    void ShowProduct(const Product& Item) const override;
    void BuyFromCustomer() override;
};

