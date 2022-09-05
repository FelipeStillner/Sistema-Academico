#include "Cursar.h"

Cursar::Cursar(Disciplina* d, Aluno* a)
{
  this->d = d;
  this->a = a;
  nota1 = 0;
  nota2 = 0;
  notaFinal = 0;
}

Cursar::Cursar()
{
  d = NULL;
  a = NULL;
  nota1 = 0;
  nota2 = 0;
  notaFinal = 0;
}

Cursar::~Cursar()
{
}

void Cursar::setNota1(float n)
{
  nota1 = n;
}

void Cursar::setNota2(float n)
{
  nota2 = n;
}

float Cursar::getNota1()
{
  return nota1;
}

float Cursar::getNota2()
{
  return nota2;
}

float Cursar::calcNotaFinal()
{
  notaFinal = (nota1+nota2)/2;
  return notaFinal;
}

Disciplina* Cursar::getDisciplina()
{
  return d;
}

Aluno* Cursar::getAluno()
{
  return a;
}
