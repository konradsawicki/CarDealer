#pragma once

#include <chrono>
#include <thread>
#include <iostream>

#define LOG(x) system("cls");\
std::cout << x << std::endl;\
std::this_thread::sleep_for(std::chrono::seconds(2))

#define PRINT(x, y) std::cout << x << y << std::endl