#include "Dealer.h"

void Dealer::Run()
{
	InitProducts();

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
	CLEAR_CONSOLE();
	PRINT("Welcome!");
	PRINT("Type 1 to buy a product, 2 to sell a product or 3 to exit shop and accept with ENTER");

	uint32_t Choice;
	m_Customer.Answer(Choice);

	switch (static_cast<SERVICE_TYPE>(Choice))
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
	CLEAR_CONSOLE();
	PRINT("List of available products:") << std::endl;
	ShowProducts(m_AvailableProducts);
	PRINT("Type number between 1 and ", m_AvailableProducts.size(), " to choose the product and accept with ENTER");
	uint32_t ChosenProductIndex;
	m_Customer.Answer(ChosenProductIndex);
	if (ChosenProductIndex >= 1 && ChosenProductIndex <= m_AvailableProducts.size())
	{
		ChosenProductIndex -= 1;
		m_SoldProducts.push_back(std::move(m_AvailableProducts[ChosenProductIndex]));
		m_AvailableProducts.erase(m_AvailableProducts.begin() + ChosenProductIndex);

		ThankForTransaction();
	}
	else
	{
		throw("Invalid index");
	}
}

void Dealer::ThankForTransaction()
{
	LOG("Thank you for the transaction! You will be moved to the main menu in a while.");
	WelcomeCustomer();
}
