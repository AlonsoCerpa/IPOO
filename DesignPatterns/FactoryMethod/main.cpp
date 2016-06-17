#include <iostream>
#include <vector>

#include "IceCreamShop.h"

int main()
{
    std::vector<IceCream *> iceCreams;
    int choice;

    std::cout << "Chocolate(1), Vanilla(2), Lucuma(3): ";
    std::cin >> choice;

    while (choice >= 1 && choice <= 3)
    {
        iceCreams.push_back(IceCream::makeIceCream(choice));

        std::cout << "Chocolate(1), Vanilla(2), Lucuma(3): ";
        std::cin >> choice;
    }

    std::cout << std::endl;

    for (unsigned i = 0; i < iceCreams.size(); i++)
    {
        iceCreams[i]->getInfoIC();
        delete iceCreams[i];
    }

    return 0;
}
