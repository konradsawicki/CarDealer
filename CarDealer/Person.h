#pragma once

#include "ConsoleMenager.h"
#include <type_traits>

class Person
{
public:
	template<typename T>
	T GetAnswer() const
	{
		return m_ConsoleMenager.GetInput<T>();
	}

protected:
	ConsoleMenager m_ConsoleMenager;
};

