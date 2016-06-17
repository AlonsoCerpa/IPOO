#include "IceCreamShop.h"
#include <iostream>

IceCream *IceCream::makeIceCream(int choice)
{
    if (choice == 1)
        return new ChocolateIC;
    else if (choice == 2)
        return new VanillaIC;
    else if (choice == 3)
        return new LucumaIC;
}

IceCream::~IceCream() {}

////////////////////////////////////////////////////////

void ChocolateIC::getInfoIC()
{
    std::cout << "Chocolate ice cream." << std::endl;
}

void VanillaIC::getInfoIC()
{
    std::cout << "Vanilla ice cream." << std::endl;
}

void LucumaIC::getInfoIC()
{
    std::cout << "Lucuma ice cream." << std::endl;
}


