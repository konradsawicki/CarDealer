#include "Dealer.h"


void Dealer::Run()
{
	InitProducts();

	while (!b_CustomerExited)
	{
		try
		{
			WelcomeCustomer();
		}
		catch (...)
		{
			m_ConsoleMenager.Log("Something went wrong. Try again in a while.");
		}
	}
}

void Dealer::ShowProducts(std::vector<ProductInfo>& ProductsInfo)
{
	for (uint32_t i = 0; i < ProductsInfo.size(); i++)
	{
		if (!b_CustomerExited)
		{
			UpdateProductPrice(ProductsInfo[i]);
		}
		m_ConsoleMenager.Print(i + 1, ". product");
		ShowProduct(ProductsInfo[i].first);
	}
}

void Dealer::WelcomeCustomer()
{
	m_ConsoleMenager.ClearConsole();
	m_ConsoleMenager.Print("Welcome!");
	m_ConsoleMenager.Print("Type 1 to buy a product, 2 to sell a product or 3 to exit shop and accept with ENTER");

	uint32_t Choice;
	m_Customer.Answer(Choice);

	switch (static_cast<SERVICE_TYPE>(Choice))
	{
		case SERVICE_TYPE::BUY: SellToCustomer(); break;
		case SERVICE_TYPE::SELL: BuyFromCustomer(); break;
		case SERVICE_TYPE::EXIT: CloseShop(); break;
		default: throw("Invalid service type");
	}
}

void Dealer::UpdateProductPrice(ProductInfo& ProdInfoToUpdate)
{
	using namespace std::chrono;

	seconds ElapsedTime = duration_cast<seconds>(high_resolution_clock::now() - ProdInfoToUpdate.second); // func
	uint32_t IntervalNumberInElapsedTime = ElapsedTime.count() / m_DeprecationTimeInterval; // func 
	auto BasePrice = ProdInfoToUpdate.first->GetBasePrice();
	auto CurrentPrice = ProdInfoToUpdate.first->GetCurrentPrice();

	if (ElapsedTime.count() > m_TimeAfterDeprecationStarts &&
		(BasePrice - CurrentPrice) < BasePrice * m_MaxDeprecation)
	{
		CurrentPrice -= CurrentPrice * m_DeprecationStep * IntervalNumberInElapsedTime;
		ProdInfoToUpdate.first->SetCurrentPrice(CurrentPrice);
	}
}

void Dealer::SellToCustomer()
{
	m_ConsoleMenager.ClearConsole();
	m_ConsoleMenager.Print("List of available products:", '\n');

	ShowProducts(m_AvailableProducts);
	m_ConsoleMenager.Print("Type number between 1 and ", m_AvailableProducts.size(), " to choose the product and accept with ENTER");
	uint32_t ChosenProductIndex;
	m_Customer.Answer(ChosenProductIndex);
	if (ChosenProductIndex >= 1 && ChosenProductIndex <= m_AvailableProducts.size()) // is in bounds funkcja sprawdzic
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
	m_ConsoleMenager.Log("Thank you for the transaction! You will be moved to the main menu in a while.");
}

void Dealer::CloseShop()
{
	b_CustomerExited = true;
	m_ConsoleMenager.ClearConsole();
	m_ConsoleMenager.Print("Workday has ended!");
	m_ConsoleMenager.Print("Sold products today: ", '\n');
	ShowProducts(m_SoldProducts);
}

