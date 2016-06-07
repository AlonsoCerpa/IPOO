#include "ejer2.h"
#include <iostream>

using std::cout;
using std::endl;

Roedor::Roedor(const string &_especie)
    : especie{_especie} {}

void Roedor::obtEspecie() const
{
    cout << especie << endl;
}

void Roedor::ingPesoGr(const int &_peso)
{
    pesoGr = _peso;
}

void Roedor::obtPesoGr() const
{
    cout << pesoGr << endl;
}

void Roedor::ingAlimento(const string &_alim)
{
    alimento = _alim;
}

void Roedor::obtAlimento() const
{
    cout << alimento << endl;
}

void Roedor::obtEnf() const
{
    cout << "No son transmisores de enfermedades." << endl;
}

void Roedor::obtMov() const
{
    cout << "Se mueve caminando con sus patas" << endl;
}

////////////////////////////////////////////////////////////////////////

Raton::Raton(const string &_especie)
    : Roedor(_especie) {}

void Raton::obtEnf() const
{
    cout << "Transmite enfermedades como la salmonellosis, fiebres hemorragicas, rabia, entre otras." << endl;
}

////////////////////////////////////////////////////////////////////////

Hamster::Hamster(const string &_especie)
    : Roedor(_especie) {}

////////////////////////////////////////////////////////////////////////

Jerbo::Jerbo(const string &_especie)
    : Roedor(_especie) {}


void Jerbo::obtMov() const
{
    cout << "Se mueven saltando con sus 2 patas traseras." << endl;
}

////////////////////////////////////////////////////////////////////////

ArregloRoedor::ArregloRoedor(Roedor *_arrRoed[], const unsigned &_numRoedores)
    : numRoedores{_numRoedores}
{
    arrRoed = new Roedor*[_numRoedores];
    for (unsigned i = 0; i < numRoedores; i++){
        arrRoed[i] = _arrRoed[i];
    }
}

void ArregloRoedor::ingresarRoedor(Roedor *roedor)
{
    Roedor **aux = arrRoed;
    ++numRoedores;
    arrRoed = new Roedor*[numRoedores];
    for (unsigned i = 0; i < numRoedores - 1; i++){
        arrRoed[i] = aux[i];
    }
    arrRoed[numRoedores - 1] = roedor;
    delete[] aux;
}

Roedor *ArregloRoedor::obtRoedor(const unsigned &pos) const
{
    return arrRoed[pos];
}

unsigned ArregloRoedor::obtNumRoed() const
{
    return numRoedores;
}

/*
ArregloRoedor::ArregloRoedor(Roedor *_arrRoed[], const unsigned &_numRoedores)  //Ex. 3
    : arrRoed(_numRoedores)
{
    for (unsigned i = 0; i < _numRoedores; i++)
    {
        arrRoed[i] = _arrRoed[i];
    }
}

ArregloRoedor::ArregloRoedor(vector<Roedor *> _arrRoed)
{
    arrRoed = _arrRoed;
}

void ArregloRoedor::ingresarRoedor(Roedor *roedor)
{
    arrRoed.push_back(roedor);
}
*/

