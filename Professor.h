#pragma once

#include "Pessoa.h"
#include "Universidade.h"
#include "Departamento.h"

class Professor : public Pessoa
{
private:
  Universidade *univ;
  Departamento *dep;
  float salario;
  float bolsa;
public:
  Professor();
  Professor(int d, int m, int a, char s[]);
  ~Professor();
  void setUniv(Universidade* u);
  Universidade* getUniv();
  void setDep(Departamento* d);
  Departamento* getDep();
  void setSalario(float n);
  float getSalario();
  void setBolsa(float n);
  float getBolsa();
  float informaProventos();
};
