#include "DepDisc.h"
#include "Departamento.h"

DepDisc::DepDisc(Disciplina* disc, Departamento* dep)
{
  this->dep = dep;
  this->disc = disc;
}

DepDisc::DepDisc()
{
  dep = NULL;
  disc = NULL;
}

DepDisc::~DepDisc()
{
}

Disciplina* DepDisc::getDisciplina()
{
  return disc;
}

Departamento* DepDisc::getDepartamento()
{
  return dep;
}
