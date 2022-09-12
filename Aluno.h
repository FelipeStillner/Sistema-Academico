#pragma once

#include <list>
#include "Pessoa.h"
#include "Departamento.h"
#include "Universidade.h"
#include "DiscAlun.h"
#include "Disciplina.h"
#include "UniAlun.h"

class Aluno : public Pessoa
{
private:
  int RA;
  Departamento* dep;
  UniAlun* u;
  std::list<DiscAlun*> c;
public:
  Aluno();
  Aluno(int d, int m, int a, char s[]);
  ~Aluno();
  void setRA(int n);
  int getRA();
  void setDep(Departamento* d);
  Departamento* getDep();
  void createDiscAlun(Disciplina* d);
  void deleteDiscAlun(int i);
  DiscAlun* getDiscAlun(int i);
  std::list<DiscAlun*> getDiscAlun();
  void createUniAlun(Universidade* u);
  void deleteUniAlun();
  UniAlun* getUniAlun();
};
