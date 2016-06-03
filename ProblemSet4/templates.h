#ifndef TEMPLATES_H_INCLUDED
#define TEMPLATES_H_INCLUDED

#include <vector>

using std::vector;
using std::cout;
using std::endl;


template<typename T>                        //Ex. 2.1
T min(const T &val1, const T &val2)
{
    return (val1 < val2) ? val1 : val2;
}

template <>
char min<char>(const char &val1, const char &val2)
{
    cout << "Imprime segun la tabla ASCII" << endl;
    return (val1 < val2) ? val1 : val2;
}


template<typename T> class Stack;

template<typename T>
Stack<T> operator+(const Stack<T> &s1, const Stack<T> &s2)
{
    Stack<T> res = s1;

    for (unsigned i = 0; i < s2.Stack.size(); i++){
        res.Stack.push_back(s2.Stack[i]);
    }
    return res;
}

template<typename T>
class Stack
{
    friend Stack<T> operator+<>(const Stack<T> &, const Stack<T> &);
public:
    bool empty() const;
    void push(const T &);
    T &top();
    void pop();
private:
    vector <T> Stack;
};

template<typename T>
bool Stack<T>::empty() const
{
    return Stack.empty();
}

template<typename T>
void Stack<T>::push(const T &elem)
{
    Stack.push_back(elem);
}

template<typename T>
T &Stack<T>::top()
{
    return Stack.back();
}

template<typename T>
void Stack<T>::pop()
{
    if (Stack.empty())
        return;
    else
        Stack.pop_back();
}

#endif // TEMPLATES_H_INCLUDED
