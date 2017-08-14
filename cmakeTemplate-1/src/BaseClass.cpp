#include "BaseClass.h"
#include <iostream>

BaseClass::BaseClass(void)
{
    std::cout << "BaseClass::BaseClass()" << std::endl;
}

BaseClass::~BaseClass(void)
{
    std::cout << "BaseClass::~BaseClass()" << std::endl;
}

void BaseClass::print(void)
{
    std::cout << "BaseClass::print(Hello World!!!)" << std::endl;
}
