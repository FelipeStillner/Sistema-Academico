#pragma once

#include <list>
#include "Universidade.h"
#include "Disciplina.h"

class Departamento
{
private:
  int id;
  char nome[30];
  Universidade* univ;
  std::list<Disciplina*> d;
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
  void setDisciplina(Disciplina* d);
  Disciplina* getDisciplina(int i);
  std::list<Disciplina*> getDisciplina();
};
