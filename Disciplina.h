#pragma once

#include <string.h>
#include <list>

class DiscAlun;
class DepDisc;
class Departamento;

class Disciplina
{
private:
  int id;
  char nome[30];
  std::list<DiscAlun*> c;
  std::list<DepDisc*> d;
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
  void createDepDisc(Departamento* d);
  void deleteDepDisc(int i);
  DepDisc* getDepDisc(int i);
  std::list<DepDisc*> getDepDisc();
};
