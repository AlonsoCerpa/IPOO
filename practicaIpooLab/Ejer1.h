#ifndef EJER1_H_INCLUDED
#define EJER1_H_INCLUDED

#include <map>
#include <vector>

using std::map;
using std::vector;
using std::string;

class Funcionario
{
public:
    Funcionario(const string &nom, const int &sal, const int fechIng[]);
    ~Funcionario();
    void estabNomFun(const string &nomFun);
    void estabSalario(const int &sal);
    void estabFechaIngreso(const int fechIng[]);
    string getNombFun() const;
    int getSalario() const;
    int *getFechIng();
private:
    string nombreFuncionario;
    int salario;
    int fechaIngreso[3];
    int *fechaCopia{nullptr};
};

class Empresa
{
public:
    Empresa(const string &nom, const int &_ruc);
    void estabNomEmp(const string &nomEmp);
    void estabRuc(const int &_ruc);
    void estabDepart(const string &dep);
    void estabNewFunc(Funcionario *const func, const string &dep);
    string getNomEmp() const;
    int getRuc() const;
    unsigned getNumFuncDep(const string &dep);
    void aumentoDiezPC(const string &dep);
private:
    string nombreEmpresa;
    int ruc;
    map <string, vector<Funcionario *> > departFunc;
};

#endif // EJER1_H_INCLUDED
