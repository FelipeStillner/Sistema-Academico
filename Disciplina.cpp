#include "Disciplina.h"
#include "DiscAlun.h"
#include "DepDisc.h"
#include "Departamento.h"

Disciplina::Disciplina()
{
}

Disciplina::Disciplina(char s[])
{
  stpcpy(nome, s);
}

Disciplina::~Disciplina()
{
}

void Disciplina::setId(int i)
{
  id = i;
}

int Disciplina::getId()
{
  return id;
}

void Disciplina::setNome(char s[])
{ 
  stpcpy(nome, s);
} 

char* Disciplina::getNome()
{
  return nome;
}

void Disciplina::setDiscAlun(DiscAlun* c)
{
  this->c.push_back(c);
}

DiscAlun* Disciplina::getDiscAlun(int i)
{
  std::list<DiscAlun*>::iterator j;
    j = c.begin();
    for (int k = 0; k < i; k++)
    {
        j++;
    }
    return *j;
}

std::list<DiscAlun*> Disciplina::getDiscAlun()
{
  return c;
}

void Disciplina::createDepDisc(Departamento* dep)
{
  DepDisc* d = new DepDisc(this, dep);
  dep->setDepDisc(d);
  this->d.push_back(d);
}

void Disciplina::deleteDepDisc(int i)
{
  std::list<DepDisc*>::iterator j;
  j = d.begin();
  for (int k = 0; k < i; k++)
  {
    j++;
  }
  (*j)->~DepDisc();
  delete *j;
}

DepDisc* Disciplina::getDepDisc(int i)
{
  std::list<DepDisc*>::iterator j;
  j = d.begin();
  for (int k = 0; k < i; k++)
  {
    j++;
  }
  return *j;
}

std::list<DepDisc*> Disciplina::getDepDisc()
{
  return d;
}
