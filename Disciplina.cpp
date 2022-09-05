#include "Disciplina.h"
#include "Departamento.h"
#include "Aluno.h"
#include "Cursar.h"

Disciplina::Disciplina()
{
  dep = NULL;
}

Disciplina::Disciplina(char s[])
{
  stpcpy(nome, s);
  dep = NULL;
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

void Disciplina::setDepartamento(Departamento* d)
{
  dep = d;
}

Departamento* Disciplina::getDepartamento()
{
  return dep;
}

void Disciplina::setCursar(Cursar* c)
{
  this->c.push_back(c);
}

Cursar* Disciplina::getCursar(int i)
{
  std::list<Cursar*>::iterator j;
    j = c.begin();
    for (int k = 0; k < i; k++)
    {
        j++;
    }
    return *j;
}

std::list<Cursar*> Disciplina::getCursar()
{
  return c;
}

