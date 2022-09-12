#pragma once

#include "Pessoa.h"
#include "Universidade.h"
#include "Departamento.h"

class Professor : public Pessoa
{
private:
  Universidade *univ;
  Departamento *dep;
public:
  Professor();
  Professor(int d, int m, int a, char s[]);
  ~Professor();
  void setUniv(Universidade* u);
  Universidade* getUniv();
  void setDep(Departamento* d);
  Departamento* getDep();
};
