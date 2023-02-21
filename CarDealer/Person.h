#pragma once

#include "ConsoleManager.h"

class Person
{
public:
	template<typename T>
	T GetAnswer() const
	{
		return m_ConsoleManager.GetInput<T>();
	}

protected:
	ConsoleManager m_ConsoleManager;
};

