#pragma once

#include <string.h>
#include <list>

class DiscAlun;
class Departamento;

class Disciplina
{
private:
  int id;
  char nome[30];
  std::list<DiscAlun*> c;
  Departamento* d;
public:
  Disciplina();
  Disciplina(char s[]);
  ~Disciplina();
  void setId(int i);
  int getId();
  void setNome(char s[]);
  char* getNome();
  void setDiscAlun(DiscAlun* c);
  DiscAlun* getDiscAlun(int i);
  std::list<DiscAlun*> getDiscAlun();
  void setDepartamento(Departamento* d);
  Departamento* getDepartamento();
};
