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

void Dealer::ShowProducts(const std::vector<ProductInfo>& ProductsInfoToShow) const
{
	uint32_t Index = 1;
	for (const auto& ProdInfo : ProductsInfoToShow)
	{
		m_ConsoleMenager.Print(Index, ". product");
		ShowProduct(ProdInfo);
		m_ConsoleMenager.EndLine();
		Index++;
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
	seconds ElapsedTime = duration_cast<seconds>(high_resolution_clock::now() - ProdInfoToUpdate.second);
	uint32_t IntervalNumberInElapsedTime = ElapsedTime.count() / m_DeprecationTimeInterval;
	if (ElapsedTime.count() > m_TimeAfterDeprecationStarts &&
		ProdInfoToUpdate.first->GetBasePrice() / ProdInfoToUpdate.first->GetCurrentPrice() >= m_MaxDeprecation)
	{

	}
}

void Dealer::SellToCustomer()
{
	m_ConsoleMenager.ClearConsole();
	m_ConsoleMenager.Print("List of available products:"); m_ConsoleMenager.EndLine();
	ShowProducts(m_AvailableProducts);
	m_ConsoleMenager.Print("Type number between 1 and ", m_AvailableProducts.size(), " to choose the product and accept with ENTER");
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
	m_ConsoleMenager.Log("Thank you for the transaction! You will be moved to the main menu in a while.");
	WelcomeCustomer();
}

void Dealer::CloseShop()
{
	b_CustomerExited = true;
}
