#include "Estagiario.h"

Estagiario::Estagiario() : Aluno()
{
  bolsa = 0;
}

Estagiario::Estagiario(int d, int m, int a, char s[]) : Aluno(d, m, a, s)
{
  bolsa = 0;
}

Estagiario::~Estagiario()
{
}

void Estagiario::setBolsa(int n)
{
  bolsa = n;
}

float Estagiario::getBolsa()
{
  return bolsa;
}