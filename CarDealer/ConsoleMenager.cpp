#include "ConsoleMenager.h"

void ConsoleMenager::ClearConsole() const
{
	system("cls");
}

void ConsoleMenager::ClearBuffer() const
{
	std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void ConsoleMenager::Log(const std::string& message) const
{
	ClearConsole();
	std::cout << message << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
}
