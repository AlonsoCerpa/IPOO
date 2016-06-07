#include "Ejer1.h"

Funcionario::Funcionario(const string &nom, const int &sal, const int fechIng[])
    : nombreFuncionario{nom}, salario{sal}
    {
        for(int i = 0; i < 3; i++){
            fechaIngreso[i] = fechIng[i];
        }
    }

Funcionario::~Funcionario()
{
    if(fechaCopia)
        delete[] fechaCopia;
}

void Funcionario::estabNomFun(const string &nomFun)
{
    nombreFuncionario = nomFun;
}

void Funcionario::estabSalario(const int &sal)
{
    salario = sal;
}

void Funcionario::estabFechaIngreso(const int fechIng[])
{
    for(int i = 0; i < 3; i++){
        fechaIngreso[i] = fechIng[i];
    }
}

string Funcionario::getNombFun() const
{
    return nombreFuncionario;
}

int Funcionario::getSalario() const
{
    return salario;
}

int *Funcionario::getFechIng()
{
    fechaCopia = new int[3];
    for(int i = 0; i < 3; i++){
        fechaCopia[i] = fechaIngreso[i];
    }
    return fechaCopia;
}

///////////////////////////////////////////////////////////////////////

Empresa::Empresa(const string &nom, const int &_ruc)
    : nombreEmpresa{nom}, ruc{_ruc} {}

void Empresa::estabNomEmp(const string &nomEmp)
{
    nombreEmpresa = nomEmp;
}

void Empresa::estabRuc(const int &_ruc)
{
    ruc = _ruc;
}

void Empresa::estabDepart(const string &dep)
{
    departFunc[dep];
}

void Empresa::estabNewFunc(Funcionario *const func, const string &dep)
{
    departFunc[dep].push_back(func);
}

string Empresa::getNomEmp() const
{
    return nombreEmpresa;
}

int Empresa::getRuc() const
{
    return ruc;
}

unsigned Empresa::getNumFuncDep(const string &dep)
{
    return departFunc[dep].size();
}

void Empresa::aumentoDiezPC(const string &dep)
{
    for (unsigned i = 0; i < departFunc[dep].size(); i++){
        int salAnt = departFunc[dep][i] -> getSalario();
        int newSal = salAnt + (salAnt / 10);
        departFunc[dep][i] -> estabSalario(newSal);
    }
}











