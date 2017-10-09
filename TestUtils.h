#pragma once

#include "TL.h"

#define PB(a) std::cout << std::boolalpha << (a) << std::endl;

void print(TL::NullType)
{
    std::cout << std::endl;
}

void print(int)
{
    std::cout << "int, ";
}

void print(int*)
{
    std::cout << "int*, ";
}

void print(char)
{
    std::cout << "char, ";
}

void print(double)
{
    std::cout << "double, ";
}

void print(bool)
{
    std::cout << "bool, ";
}

void print(unsigned char)
{
    std::cout << "unsigned char, ";
}

void print(unsigned short)
{
    std::cout << "unsigned short, ";
}

void print(unsigned int)
{
    std::cout << "unsigned int, ";
}

void print(unsigned long int)
{
    std::cout << "unsigned long int, ";
}

void print(unsigned long long int)
{
    std::cout << "unsigned long long int, ";
}

void print(char*)
{
    std::cout << "char*, ";
}

template <typename H, typename ... Args>
void print(TL::TypeList<H, Args...>)
{
    print(H());
    print(typename TL::TypeList<H, Args ...>::TailType());
}
