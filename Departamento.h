#pragma once

#include <list>
#include "Universidade.h"
#include "Disciplina.h"
#include "DepDisc.h"

class Departamento
{
private:
  int id;
  char nome[30];
  Universidade* univ;
  std::list<DepDisc*> d;
public:
  Departamento();
  Departamento(char* n);
  ~Departamento();
  void setNome(char* n);
  char* getNome();
  void setId(int n);
  int getId();
  void setUniv(Universidade* u);
  Universidade* getUniv();
  void setDepDisc(DepDisc* d);
  DepDisc* getDepDisc(int i);
  std::list<DepDisc*> getDepDisc();
};
