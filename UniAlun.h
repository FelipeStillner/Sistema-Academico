#pragma once

class Aluno;
class Universidade;

class UniAlun
{
private:
  Universidade* u;
  Aluno* a;
public:
  UniAlun(Universidade* u, Aluno* dep);
  UniAlun();
  ~UniAlun();
  Universidade* getUniversidade();
  Aluno* getAluno();
};