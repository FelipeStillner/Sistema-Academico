#pragma once

#include "Disciplina.h"

class Departamento;

class DepDisc
{
private:
  Disciplina* disc;
  Departamento* dep;
public:
  DepDisc(Disciplina* disc, Departamento* dep);
  DepDisc();
  ~DepDisc();
  Disciplina* getDisciplina();
  Departamento* getDepartamento();
};
