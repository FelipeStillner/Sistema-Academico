#include "Aluno.h"

Aluno::Aluno(): Pessoa()
{
  univ = NULL;
  dep = NULL;
}

Aluno::Aluno(int d, int m, int a, char s[]): Pessoa(d, m, a, s)
{
  univ = NULL;
  dep = NULL;
}

Aluno::~Aluno()
{
  std::list<Cursar*>::iterator j;
  j = c.begin();
  for (int k = 0; k < c.size(); k++)
  {
    delete (*j);
    j++;
  }
}

void Aluno::setRA(int n)
{
  RA = n;
}

int Aluno::getRA()
{
  return RA;
}

void Aluno::setDep(Departamento* d)
{
  dep = d;
}

Departamento* Aluno::getDep()
{
  return dep;
}

void Aluno::setUniv(Universidade* u)
{
  univ = u;
}

Universidade* Aluno::getUniv()
{
  return univ;
}

void Aluno::createCursar(Disciplina* d)
{
  Cursar* c = new Cursar(d, this);
  d->setCursar(c);
  this->c.push_back(c);
}

void Aluno::deleteCursar(int i)
{
  std::list<Cursar*>::iterator j;
  j = c.begin();
  for (int k = 0; k < i; k++)
  {
    j++;
  }
  (*j)->~Cursar();
  delete *j;
}

Cursar* Aluno::getCursar(int i)
{
  std::list<Cursar*>::iterator j;
  j = c.begin();
  for (int k = 0; k < i; k++)
  {
    j++;
  }
  return *j;
}

std::list<Cursar*> Aluno::getCursar()
{
  return c;
}
