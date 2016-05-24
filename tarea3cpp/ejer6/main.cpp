#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

const string VOWELS{"aeiou"};

const string pigLatinfy(const string &word){
    if (word.size() == 0){
        return word;
    }
    if(word.find("q") == 0){
        return word.substr(2, word.size() - 1) + "-quay";
    }
    else if(VOWELS.find(word[0]) != string::npos){
        return word + "way";
    }
    else{
        return word.substr(1, word.size() - 1) + "-" + word[0] + "ay";
    }
}

int main()
{
    const string pL1 = pigLatinfy("queen");
    cout << pL1 << endl;

    const string pL2 = pigLatinfy("practice");
    cout << pL2 << endl;

    const string pL3 = pigLatinfy("emotion");
    cout << pL3 << endl;

    return 0;
}
