#pragma once

#include "Aluno.h"

class Cursar
{
private:
  Disciplina* d;
  Aluno* a;
  float nota1;
  float nota2;
  float notaFinal;
public:
  Cursar(Disciplina* d, Aluno* a);
  Cursar();
  ~Cursar();
  void setNota1(float n);
  void setNota2(float n);
  float getNota1();
  float getNota2();
  float calcNotaFinal();
  Disciplina* getDisciplina();
  Aluno* getAluno();
};
