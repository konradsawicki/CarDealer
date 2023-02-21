#include "pch.h"

#include "CarDealer.h"
#include "CarShop.h"


class UT_CarShop : public testing::Test
{
public:
	virtual void SetUp()
	{
		shop.AddAvailableProduct(std::make_shared<Car>("Test", 2005, 2000));
	}

	CarShop shop;
};

TEST_F(UT_CarShop, UT_AddAvailableProduct) 
{
	EXPECT_NO_THROW(shop.AddAvailableProduct(std::make_shared<Car>("Test", 2005, 2000)));
	EXPECT_ANY_THROW(shop.AddAvailableProduct(nullptr));
	EXPECT_ANY_THROW(shop.AddAvailableProduct(std::make_shared<Item>(1000)));
}

TEST_F(UT_CarShop, UT_AddSoldProduct)
{
	EXPECT_NO_THROW(shop.AddSoldProduct(std::make_shared<Car>("Test", 2005, 2000)));
	EXPECT_NO_THROW(shop.AddSoldProduct(std::shared_ptr<Car>(new Car("Test", 2005, 2000))));
	EXPECT_NO_THROW(shop.AddSoldProduct(std::shared_ptr<Item>(new Car("Test", 2005, 2000))));

	EXPECT_ANY_THROW(shop.AddSoldProduct(nullptr));
	EXPECT_ANY_THROW(shop.AddSoldProduct(std::make_shared<Item>(1000)));
	EXPECT_ANY_THROW(shop.AddSoldProduct(std::shared_ptr<Item>(new Item(2000))));
}

TEST_F(UT_CarShop, UT_RemoveAvailableProduct)
{
	EXPECT_NO_THROW(shop.RemoveAvailableProduct(0));
	EXPECT_ANY_THROW(shop.RemoveAvailableProduct(0));
	EXPECT_ANY_THROW(shop.RemoveAvailableProduct(1));
	EXPECT_ANY_THROW(shop.RemoveAvailableProduct(-1));
	EXPECT_ANY_THROW(shop.RemoveAvailableProduct(1000));
}

TEST_F(UT_CarShop, UT_UpdateProductPrice)
{
	EXPECT_NO_THROW(shop.UpdateProductPrice(0));
	EXPECT_ANY_THROW(shop.UpdateProductPrice(1));
	EXPECT_ANY_THROW(shop.UpdateProductPrice(-1));
	EXPECT_ANY_THROW(shop.UpdateProductPrice(1000));
}

TEST_F(UT_CarShop, UT_Division)
{
	EXPECT_NO_THROW(Division(100, 200));
	EXPECT_NO_THROW(Division(100, 200.0f));
	EXPECT_NO_THROW(Division(100, 200.0));
	EXPECT_NO_THROW(Division(100.0, 200.0));

	EXPECT_ANY_THROW(Division(100, 0.0f));
	EXPECT_ANY_THROW(Division(100, 0.0));
	EXPECT_ANY_THROW(Division(0.0, 0.0));
}
