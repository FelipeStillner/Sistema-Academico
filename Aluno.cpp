#include "Aluno.h"

Aluno::Aluno(): Pessoa()
{
  u = NULL;
  dep = NULL;
}

Aluno::Aluno(int d, int m, int a, char s[]): Pessoa(d, m, a, s)
{
  u = NULL;
  dep = NULL;
}

Aluno::~Aluno()
{
  std::list<DiscAlun*>::iterator j;
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

void Aluno::createDiscAlun(Disciplina* d)
{
  DiscAlun* c = new DiscAlun(d, this);
  d->setDiscAlun(c);
  this->c.push_back(c);
}

void Aluno::deleteDiscAlun(int i)
{
  std::list<DiscAlun*>::iterator j;
  j = c.begin();
  for (int k = 0; k < i; k++)
  {
    j++;
  }
  (*j)->~DiscAlun();
  delete *j;
}

DiscAlun* Aluno::getDiscAlun(int i)
{
  std::list<DiscAlun*>::iterator j;
  j = c.begin();
  for (int k = 0; k < i; k++)
  {
    j++;
  }
  return *j;
}

std::list<DiscAlun*> Aluno::getDiscAlun()
{
  return c;
}


void Aluno::createUniAlun(Universidade* uni)
{
  UniAlun* u = new UniAlun(uni, this);
  uni->setUniAlun(u);
  this->u = u;
}

void Aluno::deleteUniAlun()
{
  u->~UniAlun();
}

UniAlun* Aluno::getUniAlun()
{
  return u;
}

