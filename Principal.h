#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "Aluno.h"
#include "DiscAlun.h"
#include "Departamento.h"
#include "Disciplina.h"
#include "Pessoa.h"
#include "Professor.h"
#include "Universidade.h"
#include "Str.h"
#include "Estagiario.h"

class Principal 
{
private:
    std::list<Aluno*> alunos;
    std::list<Departamento*> departamentos;
    std::list<Universidade*> universidades;
    std::list<Disciplina*> disciplinas;
    std::list<Professor*> professores;
    std::list<Pessoa*> pessoas;
    int contAlunos;
    int contDepartamentos;
    int contUniversidades;
    int contDisciplinas;
public: 
    Principal();
    ~Principal();
    void Executar();
    void Menu();
    void deleteLists();
    void menuCriar();
    void menuSair();
    void menuCadastrar();
    void menuSalvar();
    void menuPrint();
    void menuInvalido();
    void SalvaAlunos();
    void RecuperaAlunos();
    void Recuperar();
    void RecuperaUniversidades();
    void SalvaUniversidades();
    void RecuperaDepartamentos();
    void SalvaDepartamentos();
    void RecuperaDisciplinas();
    void SalvaDisciplinas();
    void SalvaDiscAlun();
    void RecuperaDiscAlun();
};
