#include <iostream>

using namespace std;

int lenStr(char *str)
{
    int len;

    for (len = 0; *(str + len) != '\0'; len++)
        ;
    return len;
}

int main()
{
    char *str = "abcd";

    int len = lenStr(str);
    cout << len << endl;
    return 0;
}
