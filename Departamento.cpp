#include "Departamento.h"

Departamento::Departamento()
{
  strcpy(nome, "\0");
  univ = NULL;
  id = -1;
}

Departamento::Departamento(char n[])
{
  strcpy(nome, n);
  univ = NULL;
  id = -1;
}

Departamento::~Departamento()
{
}

void Departamento::setNome(char* n)
{
  strcpy(nome, n);
}

char* Departamento::getNome()
{
  return nome;
}

void Departamento::setId(int n)
{
  id = n;
}

int Departamento::getId()
{
  return id;
}

void Departamento::setUniv(Universidade* u)
{
  univ = u;
}

Universidade* Departamento::getUniv()
{
  return univ;
}

void Departamento::setDepDisc(DepDisc* d)
{
  this->d.push_back(d);
}

DepDisc* Departamento::getDepDisc(int i)
{
  std::list<DepDisc*>::iterator j;
    j = d.begin();
    for (int k = 0; k < i; k++)
    {
        j++;
    }
    return *j;
}

std::list<DepDisc*> Departamento::getDepDisc()
{
  return d;
}