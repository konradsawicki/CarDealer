#include "Dealer.h"

template <typename A, typename B>
inline A Division(A x, B y)
{
	if (y != 0)
	{
		return x / y;
	}
	else
	{
		throw("Division by 0");
	}
}

void Dealer::Run()
{
	InitProducts();

	while (!b_CustomerExited && !b_ShopClosed)
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

void Dealer::ShowAvailableProducts()
{
	m_ConsoleMenager.Print("List of available products:", '\n');
	for (uint32_t i = 0; i < m_AvailableProducts.size(); i++)
	{
		UpdateProductPrice(m_AvailableProducts[i]);
		m_ConsoleMenager.Print(i + 1, ". product");
		ShowProduct(m_AvailableProducts[i]);
		m_ConsoleMenager.Print('\n');
	}
}

void Dealer::ShowSoldProducts()
{
	m_ConsoleMenager.Print("List of sold products: ", '\n');
	for (uint32_t i = 0; i < m_SoldProducts.size(); i++)
	{
		m_ConsoleMenager.Print(i + 1, ". product");
		ShowProduct(m_SoldProducts[i]);
		m_ConsoleMenager.Print('\n');
	}
}

void Dealer::WelcomeCustomer()
{
	m_ConsoleMenager.ClearConsole();
	m_ConsoleMenager.Print("Welcome!");
	m_ConsoleMenager.Print("Type 1 to buy a product, 2 to sell a product or 3 to exit shop and accept with ENTER");

	uint32_t Choice = m_Customer.GetAnswer<uint32_t>();
	switch (static_cast<SERVICE_TYPE>(Choice))
	{
		case SERVICE_TYPE::BUY: SellToCustomer(); break;
		case SERVICE_TYPE::SELL: BuyFromCustomer(); break;
		case SERVICE_TYPE::EXIT: EndWorkingDay(); break;
		default: throw("Invalid service type");
	}
}

void Dealer::UpdateProductPrice(ProductInfo& ProdInfoToUpdate)
{
	seconds ElapsedTime = m_TimeMenager.CalculateDuration<seconds>(m_TimeMenager.Now(), ProdInfoToUpdate.second);
	uint32_t IntervalNumberInElapsedTime = Division(ElapsedTime.count(), m_DeprecationTimeInterval);
	auto BasePrice = ProdInfoToUpdate.first->GetBasePrice();
	auto CurrentPrice = ProdInfoToUpdate.first->GetCurrentPrice();

	if (ElapsedTime.count() > m_TimeAfterDeprecationStarts &&
		BasePrice - CurrentPrice < BasePrice * m_MaxDeprecation)
	{
		CurrentPrice -= CurrentPrice * m_DeprecationStep * IntervalNumberInElapsedTime;
		ProdInfoToUpdate.first->SetCurrentPrice(CurrentPrice);
	}
}

void Dealer::SellToCustomer()
{
	m_ConsoleMenager.ClearConsole();
	if (!m_AvailableProducts.empty())
	{
		ShowAvailableProducts();
		m_ConsoleMenager.Print("Type number between 1 and ", m_AvailableProducts.size(), " to choose the product and accept with ENTER");
		uint32_t ChosenProductIndex = m_Customer.GetAnswer<uint32_t>();

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
	else
	{
		m_ConsoleMenager.Log("No cars to sell currently.");
	}
}

void Dealer::ThankForTransaction()
{
	m_ConsoleMenager.Log("Thank you for the transaction! You will be moved to the main menu in a while.");
}

void Dealer::EndWorkingDay()
{
	m_ConsoleMenager.ClearConsole();
	m_ConsoleMenager.Print("Workday has ended!");
	while (!b_ShopClosed)
	{
		m_ConsoleMenager.Print("Type 1 to see available products, 2 to see sold products or 3 to close the shop.");
		switch (m_Owner.GetAnswer<uint32_t>())
		{
			case 1: m_ConsoleMenager.ClearConsole(); 
					ShowAvailableProducts(); 
					m_ConsoleMenager.Print("Press anything to go back.");
					m_Owner.GetAnswer<char>();
					m_ConsoleMenager.ClearConsole();
					break;

			case 2: m_ConsoleMenager.ClearConsole();
					ShowSoldProducts();
					m_ConsoleMenager.Print("Press anything to go back.");
					m_Owner.GetAnswer<char>();
					m_ConsoleMenager.ClearConsole();
					break;

			case 3: CloseShop(); break;

			default: throw("Invalid choice");
		}
	}
}

void Dealer::CloseShop()
{
	b_ShopClosed = true;
}

