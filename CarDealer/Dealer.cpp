#include "Dealer.h"

void Dealer::OpenShop()
{
	InitShop();

	while (!b_CustomerExited && !b_ShopClosed)
	{
		try
		{
			WelcomeCustomer();
		}
		catch (const char* message)
		{
			m_ConsoleManager.Log(message + std::string(". Try again in a while."));
		}
		catch (const std::exception& e)
		{
			m_ConsoleManager.Log(std::string("Fatal error. ") + e.what());
			exit(1);
		}
		catch (...)
		{
			m_ConsoleManager.Log("Something went wrong. Check the source code.");
			exit(2);
		}
	}
}

void Dealer::ShowAvailableProducts() const
{
	m_ConsoleManager.Print("List of available products:", '\n');
	for (uint32_t i = 0; i < m_Shop->GetAvailableProducts().size(); i++)
	{
		m_Shop->UpdateProductPrice(i);
		m_ConsoleManager.Print(i + 1, ". product");
		ShowProduct(m_Shop->GetAvailableProducts()[i]);
		m_ConsoleManager.Print('\n');
	}
}

void Dealer::ShowSoldProducts() const
{
	m_ConsoleManager.Print("List of sold products: ", '\n');
	for (uint32_t i = 0; i < m_Shop->GetAvailableProducts().size(); i++)
	{
		m_ConsoleManager.Print(i + 1, ". product");
		ShowProduct(m_Shop->GetAvailableProducts()[i]);
		m_ConsoleManager.Print('\n');
	}
}

void Dealer::WelcomeCustomer()
{
	m_ConsoleManager.ClearConsole();
	m_ConsoleManager.Print("Welcome!");
	m_ConsoleManager.Print("Type 1 to buy a product, 2 to sell a product or 3 to exit the shop and accept with ENTER");

	uint32_t Choice = m_Customer.GetAnswer<uint32_t>();
	switch (Choice)
	{
		case 1: SellToCustomer(); break;
		case 2: BuyFromCustomer(); break;
		case 3: EndWorkDay(); break;
		default: throw("Invalid choice");
	}
}

void Dealer::SellToCustomer() const
{
	m_ConsoleManager.ClearConsole();
	if (!m_Shop->GetAvailableProducts().empty())
	{
		ShowAvailableProducts();
		m_ConsoleManager.Print("Type number between 1 and ", m_Shop->GetAvailableProducts().size(), " to choose the product and accept with ENTER");
		uint32_t ChosenProductIndex = m_Customer.GetAnswer<uint32_t>();

		if (ChosenProductIndex >= 1 && ChosenProductIndex <= m_Shop->GetAvailableProducts().size())
		{
			ChosenProductIndex -= 1;
			m_Shop->AddSoldProduct(m_Shop->GetAvailableProducts()[ChosenProductIndex].Item);
			m_Shop->RemoveAvailableProduct(ChosenProductIndex);

			ThankForTransaction();
		}
		else
		{
			throw("Invalid choice");
		}
	}
	else
	{
		m_ConsoleManager.Log("No cars to sell currently.");
	}
}

void Dealer::ThankForTransaction() const
{
	m_ConsoleManager.Log("Thank you for the transaction! You will be moved to the main menu in a while.");
}

void Dealer::EndWorkDay()
{
	m_ConsoleManager.ClearConsole();
	m_ConsoleManager.Print("Workday has ended!");
	while (!b_ShopClosed)
	{
		m_ConsoleManager.Print("Type 1 to see available products, 2 to see sold products or 3 to close the shop.");
		switch (GetAnswer<uint32_t>())
		{
			case 1: m_ConsoleManager.ClearConsole(); 
					ShowAvailableProducts(); 
					m_ConsoleManager.Print("Press anything to go back.");
					GetAnswer<char>();
					m_ConsoleManager.ClearConsole();
					break;

			case 2: m_ConsoleManager.ClearConsole();
					ShowSoldProducts();
					m_ConsoleManager.Print("Press anything to go back.");
					GetAnswer<char>();
					m_ConsoleManager.ClearConsole();
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

