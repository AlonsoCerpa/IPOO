#include <iostream>

void printNum(int number){ std::cout << number; };

int main(){
    int number = 35;
    printNum(number);
    return 0;
}

/*
La anterior solucion es preferible ya que permite pasar
como argumento cualquier entero para que sea impreso,
en cambio la solucion siguiente solo va a imprimir
el numero 35.

int number = 35;

void printNum(){ std::cout << number; };

int main(){
    printNum();
    return 0;
}
*/


