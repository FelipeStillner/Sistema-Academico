#pragma once

#include <string.h>
#include <list>

class Departamento;
class Aluno;
class Cursar;

class Disciplina
{
private:
  int id;
  char nome[30];
  Departamento* dep;
  std::list<Cursar*> c;
public:
  Disciplina();
  Disciplina(char s[]);
  ~Disciplina();
  void setId(int i);
  int getId();
  void setNome(char s[]);
  char* getNome();
  void setDepartamento(Departamento* d);
  Departamento* getDepartamento();
  void setCursar(Cursar* c);
  Cursar* getCursar(int i);
  std::list<Cursar*> getCursar();
};
