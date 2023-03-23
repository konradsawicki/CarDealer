#pragma once

#include <chrono>
#include <thread>
#include <iostream>
#include <string>
#include <type_traits>
#include <conio.h>

class ConsoleManager
{
public:
	void Log(const std::string& message) const
	{
		ClearConsole();
		std::cout << message << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(2));
	}

	void ClearConsole() const { system("cls"); }

	template<typename ... Types>
	void Print(const Types& ... messages) const { ((std::cout << messages), ...) << std::endl; }

	template<typename T>
	T GetInput() const { throw("Invalid input type"); } // static_assert(false); doesn't work, don't know why

	template<>
	uint32_t GetInput<uint32_t>() const
	{
		uint32_t Input;
		if (std::cin >> Input)
		{
			ClearBuffer();
			return Input;
		}
		else
		{
			ClearBuffer();
			throw("Invalid input type");
		}
	}

	template<>
	std::string GetInput<std::string>() const
	{
		std::string Input;
		if (getline(std::cin, Input))
		{
			return Input;
		}
		else
		{
			throw("Invalid input type");
		}
	}

	template<>
	char GetInput<char>() const { return _getch(); }

protected:
	void ClearBuffer() const
	{
		std::cin.clear(); 
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
};



