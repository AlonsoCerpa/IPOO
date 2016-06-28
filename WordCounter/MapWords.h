#ifndef MAPWORDS_H_INCLUDED
#define MAPWORDS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <map>

class MapWords
{
public:
    MapWords(const std::string &nameTextFile);
    void printMapWords() const;

private:
    std::map<std::string, int> mapWords;
    std::ifstream myText;
    std::string word;
};

#endif // MAPWORDS_H_INCLUDED
