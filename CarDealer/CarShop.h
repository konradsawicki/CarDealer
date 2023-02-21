#pragma once

#include "Shop.h"

class CarShop :
    public Shop
{
protected:
	virtual void InitProducts() override;
};

