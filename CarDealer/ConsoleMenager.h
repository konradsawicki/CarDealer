#pragma once

#include <chrono>
#include <thread>
#include <iostream>
#include <sstream>


class ConsoleMenager
{
public:
	template<typename ... Types>
	void Print(const Types& ... messages) const;

	void Log(const std::string& message) const;

	void ClearConsole() const;

	void ClearBuffer() const;

	void EndLine() const;

	template<typename T>
	typename std::enable_if_t<std::is_same_v<T, std::string>> TakeInput(T& Input) const;

	template<typename T>
	typename std::enable_if_t<!std::is_same_v<T, std::string>> TakeInput(T& Input) const;
};

template<typename ... Types>
inline void ConsoleMenager::Print(const Types& ... messages) const
{
	((std::cout << messages << ' '), ...) << std::endl;
}

template<typename T>
inline typename std::enable_if_t<std::is_same_v<T, std::string>> ConsoleMenager::TakeInput(T& Input) const
{
	if (getline(std::cin, Input));
	else
	{
		throw("Invalid input type");
	}
}

template<typename T>
inline typename std::enable_if_t<!std::is_same_v<T, std::string>> ConsoleMenager::TakeInput(T& Input) const
{
	if (std::cin >> Input)
	{
		ClearBuffer();
	}
	else
	{
		ClearBuffer();
		throw("Invalid input type");
	}
}



