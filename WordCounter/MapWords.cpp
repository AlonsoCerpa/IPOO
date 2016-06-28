#include "MapWords.h"

MapWords::MapWords(const std::string &nameTextFile)
{
    myText.open(nameTextFile);

    auto itMap = mapWords.begin();

    while (myText >> word)
    {
        if (mapWords.empty())
            mapWords[word] = 1;
        else
        {
            for (itMap = mapWords.begin(); itMap != mapWords.end() &&
                 word.compare(itMap->first) != 0; ++itMap)
                ;
            if (itMap == mapWords.end())
                mapWords[word] = 1;
            else
                ++(itMap->second);
        }
    }
}

void MapWords::printMapWords() const
{
    for (auto itMap = mapWords.begin(); itMap != mapWords.end(); ++itMap)
    {
        std::cout << itMap->first << ": " << itMap->second << std::endl;
    }
}
