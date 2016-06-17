#include <iostream>
#include "Cellphones.h"

int main()
{
    Factory *abstractFactory;
    bool request = true;
    std::string factory;

    while (request)
    {
        Cellphone::totalCellp = 0;
        abstractFactory = nullptr;
        std::cout << "Enter the name of the factory: ";
        std::cin >> factory;

        if (factory == "Samsung")
            abstractFactory = new SamsungFactory;
        else if (factory == "LG")
            abstractFactory = new LGFactory;
        else if (factory == "close")
            request = false;
        else
            std::cout << "Enter a correct name of a factory." << std::endl << std::endl;

        if (abstractFactory != nullptr)
        {
            Cellphone *cellphones[3];

            cellphones[0] = abstractFactory->createCheapCellp();
            cellphones[1] = abstractFactory->createExpensiveCellp();
            cellphones[2] = abstractFactory->createCheapCellp();

            for (int i = 0; i < 3; i++){
                cellphones[i]->getDescription();
                delete cellphones[i];
            }

            std::cout << std::endl;
            delete abstractFactory;
        }
    }
    return 0;
}
