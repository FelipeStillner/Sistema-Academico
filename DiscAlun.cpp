#include "DiscAlun.h"
#include "Aluno.h"

DiscAlun::DiscAlun(Disciplina* d, Aluno* a)
{
  this->d = d;
  this->a = a;
  nota1 = 0;
  nota2 = 0;
  notaFinal = 0;
}

DiscAlun::DiscAlun()
{
  d = NULL;
  a = NULL;
  nota1 = 0;
  nota2 = 0;
  notaFinal = 0;
}

DiscAlun::~DiscAlun()
{
}

void DiscAlun::setNota1(float n)
{
  nota1 = n;
}

void DiscAlun::setNota2(float n)
{
  nota2 = n;
}

float DiscAlun::getNota1()
{
  return nota1;
}

float DiscAlun::getNota2()
{
  return nota2;
}

float DiscAlun::getNotaFinal()
{
  notaFinal = (nota1+nota2)/2;
  return notaFinal;
}

Disciplina* DiscAlun::getDisciplina()
{
  return d;
}

Aluno* DiscAlun::getAluno()
{
  return a;
}
