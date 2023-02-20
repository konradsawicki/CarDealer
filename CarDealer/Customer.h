#pragma once

#include "ConsoleMenager.h"
#include <type_traits>

class Customer
{
public:
    template<typename T>
	void Answer(T& Input) const
	{
		m_ConsoleMenager.TakeInput(Input);
	}

protected:
	ConsoleMenager m_ConsoleMenager;
};

