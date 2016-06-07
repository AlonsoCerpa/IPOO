#ifndef EJER2_H_INCLUDED
#define EJER2_H_INCLUDED

#include <string>
#include <vector>

using std::string;
using std::vector;

class Roedor
{
public:
    Roedor(const string &_especie);
    void obtEspecie() const;
    void ingPesoGr(const int &_peso);
    void obtPesoGr() const;
    void ingAlimento(const string &_alim);
    void obtAlimento() const;
    virtual void obtEnf() const;
    virtual void obtMov() const;
protected:
    string especie;
    int pesoGr;
    string alimento;
    string enfermedades;
    string movimiento;
};

////////////////////////////////////////////////////////////////////

class Raton : public Roedor
{
public:
    Raton(const string &_especie);
    virtual void obtEnf() const;
};

////////////////////////////////////////////////////////////////////

class Hamster : public Roedor
{
public:
    Hamster(const string &_especie);
};

////////////////////////////////////////////////////////////////////

class Jerbo : public Roedor
{
public:
    Jerbo(const string &_especie);
    virtual void obtMov() const;
};

////////////////////////////////////////////////////////////////////

class ArregloRoedor
{
private:
    Roedor **arrRoed;
    unsigned numRoedores;
public:
    ArregloRoedor(Roedor *_arrRoed[], const unsigned &_numRoedores);
    void ingresarRoedor(Roedor *roedor);
    Roedor *obtRoedor(const unsigned &pos) const;
    unsigned obtNumRoed() const;
};

/*                                             //Ex. 3
class ArregloRoedor
{
private:
    vector<Roedor *> arrRoed;
    unsigned numRoedores;
public:
    ArregloRoedor(Roedor *_arrRoed[], const unsigned &_numRoedores);
    ArregloRoedor(vector<Roedor *> _arrRoed);
    void ingresarRoedor(Roedor *roedor);
    Roedor *obtRoedor(const unsigned &pos) const;
    unsigned obtNumRoed() const;
};
*/
#endif // EJER2_H_INCLUDED
