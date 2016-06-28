#include <iostream>
#include <fstream>

#include "MapWords.h"

int main()
{
    MapWords mapWords("TextToRead.txt");
    mapWords.printMapWords();

    return 0;
}
