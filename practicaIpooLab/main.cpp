#include <iostream>
#include "Ejer1.h"
#include "ejer2.h"

using namespace std;

int main()
{
    int fecha[3] = {4, 5, 2012};                                //Ex. 1

    Funcionario a{"alvaro", 120, fecha};
    Funcionario b{"fred", 350, fecha};
    Funcionario c{"rodrigo", 810, fecha};
    Funcionario d{"maria", 1200, fecha};
    Funcionario e{"carl", 670, fecha};
    Funcionario f{"mateo", 990, fecha};

    Empresa emp{"Google", 4235631};
    emp.estabNewFunc(&a, "Programadores");
    emp.estabNewFunc(&b, "Programadores");
    emp.estabNewFunc(&c, "Programadores");

    emp.estabNewFunc(&d, "Ventas");
    emp.estabNewFunc(&e, "Ventas");

    emp.estabNewFunc(&f, "Marketing");

    emp.aumentoDiezPC("Programadores");

    cout << a.getSalario() << endl;

    int *fgt = a.getFechIng();

    cout << fgt[0] << " " << fgt[1] << " " << fgt[2] << endl;

///////////////////////////////////////////////////////////////// Ex. 2

    Raton raton{"Mus musculus"};
    raton.ingPesoGr(40);
    raton.ingAlimento("Queso, frutas, granos, etc.");

    Hamster hamster{"Cricetinae"};
    hamster.ingPesoGr(40);
    hamster.ingAlimento("Frutos, verduras, cereales y semillas.");

    Jerbo jerbo{"Dipodinae"};
    jerbo.ingPesoGr(120);
    jerbo.ingAlimento("Semillas, insectos y vegetales.");

    Roedor *aR[] = {&raton, &hamster, &jerbo};
    ArregloRoedor roedores{aR, 3};

    roedores.obtRoedor(0) -> obtEnf();
    roedores.obtRoedor(1) -> obtMov();
    roedores.obtRoedor(2) -> obtMov();

    return 0;
}
