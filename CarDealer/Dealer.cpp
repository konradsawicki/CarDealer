#include "Dealer.h"

void Dealer::Run()
{
	while (!b_CustomerExited) //dodac jakis warunek exitujacy
	{
		try
		{
			WelcomeCustomer();
		}
		catch (...)
		{
			LOG("Something went wrong. Try again in a while.");
		}
	}
}

void Dealer::WelcomeCustomer()
{
	system("cls");
	PRINT("Welcome!");
	PRINT("Would you like to buy or sell a product?");

	switch (m_Customer.ChooseService())
	{
		case SERVICE_TYPE::BUY: SellToCustomer(); break;
		case SERVICE_TYPE::SELL: BuyFromCustomer(); break;
		case SERVICE_TYPE::EXIT: b_CustomerExited = true; break;
		default: throw("Invalid service type");
	}
}

void Dealer::UpdateProductPrice(ProductInfo& ProductInfoToUpdate)
{
	using namespace std::chrono;
	seconds ElapsedTime = duration_cast<seconds>(high_resolution_clock::now() - ProductInfoToUpdate.second);
	uint32_t TenSecsNumber = ElapsedTime.count() / 10;
}

void Dealer::SellToCustomer()
{
	system("cls");
	PRINT("List of available products:") << std::endl;
	ShowProducts(m_AvailableProducts);
	PRINT("Which product would you like to buy?");
	uint32_t ChosenProductIndex = m_Customer.ChooseProduct(m_AvailableProducts.size()) - 1;
	m_SoldProducts.push_back(std::move(m_AvailableProducts[ChosenProductIndex]));
	m_AvailableProducts.erase(m_AvailableProducts.begin() + ChosenProductIndex);
}
