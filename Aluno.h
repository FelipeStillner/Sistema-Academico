#pragma once

#include "Pessoa.h"
#include "Universidade.h"
#include "Cursar.h"
#include <list>

class Aluno : public Pessoa
{
private:
  int RA;
  Departamento* dep;
  Universidade* univ;
  std::list<Cursar*> c;
public:
  Aluno();
  Aluno(int d, int m, int a, char s[]);
  ~Aluno();
  void setRA(int n);
  int getRA();
  void setDep(Departamento* d);
  Departamento* getDep();
  void setUniv(Universidade* u);
  Universidade* getUniv();
  void createCursar(Disciplina* d);
  void deleteCursar(int i);
  Cursar* getCursar(int i);
  std::list<Cursar*> getCursar();
};
