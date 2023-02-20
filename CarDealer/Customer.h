#pragma once
#include "Utils.h"
#include <type_traits>

class Customer
{
public:
    template<typename T>
	typename std::enable_if_t<!std::is_same_v<T, std::string>> Answer(T& Info)
	{
		if (std::cin >> Info)
		{
			CLEAR_BUFFER();
		}
		else
		{
			CLEAR_BUFFER();
			throw("Invalid input type");
		}
	}

	template<typename T>
	typename std::enable_if_t<std::is_same_v<T, std::string>> Answer(T& Info)
	{
		if (getline(std::cin, Info));
		else
		{
			throw("Invalid input type");
		}
	}
};

