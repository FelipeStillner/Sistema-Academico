#pragma once

#include <string.h>
#include <list>
#include "UniAlun.h"

class Departamento;

class Universidade
{
private:
    char nome[30];
    std::list<Departamento*> departamentos;
    std::list<UniAlun*> a;
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
    void setUniAlun(UniAlun* c);
    UniAlun* getUniAlun(int i);
    std::list<UniAlun*> getUniAlun();
};
