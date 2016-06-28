#include <iostream>

#include "Node.h"
#include "CircularList.h"

int main()
{
    CircularList<int> circList1;
    circList1.pushBack(12);
    circList1.pushBack(28);
    circList1.pushBack(37);
    std::cout << circList1.popBack() << std::endl;
    circList1.print();

    std::cout << std::endl;

    CircularList<int> circList2;
    circList2.pushBack(2);
    circList2.pushBack(1);
    circList2.pushBack(3);
    std::cout << circList2.popBack() << std::endl;
    circList2.print();

    CircularList<int> circList3;
    circList3 = circList1 + circList2;

    circList3.print();
    circList1.print();
    circList2.print();

    std::cout << std::endl;

    std::cout << (circList1 == circList2) << std::endl;
    std::cout << (circList1 == circList3) << std::endl;
    std::cout << (circList2 == circList3) << std::endl;
    std::cout << (circList1 == circList1) << std::endl;

    CircularList<int> circList4;
    circList4.pushBack(2);
    circList4.pushBack(1);

    std::cout << (circList2 == circList4) << std::endl;

    return 0;
}
