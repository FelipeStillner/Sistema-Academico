#pragma once

#include "Pessoa.h"
#include "Aluno.h"
#include "Universidade.h"
#include "Professor.h"
#include "Departamento.h"

class Principal 
{
private:
    std::list<Aluno> alunos;
    std::list<Departamento> departamentos;
    std::list<Universidade> universidades;
    std::list<Disciplina> disciplinas;
    std::list<Professor> professores;
public: 
    Principal();
    ~Principal();
    void Executar();
    void Menu();
};
