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

	virtual ~Person() {}
protected:
	ConsoleManager m_ConsoleManager;
};

