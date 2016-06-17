#include "Cellphones.h"
#include <iostream>

int Cellphone::totalCellp = 0;

Cellphone::Cellphone()
{
    id = totalCellp++;
}

Cellphone::~Cellphone() {}

void Cellphone::getDescription() const
{
    std::cout << "Cellphone " << id << ": No brand specified" << std::endl;
}

//////////////////////////////////////////////////////////////////////////////

void SamsungCheapCellp::getDescription() const
{
    std::cout << "Cellphone " << id << ": Samsung Galaxy A3" << std::endl;
}

void SamsungExpensiveCellp::getDescription() const
{
    std::cout << "Cellphone " << id << ": Samsung Galaxy S6" << std::endl;
}

void LGCheapCellp::getDescription() const
{
    std::cout << "Cellphone " << id << ": LG G3" << std::endl;
}

void LGExpensiveCellp::getDescription() const
{
    std::cout << "Cellphone " << id << ": LG G4" << std::endl;
}

//////////////////////////////////////////////////////////////////////////////

Factory::~Factory() {}

//////////////////////////////////////////////////////////////////////////////

Cellphone *SamsungFactory::createCheapCellp()
{
    return new SamsungCheapCellp;
}

Cellphone *SamsungFactory::createExpensiveCellp()
{
    return new SamsungExpensiveCellp;
}


Cellphone *LGFactory::createCheapCellp()
{
    return new LGCheapCellp;
}

Cellphone *LGFactory::createExpensiveCellp()
{
    return new LGExpensiveCellp;
}



