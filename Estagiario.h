#pragma once
#include "Aluno.h"

class Estagiario : public Aluno
{
private:
  float bolsa;
public:
  Estagiario();
  Estagiario(int d, int m, int a, char s[]);
  ~Estagiario();
  void setBolsa(int n);
  float getBolsa();
};
