#include "Professor.h"

Professor::Professor() : Pessoa()
{
  univ = NULL;
  dep = NULL;
}

Professor::Professor(int d, int m, int a, char s[]) : Pessoa(d, m, a, s)
{
  univ = NULL;
  dep = NULL;
}

Professor::~Professor()
{
}

void Professor::setUniv(Universidade* u)
{
    univ = u;
}

Universidade* Professor::getUniv()
{
    return univ;
}

void Professor::setDep(Departamento* d)
{
    dep = d;
}

Departamento* Professor::getDep()
{
    return dep;
}

void Professor::setSalario(float n)
{
  salario = n;
}

float Professor::getSalario()
{
  return salario;
}

void Professor::setBolsa(float n)
{
  bolsa = n;
}

float Professor::getBolsa()
{
  return bolsa;
}

float Professor::informaProventos()
{
  return bolsa + salario;
}

