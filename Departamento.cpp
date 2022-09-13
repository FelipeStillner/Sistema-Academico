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

void Departamento::setDisciplina(Disciplina* d)
{
  this->d.push_back(d);
}

Disciplina* Departamento::getDisciplina(int i)
{
  std::list<Disciplina*>::iterator j;
    j = d.begin();
    for (int k = 0; k < i; k++)
    {
        j++;
    }
    return *j;
}

std::list<Disciplina*> Departamento::getDisciplina()
{
  return d;
}