#include "myAppLib.h"
#include "buildVersion.h"
#include <iostream>

MyAppLib::MyAppLib(void)
{
    STACK

    std::cout << " MyAppLib::MyAppLib()" << std::endl;
}

MyAppLib::~MyAppLib(void)
{
    STACK

    std::cout << " MyAppLib::~MyAppLib()" << std::endl;
}

void    MyAppLib::print(void)
{
    STACK

    std::cout << " MyAppLib::print(Hello World!!!)" << std::endl;
}
