#pragma once

#include <chrono>
#include <thread>
#include <iostream>

///////////////////////////////////////////////////////////

#define LOG(x) system("cls");\
std::cout << x << std::endl;\
std::this_thread::sleep_for(std::chrono::seconds(2))

///////////////////////////////////////////////////////////

#define GLUE(x, y) x y

#define RETURN_ARG_COUNT(_1_, _2_, _3_, _4_, _5_, count, ...) count
#define EXPAND_ARGS(args) RETURN_ARG_COUNT args
#define COUNT_ARGS_MAX5(...) EXPAND_ARGS((__VA_ARGS__, 5, 4, 3, 2, 1, 0))

#define OVERLOAD_MACRO2(name, count) name##count
#define OVERLOAD_MACRO1(name, count) OVERLOAD_MACRO2(name, count)
#define OVERLOAD_MACRO(name, count) OVERLOAD_MACRO1(name, count)

#define CALL_OVERLOAD(name, ...) GLUE(OVERLOAD_MACRO(name, COUNT_ARGS_MAX5(__VA_ARGS__)), (__VA_ARGS__))

#define PRINT1(x) std::cout << x << std::endl
#define PRINT2(x, y) std::cout << x << y << std::endl
#define PRINT3(x, y, z) std::cout << x << y << z << std::endl
#define PRINT(...) CALL_OVERLOAD(PRINT, __VA_ARGS__)

///////////////////////////////////////////////////////////

#define CLEAR_BUFFER() std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')

///////////////////////////////////////////////////////////