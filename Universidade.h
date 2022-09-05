#pragma once

#include "Departamento.h"
#include <string.h>
#include <list>

class Universidade
{
private:
    char nome[30];
    std::list<Departamento*> departamentos;
    int id;
public:
    Universidade();
    Universidade(char n[]);
    ~Universidade();
    void setNome(char s[]);
    char* getNome();
    void setDepartamento(Departamento* d);
    Departamento* getDepartamento(int i);
    std::list<Departamento*> getDepartamentos();
    void setId(int n);
    int getId();
};
