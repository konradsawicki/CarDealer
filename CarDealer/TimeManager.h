#pragma once

#include <chrono>

using namespace std::chrono;

class TimeManager
{
public:
	template<typename T>
	T CalculateDuration(high_resolution_clock::time_point tp1, high_resolution_clock::time_point tp2)
	{
		return duration_cast<T>(tp1 - tp2);
	}


	high_resolution_clock::time_point Now()
	{
		return high_resolution_clock::now();
	}
};

