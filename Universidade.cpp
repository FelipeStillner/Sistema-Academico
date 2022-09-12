#include "Universidade.h"
#include "Departamento.h"

Universidade::Universidade()
{
}

Universidade::Universidade(char n[])
{
    strcpy(nome, n);
}

Universidade::~Universidade()
{
}

void Universidade::setNome(char s[])
{
    strcpy(nome, s);
}

char* Universidade::getNome()
{
    return nome;
}

void Universidade::setDepartamento(Departamento* d)
{
    departamentos.push_back(d);
}

Departamento* Universidade::getDepartamento(int i)
{
    std::list<Departamento*>::iterator j;
    j = departamentos.begin();
    for (int k = 0; k < i; k++)
    {
        j++;
    }
    return *j;
}

void Universidade::setId(int n)
{
    id = n;
}

int Universidade::getId()
{
    return id;
}

std::list<Departamento*> Universidade::getDepartamentos()
{
    return departamentos;
}

void Universidade::setUniAlun(UniAlun* a)
{
  this->a.push_back(a);
}

UniAlun* Universidade::getUniAlun(int i)
{
    std::list<UniAlun*>::iterator j;
    j = a.begin();
    for (int k = 0; k < i; k++)
    {
        j++;
    }
    return *j;
}

std::list<UniAlun*> Universidade::getUniAlun()
{
  return a;
}