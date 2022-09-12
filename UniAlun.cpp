#include "UniAlun.h"
#include "Universidade.h"
#include "Aluno.h"

UniAlun::UniAlun(Universidade* u, Aluno* a)
{
  this->u = u;
  this->a = a;
}

UniAlun::UniAlun()
{
  u = NULL;
  a = NULL;
}

UniAlun::~UniAlun()
{
}

Universidade* UniAlun::getUniversidade()
{
  return u;
}

Aluno* UniAlun::getAluno()
{
  return a;
}
