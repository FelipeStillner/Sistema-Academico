#pragma once

#include "Disciplina.h"

class Aluno;

class DiscAlun
{
private:
  Disciplina* d;
  Aluno* a;
  float nota1;
  float nota2;
  float notaFinal;
public:
  DiscAlun(Disciplina* d, Aluno* a);
  DiscAlun();
  ~DiscAlun();
  void setNota1(float n);
  void setNota2(float n);
  float getNota1();
  float getNota2();
  float calcNotaFinal();
  Disciplina* getDisciplina();
  Aluno* getAluno();
};
